/*
* ¬вести две даты в формате дд.мм.гггг, напечатать знак сравнени€ между ними
*/

//#include <stdio.h>
//#include <locale.h>
//
//
//int main()
//{
//	setlocale(LC_CTYPE, "Russian");
//
//	int d1, m1, y1;
//	int d2, m2, y2;
//	int marker = 2;
//
//	d1 = d2 = m1 = m2 = y1 = y2 = 0;
//	printf("¬ведите дату є1(в формате дд.мм.гггг): ");
//	scanf("%2d.%2d.%4d", &d1, &m1, &y1);
//	printf("¬ведите дату є2(в формате дд.мм.гггг): ");
//	scanf("%2d.%2d.%4d", &d2, &m2, &y2);
//
//	marker = (y1 < y2 ? 0 : 
//		y1 > y2 ? 1 :
//		m1 < m2 ? 0 :
//		m1 > m2 ? 1 :
//		d1 < d2 ? 0 :
//		d1 > d2 ? 1 : 2);
//
//	printf("%d.%d.%d %s %d.%d.%d\n", d1, m1, y1,
//		(marker == 0 ? "<" : marker == 1 ? ">" : marker == 2 ? "=" : "?"), d2, m2, y2);
//
//	return 0;
//}