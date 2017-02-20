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

void drawFrame(int, int);					// функция отрисовки ограничивающей рамки
void gotoxy(int, int);						// функция перемещения курсора по заданным координатам
int startDirection(void);					// функция генерации начального направления
void newSnake(balloonSnake *,int leight, int direction);		// функция начальной генерации тела змеи



int main()
{
	system("color 1E");						// Установка синего фона и желтого текста
	setlocale(LC_CTYPE, "rus");

	drawFrame(FRAME_X, FRAME_Y);			// нарисовать рамку

	int key, // текущее значение управляющей клавиши (стрелки)
		dx = 1, // начальная инициализация приращений по координатам (змея ползет вправо)
		dy = 0;
	balloonSnake Snake[SNAKE_MAX_SIZE];	// массив описывающий положение змеи в координатах
	int bodySnake[2][SNAKE_MAX_SIZE],				// массив описывающий положение змеи в координатах
		longSnake = SNAKE_SIZE,						// l - текущий размер змеи
		i; 

	newSnake(Snake, SNAKE_SIZE, startDirection());				// функция генерации начального тела змеи


	bodySnake[0][0] = START_POINT_X + 4;
	bodySnake[1][0] = START_POINT_Y;
	bodySnake[0][1] = START_POINT_X + 3;
	bodySnake[1][1] = START_POINT_Y;
	bodySnake[0][2] = START_POINT_X + 2;
	bodySnake[1][2] = START_POINT_Y;
	bodySnake[0][3] = START_POINT_X + 1;
	bodySnake[1][3] = START_POINT_Y;
	bodySnake[0][4] = START_POINT_X;
	bodySnake[1][4] = START_POINT_Y;

	while (true) // цикл программы
	{
		gotoxy(bodySnake[0][0], bodySnake[1][0]);					// перемещение курсора в первых сектор змеи
		putchar(HEAD_SNAKE);						// отрисовка головы змеи
		for (i = 1; i < longSnake; i++)
		{
			gotoxy(bodySnake[0][i], bodySnake[1][i]);
			putchar(BODY_SNAKE);
		}
		if (kbhit() != false)
		{
			key = _getch();					// перехват нажатия клавиш
			if (key == 27) {				// прекращение цикла при нажатии Esc
				gotoxy(0,
					   START_POINT_FRAME_Y + FRAME_Y + 1);				// завершающая надпись после рамки
				break; 
			}
			if (key == 0) key = _getch();	// повторный вызов т.к. первоначально стрелки возвращают 0
			switch (key) {
				case LEFT: dx = -1; dy = 0;			// лево (был код 75)
					break;
				case RIGHT: dx = 1; dy = 0;			// право (был код - 77)
					break;
				case UP: dx = 0; dy = -1;			// верх (был код - 72)
					break;
				case DOWN: dy = 1;	dx = 0;			// низ (был код - 80)
					break;
			}
			//if (key == LEFT) {				// лево (был код 75)
			//	dx = -1; dy = 0;}
			//if (key == RIGHT) {				// право (был код - 77)
			//	dx = 1; dy = 0;	}
			//if (key == UP) {				// верх (был код - 72)
			//	dx = 0; dy = -1;}
			//if (key == DOWN) {				// низ (был код - 80)
			//	dy = 1;	dx = 0;	}
		}
		gotoxy(bodySnake[0][longSnake - 1], bodySnake[1][longSnake - 1]);
		putchar(EMPTY_SPACE);

		for (i = longSnake - 1; i > 0; i--)
		{
			bodySnake[0][i] = bodySnake[0][i - 1];
			bodySnake[1][i] = bodySnake[1][i - 1];
		}
		bodySnake[0][0] += dx;
		bodySnake[1][0] += dy;
		gotoxy(bodySnake[0][0], bodySnake[1][0]);

		Sleep(500);								// задержка времени
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
			Snake[i].x = START_POINT_X - i;
			Snake[i].y = START_POINT_Y;
		} break;
	case RIGHT:
		for (int i = 1; i < SNAKE_SIZE; ++i)
		{
			Snake[i].x = START_POINT_X + i;
			Snake[i].y = START_POINT_Y;
		} break;
	case UP:
		for (int i = 1; i < SNAKE_SIZE; ++i)
		{
			Snake[i].x = START_POINT_X;
			Snake[i].y = START_POINT_Y - i;
		} break;
	case DOWN:
		for (int i = 1; i < SNAKE_SIZE; ++i)
		{
			Snake[i].x = START_POINT_X;
			Snake[i].y = START_POINT_Y + i;
		} break;
	default: 
		for (int i = 1; i < SNAKE_SIZE; ++i)					// UP
		{
			Snake[i].x = START_POINT_X;
			Snake[i].y = START_POINT_Y - i;
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

void drawFrame(int x, int y)
{
	/*  o----> X
	    |
	    |
	    Y       */
	printf("Змейка! Поехали.......");									//
	gotoxy(START_POINT_FRAME_X, START_POINT_FRAME_Y);					// начало отрисовки рамки
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


void gotoxy(int x, int y)
{
	COORD position = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}
