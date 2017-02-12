/*
 * ¬вести три числа, напечатать максимальное из них
 */


#include <stdio.h>
#include <locale.h>


int main()
{
	setlocale(LC_CTYPE, "Russian");
	int a, b, c;
	a = b = c = 0;

	int max = 0;

	printf("¬ведите три целых числа: ");
	scanf("%d %d %d", &a, &b, &c);

	max = (a >= b ? (a >= c ? a : c) : (b >= c ? b : c));

	printf("max = %d\n", max);

	return 0;
}