/*
 * Найти первые 20 троек пифагоровых чисел (a2+ b2= c2).
 */

//#include <stdio.h>
//#include <stdbool.h>
//
//struct number3
//{
//	int a, b, c;
//};
//
//typedef struct number3 PithNum;
//
//int main()
//{
//	int a, b, c;
//	int i = 0;
//	const int lim = 50;
//	PithNum m[30];
//	_Bool presence = false;								// маркер присутствия значения в массиве
//
//	for (a = 1; a <= lim; a++)
//		for (b = 1; b <= lim; b++)
//			for (c = 1; c <= lim; c++)
//				if (((a * a) + (b * b)) == (c * c))
//				{
//						if(i == 0)						// запись в массив первого значения
//						{
//							m[i].a = a;
//							m[i].b = b;
//							m[i].c = c;
//							i++;
//							printf("%d. {%d, %d, %d}\n", i, a, b, c);
//							continue;
//						}
//					for (int j = 0; j < i; j++)			// проверка массива на наличие схожих значений
//					{
//						if ((m[j].a == b && m[j].b == a) ||
//							(m[j].a == a && m[j].b == b)) {
//							presence = true;
//							break;
//						} // if
//					} // for
//					if (!presence)
//					{
//						m[i].a = a;
//						m[i].b = b;
//						m[i].c = c;
//						presence = false;
//						i++;
//						printf("%d. {%d, %d, %d}\n", i, a, b, c);
//						if (i >= 30) return 0;
//					} // if
//					presence = false;
//				} // if
//
//	//return 0;
//}
