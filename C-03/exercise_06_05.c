/*
 * 6. ������������� ������ �� ����������� �������:
	a. ���������
	b. �������
	c. ������ ���������
 */

//#include <stdio.h>
//#include <locale.h>
//#include <stdlib.h>
//#include <windows.h>
//#include <time.h>
//#include "bubnov_function.h"
//
//
//
//#define SIZE_M 1000
// 
//int main()
//{
//	setlocale(LC_CTYPE, "rus");
//	
//	//size_t a; - ������ ��� ����������� ��� �� ����� �������� ����� ������ ��������� ���
//	// size_t - ��� ��� ��������
//	int *max;
//	int p = 0;
//		//max = &p;
//	int m[SIZE_M];
//	generatorArray(m, SIZE_M, 100);				// ��������� �������� �������
//	printArray(m);								// ����� �������� �������
//
//	printf("������� � ������������ ��������� %d ����� ����� %d\n", maxElementArray(m, &p), p);
//	printf("������� � ����������� ��������� %d ����� ����� %d\n", minElementArray(m, &p), p);
//	sortArray(m);								// ���������� �������
//	printArray(m);								// ����� �������������� �������
//
//	DWORD nStartValue = time(NULL);
//	srand(nStartValue);
//
//	int element = rand() % (SIZE_M);
//	printf("������������ ������� - %d\n", element);
//	if (searchElementArray(element, m, &p)) {
//		printf("������� %d ���������� � ������ ������� ��� ������� %d.\n", element, p);
//	}
//	else
//	{
//		printf("������� %d ����������� � ������ �������.\n", element);
//	}
//	return 0;
//}