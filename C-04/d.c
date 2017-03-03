//#include<stdio.h>
//#include<locale.h>
//#include<stdlib.h>
//
//void bin_print(unsigned x, int radix)
//{
//	if(x>= radix) bin_print(x / radix, radix);
//	printf("%X", x % radix);
//}
//
//int main()
//{
//	int a[] = { 2,6,5,3,8,4,9,2,7,4 };
//	const size_t n = sizeof a / sizeof a[0];
//	size_t i;
//	int x;
//	char buf[80], end;
//	int error;
//	int found;
//
//	
//	scanf("%d", &x);
//	printf("%X\n", x);
//	bin_print(x,2); printf("\n");
//	printf("%d\n", x);
//	bin_print(x,10); printf("\n");
//	bin_print(x,3); printf("\n");
//
//	return 0;
//
//	setlocale(LC_CTYPE, "");
//	//1. распечатка массива
//	for (i = 0; i < n; ++i)
//		printf("%d, ", a[i]);
//	printf("\b\b \n");
//
//	//линейный поиск 
//	do
//	{
//		printf("Какое значение будем искать?\n");
//		scanf_s(" %[^\n]", buf, sizeof buf);
//		error = sscanf_s(buf, "%d%c", &x, &end, sizeof end) != 1
//				&& end != '\n'
//				&& printf("Введено: %s\nНадо вводить целое число\n", buf)
//			||  x < 0
//				&& printf("Введено: %d\nНадо вводить положительное целое число\n", x);
//	} while (error);
//
//	//поиск
//	for (i = 0;  a[i] != x ; ++i)
//		;
//
//	if(i < n)
//		printf("a[%d]=%d\n", i, x);
//	else
//		printf("%d нет в массиве\n", x);
//
//
//}
/*
void strcopy(char t[], const char s[])
{
	int i;
	for (i = 0; t[i] = s[i]; ++i)
		;
 }

n! = 1*2*3*...*(n-1)*n = n*(n-1)!

h(N, 1, 3, 2)
{
	h(N - 1, 1, 2, 3);
	h(    1, 1, 3, 2);
	h(N - 1, 2, 3, 1);
}


  1+(2-3*4)*5-6=

*/