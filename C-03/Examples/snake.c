/* Программа представляет игру "Змейка"
 * Начальный текст программы получена на курсах по программирования на С (Специалист). 
 * Первоначальный автор неизвестен.
 * Версия 0.2
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <time.h>
#include <stdbool.h>
#include <windows.h>

// параметры ограничивающей рамки
#define START_POINT_FRAME_X 0				// начальная точка рамки (X)
#define START_POINT_FRAME_Y 1				// начальная точка рамки (Y)
#define FRAME_X 60							// размер рамки по x
#define FRAME_Y 20							// размер рамки по y
#define NODE_FRAME '+'						// символ в углах рамки '+'
#define HORIZONT_LINE_FRAME '-'				// символ горизонтальной линии рамки '-'
#define VERTICAL_LINE_FRAME '|'				// символ вертикальной линии рамки '|'
#define EMPTY_SYMBOL_FRAME ' '				// пустой символ рамки ' '
#define NEW_LINE_FRAME '\n'					// символ начало отрисовки новой линии
// параметры змеи
#define HEAD_SNAKE '@'						// символ головы змеи
#define BODY_SNAKE 'o'						// символ тела змеи 'o'
#define SNAKE_SIZE 5						// начальная длинна змеи
#define SNAKE_MAX_SIZE 10					// максимальный рамер змеи
#define EMPTY_SPACE ' '						// пустая позиция с которой ушла змея (пробел)
// иные параметры
#define START_POINT_X FRAME_X / 2			// x начала движения змеи
#define START_POINT_Y FRAME_Y / 2			// y начала двизения змеи
#define SLEEP 100							// шаг паузы
#define FOOD '*'							// символ еды
// направления
#define UP 0x48
#define DOWN 0x50
#define LEFT 0x4b
#define RIGHT 0x4d

struct balloon_snake						// структура описывает бусинку змеи
{
	int x;
	int y;
};

typedef struct balloon_snake balloonSnake;	// новое имя структуры
typedef struct balloon_snake foodPosition;	// новое имя структуры

balloonSnake startPointFrame = { START_POINT_FRAME_X,// точка старта отрисовку рамки
START_POINT_FRAME_Y };
balloonSnake pointForEndMessage = { 0,			// точка вывода завершающей надписи по окончании программы
START_POINT_FRAME_Y + FRAME_Y + 1 };

void drawFrame(int, int);					// функция отрисовки ограничивающей рамки
//void gotoxy(int, int);						// функция перемещения курсора по заданным координатам
void gotoxy(balloonSnake);						// функция перемещения курсора по заданным координатам
int startDirection(void);					// функция генерации начального направления
void newSnake(balloonSnake *,int leight, int direction);		// функция начальной генерации тела змеи
balloonSnake stepSnake(int direction, balloonSnake head);		// функция генерации шага змеи
bool snakeCrash(balloonSnake position);							// функция определения столкновения змеи с рамкой
foodPosition foodGenerator();									// генератор еды



int main()
{
	system("color 1E");						// Установка синего фона и желтого текста
	setlocale(LC_CTYPE, "rus");

	drawFrame(FRAME_X, FRAME_Y);			// нарисовать рамку

	int key = RIGHT/*startDirection()*/, // текущее значение управляющей клавиши (стрелки)
		prevKey,
		dx = 1, // начальная инициализация приращений по координатам (змея ползет вправо)
		dy = 0;
	balloonSnake Snake[SNAKE_MAX_SIZE];				// массив описывающий положение змеи в координатах

	int longSnake = SNAKE_SIZE,						// longSnake - текущий размер змеи
		i; 

	newSnake(Snake, SNAKE_SIZE, key);				// функция генерации начального тела змеи
	foodPosition food;

	while (true) // цикл программы
	{
		if (snakeCrash(Snake[0])) {					// столкновение змеи с рамкой
			gotoxy(pointForEndMessage);				// завершающая надпись после рамки
			printf("Авария!!!\n");
			break;
		}

		food = 
		gotoxy(Snake[0]);					// перемещение курсора в первых сектор змеи
		putchar(HEAD_SNAKE);						// отрисовка головы змеи
		for (i = 1; i < longSnake; i++)
		{
			gotoxy(Snake[i]);
			putchar(BODY_SNAKE);
			gotoxy(Snake[i]);
		}
		if (kbhit() != false)
		{
			prevKey = key;
			key = getch();								// перехват нажатия клавиш
			if (key == 27) {							// прекращение цикла при нажатии Esc
				gotoxy(pointForEndMessage);				// завершающая надпись после рамки
				break; 
			}
			if (key == 224) key = getch();				// повторный вызов т.к. первоначально стрелки возвращают E0
			// отладка
			/*gotoxy(pointForEndMessage);
			printf("%d\t%x", key, key);*/
			if (key == RIGHT && prevKey == LEFT) key = LEFT;	// змея не может ползти через себя
			if (key == LEFT && prevKey == RIGHT ) key = RIGHT;
			if (key == DOWN && prevKey == UP) key = UP;
			if (key == UP && prevKey == DOWN) key = DOWN;
			
		}
		gotoxy(Snake[0]);							// перевод курсора в голову змеи
		if (key == LEFT || key == RIGHT) Sleep(SLEEP);// задержка времени
		else Sleep(SLEEP * 1.5);							// скорость между строками медленнее в 1.5 раза								
		
		gotoxy(Snake[longSnake - 1]);				// уход курсора в последний сектор замеи
		putchar(EMPTY_SPACE);						// отрисовка пустоты

		for (i = longSnake - 1; i > 0; i--)
		{
			Snake[i] = Snake[i - 1];
			/*bodySnake[0][i] = bodySnake[0][i - 1];
			bodySnake[1][i] = bodySnake[1][i - 1];*/
		}

		Snake[0] = stepSnake(key, Snake[0]);
		/*bodySnake[0][0] += dx;
		bodySnake[1][0] += dy;*/
		

	}
}

void newSnake(balloonSnake *Snake, int leight, int direction)
{
	Snake[0].x = START_POINT_X;
	Snake[0].y = START_POINT_Y;

	switch (direction) {
	case LEFT:
		for(int i = 1; i < SNAKE_SIZE; ++i)
		{
			Snake[i].x = START_POINT_X + i;
			Snake[i].y = START_POINT_Y;
		} break;
	case RIGHT:
		for (int i = 1; i < SNAKE_SIZE; ++i)
		{
			Snake[i].x = START_POINT_X - i;
			Snake[i].y = START_POINT_Y;
		} break;
	case UP:
		for (int i = 1; i < SNAKE_SIZE; ++i)
		{
			Snake[i].x = START_POINT_X;
			Snake[i].y = START_POINT_Y + i;
		} break;
	case DOWN:
		for (int i = 1; i < SNAKE_SIZE; ++i)
		{
			Snake[i].x = START_POINT_X;
			Snake[i].y = START_POINT_Y - i;
		} break;
	default: 
		for (int i = 1; i < SNAKE_SIZE; ++i)					// UP
		{
			Snake[i].x = START_POINT_X;
			Snake[i].y = START_POINT_Y + i;
		} break;
	}
}

int startDirection(void)							// функция генерации начального направления
{
	DWORD nStartValue = time(NULL);
	srand(nStartValue);
	int direction;
	direction = rand() % 4;						// генерация случайного направления

	switch (direction) {
		case 0: return LEFT;
		case 1: return RIGHT;
		case 2: return UP;
		case 3: return DOWN;
		default: return UP;
	}
}

balloonSnake stepSnake(int direction, balloonSnake head)					// функция генерации шага змеи
{
	balloonSnake step;
	switch (direction) {
	case LEFT:	step.x = -1 + head.x;					// лево (был код 75)
				step.y = 0 + head.y; 
			   return step;
	case RIGHT: step.x = 1 + head.x;					// право (был код - 77)
				step.y = 0 + head.y;					
				return step;
	case UP:	step.x = 0 + head.x;					// верх (был код - 72)
				step.y = -1 + head.y; 
				return step;
	case DOWN:	step.x = 0 + head.x;					// низ (был код - 80)
				step.y = 1 + head.y; 
				return step;
	default:	step.x = 0 + head.x;
				step.y = 0 + head.y;
				return step;
	}		 
}

void drawFrame(int x, int y)
{
	/*  o----> X
	    |
	    |
	    Y       */
	printf("Змейка! Поехали.......");									//
	gotoxy(startPointFrame);					// начало отрисовки рамки
	for(int i = 0; i <= y; i++)
	{
		for(int j = 0; j <= x; j++)
		{
			if(i == 0 || i == y)
			{
				if (j == 0 || j == x) putchar(NODE_FRAME);				// отрисовка узвол рамки
				else putchar(HORIZONT_LINE_FRAME);						// отрисовка горизонтальной линии
			}
			else
			{
				if (j == 0 || j == x) putchar(VERTICAL_LINE_FRAME);		// отрисовка вертикальной линии
				else putchar(EMPTY_SYMBOL_FRAME);						// отрисовка пустоты
			}
			if (j == x) putchar(NEW_LINE_FRAME);
		}
	}
}


//void gotoxy(int x, int y)
//{
//	COORD position = { x, y };
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
//}

void gotoxy(balloonSnake step)
{
	COORD position = { step.x, step.y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

bool snakeCrash(balloonSnake position)						// функция определения столкновения змеи с рамкой
{
	if (position.x <= START_POINT_FRAME_X || position.x >= START_POINT_FRAME_X + FRAME_X ||
		position.y <= START_POINT_FRAME_Y || position.y >= START_POINT_FRAME_Y + FRAME_Y) return true;
	else return false;
}

foodPosition foodGenerator()								// генератор еды
{	
	foodPosition food;
	DWORD nStartValue = time(NULL);
	srand(nStartValue);
	int food_x, food_y;
	food.x = rand() % (START_POINT_FRAME_X + FRAME_X);
	food.y = rand() % (START_POINT_FRAME_Y + FRAME_Y);
	return food;
}
