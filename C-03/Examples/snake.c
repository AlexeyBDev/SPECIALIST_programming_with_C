/* ��������� ������������ ���� "������"
 * ��������� ����� ��������� �������� �� ������ �� ���������������� �� � (����������). 
 * �������������� ����� ����������.
 * ������ 0.2
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <time.h>
#include <stdbool.h>
#include <windows.h>

// ��������� �������������� �����
#define START_POINT_FRAME_X 0				// ��������� ����� ����� (X)
#define START_POINT_FRAME_Y 1				// ��������� ����� ����� (Y)
#define FRAME_X 60							// ������ ����� �� x
#define FRAME_Y 20							// ������ ����� �� y
#define NODE_FRAME '+'						// ������ � ����� ����� '+'
#define HORIZONT_LINE_FRAME '-'				// ������ �������������� ����� ����� '-'
#define VERTICAL_LINE_FRAME '|'				// ������ ������������ ����� ����� '|'
#define EMPTY_SYMBOL_FRAME ' '				// ������ ������ ����� ' '
#define NEW_LINE_FRAME '\n'					// ������ ������ ��������� ����� �����
// ��������� ����
#define HEAD_SNAKE '@'						// ������ ������ ����
#define BODY_SNAKE 'o'						// ������ ���� ���� 'o'
#define SNAKE_SIZE 5						// ��������� ������ ����
#define SNAKE_MAX_SIZE 10					// ������������ ����� ����
#define EMPTY_SPACE ' '						// ������ ������� � ������� ���� ���� (������)
// ���� ���������
#define START_POINT_X FRAME_X / 2			// x ������ �������� ����
#define START_POINT_Y FRAME_Y / 2			// y ������ �������� ����
#define SLEEP 100							// ��� �����
#define FOOD '*'							// ������ ���
// �����������
#define UP 0x48
#define DOWN 0x50
#define LEFT 0x4b
#define RIGHT 0x4d

struct balloon_snake						// ��������� ��������� ������� ����
{
	int x;
	int y;
};

typedef struct balloon_snake balloonSnake;	// ����� ��� ���������
typedef struct balloon_snake foodPosition;	// ����� ��� ���������

balloonSnake startPointFrame = { START_POINT_FRAME_X,// ����� ������ ��������� �����
START_POINT_FRAME_Y };
balloonSnake pointForEndMessage = { 0,			// ����� ������ ����������� ������� �� ��������� ���������
START_POINT_FRAME_Y + FRAME_Y + 1 };

void drawFrame(int, int);					// ������� ��������� �������������� �����
//void gotoxy(int, int);						// ������� ����������� ������� �� �������� �����������
void gotoxy(balloonSnake);						// ������� ����������� ������� �� �������� �����������
int startDirection(void);					// ������� ��������� ���������� �����������
void newSnake(balloonSnake *,int leight, int direction);		// ������� ��������� ��������� ���� ����
balloonSnake stepSnake(int direction, balloonSnake head);		// ������� ��������� ���� ����
bool snakeCrash(balloonSnake position);							// ������� ����������� ������������ ���� � ������
foodPosition foodGenerator();									// ��������� ���



int main()
{
	system("color 1E");						// ��������� ������ ���� � ������� ������
	setlocale(LC_CTYPE, "rus");

	drawFrame(FRAME_X, FRAME_Y);			// ���������� �����

	int key = RIGHT/*startDirection()*/, // ������� �������� ����������� ������� (�������)
		prevKey,
		dx = 1, // ��������� ������������� ���������� �� ����������� (���� ������ ������)
		dy = 0;
	balloonSnake Snake[SNAKE_MAX_SIZE];				// ������ ����������� ��������� ���� � �����������

	int longSnake = SNAKE_SIZE,						// longSnake - ������� ������ ����
		i; 

	newSnake(Snake, SNAKE_SIZE, key);				// ������� ��������� ���������� ���� ����
	foodPosition food;

	while (true) // ���� ���������
	{
		if (snakeCrash(Snake[0])) {					// ������������ ���� � ������
			gotoxy(pointForEndMessage);				// ����������� ������� ����� �����
			printf("������!!!\n");
			break;
		}

		food = 
		gotoxy(Snake[0]);					// ����������� ������� � ������ ������ ����
		putchar(HEAD_SNAKE);						// ��������� ������ ����
		for (i = 1; i < longSnake; i++)
		{
			gotoxy(Snake[i]);
			putchar(BODY_SNAKE);
			gotoxy(Snake[i]);
		}
		if (kbhit() != false)
		{
			prevKey = key;
			key = getch();								// �������� ������� ������
			if (key == 27) {							// ����������� ����� ��� ������� Esc
				gotoxy(pointForEndMessage);				// ����������� ������� ����� �����
				break; 
			}
			if (key == 224) key = getch();				// ��������� ����� �.�. ������������� ������� ���������� E0
			// �������
			/*gotoxy(pointForEndMessage);
			printf("%d\t%x", key, key);*/
			if (key == RIGHT && prevKey == LEFT) key = LEFT;	// ���� �� ����� ������ ����� ����
			if (key == LEFT && prevKey == RIGHT ) key = RIGHT;
			if (key == DOWN && prevKey == UP) key = UP;
			if (key == UP && prevKey == DOWN) key = DOWN;
			
		}
		gotoxy(Snake[0]);							// ������� ������� � ������ ����
		if (key == LEFT || key == RIGHT) Sleep(SLEEP);// �������� �������
		else Sleep(SLEEP * 1.5);							// �������� ����� �������� ��������� � 1.5 ����								
		
		gotoxy(Snake[longSnake - 1]);				// ���� ������� � ��������� ������ �����
		putchar(EMPTY_SPACE);						// ��������� �������

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

int startDirection(void)							// ������� ��������� ���������� �����������
{
	DWORD nStartValue = time(NULL);
	srand(nStartValue);
	int direction;
	direction = rand() % 4;						// ��������� ���������� �����������

	switch (direction) {
		case 0: return LEFT;
		case 1: return RIGHT;
		case 2: return UP;
		case 3: return DOWN;
		default: return UP;
	}
}

balloonSnake stepSnake(int direction, balloonSnake head)					// ������� ��������� ���� ����
{
	balloonSnake step;
	switch (direction) {
	case LEFT:	step.x = -1 + head.x;					// ���� (��� ��� 75)
				step.y = 0 + head.y; 
			   return step;
	case RIGHT: step.x = 1 + head.x;					// ����� (��� ��� - 77)
				step.y = 0 + head.y;					
				return step;
	case UP:	step.x = 0 + head.x;					// ���� (��� ��� - 72)
				step.y = -1 + head.y; 
				return step;
	case DOWN:	step.x = 0 + head.x;					// ��� (��� ��� - 80)
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
	printf("������! �������.......");									//
	gotoxy(startPointFrame);					// ������ ��������� �����
	for(int i = 0; i <= y; i++)
	{
		for(int j = 0; j <= x; j++)
		{
			if(i == 0 || i == y)
			{
				if (j == 0 || j == x) putchar(NODE_FRAME);				// ��������� ����� �����
				else putchar(HORIZONT_LINE_FRAME);						// ��������� �������������� �����
			}
			else
			{
				if (j == 0 || j == x) putchar(VERTICAL_LINE_FRAME);		// ��������� ������������ �����
				else putchar(EMPTY_SYMBOL_FRAME);						// ��������� �������
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

bool snakeCrash(balloonSnake position)						// ������� ����������� ������������ ���� � ������
{
	if (position.x <= START_POINT_FRAME_X || position.x >= START_POINT_FRAME_X + FRAME_X ||
		position.y <= START_POINT_FRAME_Y || position.y >= START_POINT_FRAME_Y + FRAME_Y) return true;
	else return false;
}

foodPosition foodGenerator()								// ��������� ���
{	
	foodPosition food;
	DWORD nStartValue = time(NULL);
	srand(nStartValue);
	int food_x, food_y;
	food.x = rand() % (START_POINT_FRAME_X + FRAME_X);
	food.y = rand() % (START_POINT_FRAME_Y + FRAME_Y);
	return food;
}
