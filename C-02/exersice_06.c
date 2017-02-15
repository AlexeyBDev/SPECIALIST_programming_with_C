/*
* ¬вести два значени€ времени в формате чч:мм:сс, проверить корректность ввода и напечатать 
* знак сравнени€ между ними
*/

//#include <stdio.h>
//#include <locale.h>
//
//
//int main()
//{
//	setlocale(LC_CTYPE, "Russian");
//
//	int h1, m1, s1;
//	int h2, m2, s2;
//	h1 = h2 = m1 = m2 = s1 = s2 = 0;
//	int timeInSec_1 = 0, timeInSec_2 = 0;
// 
//	printf("¬ведите значение времени є1 (в формате чч:мм:сс): ");
//	scanf("%d:%d:%d", &h1, &m1, &s1);
//	printf("¬ведите значение времени є2 (в формате чч:мм:сс): ");
//	scanf("%d:%d:%d", &h2, &m2, &s2);
//	timeInSec_1 = s1 + m1 * 60 + h1 * 3600;
//	timeInSec_2 = s2 + m2 * 60 + h2 * 3600;
//
//	printf("%d:%d:%d %s %d:%d:%d\n", h1, m1, s1,
//		(timeInSec_1 > timeInSec_2 ? ">" : timeInSec_1 < timeInSec_2 ? "<" : "="),
//		h2, m2, s2);
//
//	return 0;
//}