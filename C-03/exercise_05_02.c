///*
// * Напечатать только те числа из входного потока, которые не содержат одинаковых цифр:
//	2.числа натуральные.
//	3.числа целые (могут быть отрицательными).
// */
//
//#include <stdio.h>
//#include <locale.h>
////#include <limits.h>
//#include <stdbool.h>
//#include <math.h>
//#include "bubnov_function.h"
//
//bool sameSign(int n);							// функция исследует число на предмет наличия одинковых знаков
//												// если есть, то true, в противном случае false
//
//int main()
//{
//	setlocale(LC_CTYPE, "rus");
//
//	int num = 0;
//	int m[30];
//	while (scanf_s("%d", &num) > 0) {
//	//scanf_s("%d", &num);
//		//printf("Число %d введено!\n", num);
//		/*decomposIntoBitComponents(num, m);
//		printArray(m);
//		reversArray(m);
//		printArray(m);*/
//		if (!sameSign(num)) printf("%d\n", num);
//	}
//
//	return 0;
//}
//
//
//bool sameSign(int n)
//{
//	int m[30];							// временный массив
//	decomposIntoBitComponents(n, m);
//	if (m[0] == 1) return false;		// в чмсле с одним разрядом нет повторяющихся чисел
//
//	for(int i = 1; i <= m[0]; i++)
//	{
//		for(int j = i + 1; j <= m[0]; j++)
//		{
//			if (abs(m[i]) == m[j]) return true;	// если знаки сходятся, то true
//		} // for
//	} // for
//	return false;
//} // sameSign
// 