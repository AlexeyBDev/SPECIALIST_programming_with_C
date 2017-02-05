/* Вычислить среднее арифметическое двух значений х1 и х2.
*
*/

#include <stdio.h>

int main()
{
	float x1, x2;
	x1 = x2 = 0.0f;
		printf("Enter 2 int value: ");
		scanf("%f %f", &x1, &x2);

		printf("The average of the numbers %.3f and %.3f is equal to: %.3f\n\n", x1, x2, (x1 + x2) / 2);
	return 0;
}