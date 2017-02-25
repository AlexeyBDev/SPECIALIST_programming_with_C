/*
 * 6. Отсортировать массив по возрастанию методом:
	a. «пузырька»
	b. вставок
	c. поиска максимума
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
//	//size_t a; - данные тип гарантирует что им можно измерить любой объект созданные тут
//	// size_t - тип для размеров
//	int *max;
//	int p = 0;
//		//max = &p;
//	int m[SIZE_M];
//	generatorArray(m, SIZE_M, 100);				// генерация значений массива
//	printArray(m);								// вывод значений массива
//
//	printf("Элемент с максимальным значением %d имеет номер %d\n", maxElementArray(m, &p), p);
//	printf("Элемент с минимальным значением %d имеет номер %d\n", minElementArray(m, &p), p);
//	sortArray(m);								// сортировка массива
//	printArray(m);								// вывод сортированного массива
//
//	DWORD nStartValue = time(NULL);
//	srand(nStartValue);
//
//	int element = rand() % (SIZE_M);
//	printf("Сгенерирован элемент - %d\n", element);
//	if (searchElementArray(element, m, &p)) {
//		printf("Элемент %d содержится в данном массиве под номером %d.\n", element, p);
//	}
//	else
//	{
//		printf("Элемент %d отсутствует в данном массиве.\n", element);
//	}
//	return 0;
//}