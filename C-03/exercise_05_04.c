/*
 * Найти первые Nнатуральных чисел –палиндромов.
 */

//#include <stdio.h>
//#include <locale.h>
//#include "bubnov_function.h"
//
//#define SIZE 30
////#pragma 
//
//int main()
//{
//	setlocale(LC_CTYPE, "rus");
//
//	int N = 0;				// счетчик палиндромов
//	int num = 1;			// число проверяемое на палиндромность 
//	int m[SIZE] = {0};					// массив для разложения
//	printf("Сколько чисел палиндромов нужно вывести: ");
//	scanf_s("%d", &N);
//	for(int i = 1; i <= N; )
//	{
//		decomposIntoBitComponents(num, m);			// разложение массива на элементы
//		if(palindromeArray(m))
//		{
//			printf("Число %d палиндром!\n", num);
//			num++;
//			i++;
//		}
//		num++;
//	} // for
//
//
//	return 0;
//}