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

void drawFrame(int, int);					// ������� ��������� �������������� �����
void gotoxy(int, int);						// ������� ����������� ������� �� �������� �����������
int startDirection(void);					// ������� ��������� ���������� �����������
void newSnake(balloonSnake *,int leight, int direction);		// ������� ��������� ��������� ���� ����



int main()
{
	system("color 1E");						// ��������� ������ ���� � ������� ������
	setlocale(LC_CTYPE, "rus");

	drawFrame(FRAME_X, FRAME_Y);			// ���������� �����

	int key, // ������� �������� ����������� ������� (�������)
		dx = 1, // ��������� ������������� ���������� �� ����������� (���� ������ ������)
		dy = 0;
	balloonSnake Snake[SNAKE_MAX_SIZE];	// ������ ����������� ��������� ���� � �����������
	int bodySnake[2][SNAKE_MAX_SIZE],				// ������ ����������� ��������� ���� � �����������
		longSnake = SNAKE_SIZE,						// l - ������� ������ ����
		i; 

	newSnake(Snake, SNAKE_SIZE, startDirection());				// ������� ��������� ���������� ���� ����


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

	while (true) // ���� ���������
	{
		gotoxy(bodySnake[0][0], bodySnake[1][0]);					// ����������� ������� � ������ ������ ����
		putchar(HEAD_SNAKE);						// ��������� ������ ����
		for (i = 1; i < longSnake; i++)
		{
			gotoxy(bodySnake[0][i], bodySnake[1][i]);
			putchar(BODY_SNAKE);
		}
		if (kbhit() != false)
		{
			key = _getch();					// �������� ������� ������
			if (key == 27) {				// ����������� ����� ��� ������� Esc
				gotoxy(0,
					   START_POINT_FRAME_Y + FRAME_Y + 1);				// ����������� ������� ����� �����
				break; 
			}
			if (key == 0) key = _getch();	// ��������� ����� �.�. ������������� ������� ���������� 0
			switch (key) {
				case LEFT: dx = -1; dy = 0;			// ���� (��� ��� 75)
					break;
				case RIGHT: dx = 1; dy = 0;			// ����� (��� ��� - 77)
					break;
				case UP: dx = 0; dy = -1;			// ���� (��� ��� - 72)
					break;
				case DOWN: dy = 1;	dx = 0;			// ��� (��� ��� - 80)
					break;
			}
			//if (key == LEFT) {				// ���� (��� ��� 75)
			//	dx = -1; dy = 0;}
			//if (key == RIGHT) {				// ����� (��� ��� - 77)
			//	dx = 1; dy = 0;	}
			//if (key == UP) {				// ���� (��� ��� - 72)
			//	dx = 0; dy = -1;}
			//if (key == DOWN) {				// ��� (��� ��� - 80)
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

		Sleep(500);								// �������� �������
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

void drawFrame(int x, int y)
{
	/*  o----> X
	    |
	    |
	    Y       */
	printf("������! �������.......");									//
	gotoxy(START_POINT_FRAME_X, START_POINT_FRAME_Y);					// ������ ��������� �����
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


void gotoxy(int x, int y)
{
	COORD position = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}
