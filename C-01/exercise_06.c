/* Вычислить площадь кольца (внешний радиус R, внутренний -r).
*
*/

#include <stdio.h>

#define _USE_MATH_DEFINES
#include <math.h>
#include <stdbool.h>



float circleArea(float radius);

int main()
{
	float r, R;
	r = R = 0.0f;
	float ringArea = 0;
	while (true)
	{
		printf("Enter the external radius: ");
		scanf("%f", &R);
		printf("Enter the inner radius: ");
		scanf("%f", &r);
		if(R < r)
		{
			printf("\nThe outer radius less the inner. Enter the data again!\n");
			continue;
		}

		ringArea = circleArea(R) - circleArea(r);

		printf("\nExternal radius: %.3f\n", R);
		printf("Inner radius : %.3f\n", r);
		printf("The area of the ring is %.3f\n\n", ringArea);
		break;
	}

	return 0;
}


float circleArea(float radius)
{
	return radius * radius * M_PI;
}