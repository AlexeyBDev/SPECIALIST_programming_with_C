/*
 * Ќаписать функцию, вычисл€ющую скал€рное произведение двух N - мерных векторов
 */
#include <stdio.h>

#define VECTOR_SIZE 10
#define SIZE 4

float multArray(float a_Array[], float b_Array[], int size); // произведение двух векторов

int main()
{
	int m[3][3] = {1};
	printf("sizeof m = %zd\n", sizeof(m));
	printf("sizeof m[0] = %zd\n", sizeof(m[0]));
	printf("sizeof m[0][0] = %zd\n", sizeof(m[0][0]));
	int n = 5;
	printf("%d\n", n = 10);
	float a[SIZE] = { 2, 3, 4, 5 };
	float b[SIZE][1] = {{4}, {4.3}, {-1}, {32.2}};
	printf("%f\n", multArray(a, b, SIZE));

	return 0;
}


float multArray(float a_Array[], float b_Array[], int size) // произведение двух массивов
{
	float scalarMult = 0.f;
	for(int i = 0; i < size; ++i)
	{
		scalarMult += a_Array[i] * b_Array[i];
	}
	return scalarMult;
}