/* bubnov_function.c	230217
 * Данные файл создается с целью реализации в нем функций частоиспользуемых при программировании.
 * Функции реализуются на языке C
 *
 */

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "bubnov_function.h"

 // decomposition into bit components
 // функция раскладывает простое число на разрядные слагаемые
 // 12345 -> |1|2|3|4|5|
 // -12345 -> |-1|2|3|4|5|
 // 0 -> |0|
 // на входе целое число, на выходе массив элементами которого являются 
 // разрадные слагаемые
void decomposIntoBitComponents(int num, int *m) {
	int i = 1;					// число для сравнения
	int n = 1;					// счетчик разрядов
	if (num >= 0) {
		while (n <= num) {
			n *= 10;
			i++;
		} // while
	} // if
	else {
		while (n <= abs(num))
		{
			n *= 10;
			i++;
		} // while
	} // else
	if(num >= 0) {
		i = i - 1;
		m[0] = i;						// первый элемент массива его размер
		while(i >= 1) {
			n /= 10;
			m[i] = num / n;
			num -= (n * m[i]);
			i--;
		} // while
	} // if
	else {	
		i = i - 1;
		m[0] = i;						// первый элемент массива его размен
		if (i > 0) {					// первая итерация записывает в наивысший разряд отрицательное число
			n /= 10;
			m[i] = num / n;
			num = -num;					// смена знака исходного отрицательного числа
			num -= (n * -m[i]);
			i--;
		}
		while (i >= 1) {
			n /= 10;
			m[i] = num / n;
			num -= (n * m[i]);
			i--;
		} // while
	} // else
} // decomposIntoBitComponents

// функция выводит на экран консоли элементы массива
// первый элемент массива равен его размеру
// на входе массив целых чисел первй элемент которого размер массива
void printArray(int *m)
{
	printf("[");
	for(int i = 1; i <= m[0]; i++)
	{
		printf("%d, ", m[i]);
	}
	printf("\b\b]\n");
} // printArray

// функция производит реверс массива
// первый элемент массива равен его размеру и остается на своем месте
void reversArray(int m[])
{
	if (m[0] <= 0) return;					// если размер меньше или равен нулю, то выход из функции
	int temp = 0,
		size_m = m[0],						// полный размер массива
		size_m_2 = m[0] / 2;				// половина массива
	// если size_m = 5 то будет 2; если size_m = 6 то будет 3
	for(int i = 1; i <= size_m_2; i++)
	{
		temp = m[i];
		m[i] = m[size_m];
		m[size_m] = temp;
		size_m--;
	} // for
} // reversArray


  // функция проверяет массив на симметричность (палиндром) и
  // в случае положительного результата возвращает true
  // если массив не симметричен и состоит из одного элемента возвращает false
_Bool palindromeArray(int m[])
{
	//_Bool palindrome = false;
	if (m[0] <= 0 || m[0] == 1) return false;		// если размер меньше или равен нулю или равен 1, 
													// то выход из функции со значением false
	int size_m = m[0],						// полный размер массива
		size_m_2 = m[0] / 2;				// половина массива
											// если size_m = 5 то будет 2; если size_m = 6 то будет 3
	for (int i = 1; i <= size_m_2; i++)
	{
		if(m[i] != m[size_m]) return false;
		size_m--;
	} // for
	return true;
} // polindromArray

//-----------------------------------------------------------------------------------
// функции для работы с массивами для заданий модуля №06

// функция создания массива
// первый элемент созданного массива равен значению количества его элементов

// пока не удается реализовать по причине невозможности задать массив
// без использования константного значения

//void createArray(int *m, unsigned int size_m)
//{
//	static int array_m[size_m + 1];
//
//}

// функция заполнения массива случайными числами
// первый элемент массива равен значению количества его элементов
void generatorArray(int m[], int size_m, int range)
{
	DWORD nStartValue = time(NULL);
	srand(nStartValue);
	m[0] = size_m - 1;								// запись размера массива в первый элемент минул один элемент под размер
	for (int i = 1; i < size_m; i++) {
		m[i] = rand() % (range + 1);
	}
} // generatorArray


// нахождение максимального элемента в массиве
// numMaxElemen - номер максимального элемента в массиве
int maxElementArray(int m[], int *numMaxElemen)
{
	int max = m[1];						// присвоение переменной max значения первого элемента массива
	*numMaxElemen = 1;
	for(int i = 2; i < m[0]; i++)
	{
		if (m[i] > max) {
			max = m[i];
			*numMaxElemen = i;
		} // if
	} // for
	return max;
} // maxElementArray


// нахождение минимального элемента в массиве
int minElementArray(int m[], int *numMinElemen)
{
	int min = m[1];						// присвоение переменной min значения первого элемента массива
	*numMinElemen = 1;
	for (int i = 2; i < m[0]; i++)
	{
		if (m[i] < min) {
			min = m[i];
			*numMinElemen = i;
		} // if
	} // for
	return min;
} // minElementArray

// сортировка массива по методу максимума
void sortArray(int m[])
{
	int max, num_max, temp, currentSize_m = m[0];
	// 1. находим максимум
	max = maxElementArray(m, &num_max);
	// 2. переносим его на место полследнего элемента
	for(int i = m[0]; i >= 1; )
	{
		temp = m[i];			// записываем во временную переменную значение последнего элемента
		m[i] = max;				// записываем макмимальное значение массива в последний элемент
		m[num_max] = temp;		// на место элемента с макс. значением записывем значение последнего элемента
		m[0] = i--;				// уменьшение счетчика с присовоением уменьшенного размера массиву
		max = maxElementArray(m, &num_max);
	}
	// 3. переходим к шагу №1 с уменьшением диапазона поиска
	m[0] = currentSize_m;		// запись реального значения массива
}


// линейный поиск элемента в массиве
_Bool searchElementArray(int elem, int m[], int *numElem)
{
	for(int i = 1; i < m[0]; i++)
	{
		if(m[i] == elem)
		{
			*numElem = i;
			return true;
		} // if
	} // for
	numElem = NULL;					// в случае отсутствия элемента перевести указатель в нулевой адрес
	return false;
}
