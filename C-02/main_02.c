#include <stdio.h>


int ex_01(void);
int ex_02(void);


int main()
{
	//int k;
	//char c;

	//k = 129;
	//c = k;

	//printf("c = %c, k = %k\n", c, k);

	//int a, b;

	//a = 123;
	//b = -321;

	//printf("%d %d %d\n", a, -a, +a);
	//printf("%d %d %d\n", b, -b, +b);

	//// 16 = 5 * 3 + 1
	////-16 = 5 * (-3) + (-1)
	//// -16 = 5 * (-4) + 4
	//// тут, как правило, исходят из знака исходного числа

	//int A, B, C, D;

	//A = B = 2;
	//C = ++A;
	//D = B++;
	//printf("A = %d, B = %d\n"
	//	"C = %d, D = %d\n",
	//	A, B, C, D);

	ex_02();
	return 0;
}

int ex_01()
{
	int a = 1, b = 2, c;
	double x = 1., y = 2., z;

	c = a + b;
	z = x + y;
	c = a + x;
	z = y + b;

	return 0;
}

int ex_02()
{
	printf("%d\n", ~0);
	printf("%d\n", (10 & 5));
	printf("%d\n", (2 | 5));
	printf("%d\n", 200);
	printf("%d\n", (200 >> 1));
	printf("%d\n", (200 << 1));

	printf("%d %d %d %d %d %d %d %d\n",
		sizeof(char),
		sizeof(short),
		sizeof(int),
		sizeof(long),
		sizeof(long long),
		sizeof(float),
		sizeof(double),
		sizeof(long double));
}