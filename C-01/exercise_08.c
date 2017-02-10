/* Вычислить площадь поверхности и объем:
   1.цилиндра (радиус r, высота h).
   2.полого цилиндра (радиусы Rи r, высота h).
   3.шара(S=4r2, V=(3/4) r3).
 */

#include <stdio.h>
#include <math.h>
#include <locale.h>

enum figur { cylinder = 1, hollowCylinder, ball };

// calculation functions parameters
void squareFunction(float a, float* perimeter, float* area); // for square
void rightTriangleFunction(float a, float b, float *perimeter, float *area); // for rectangle
void isoscelesTriangleFunction(float a, float h, float *perimeter, float *area); // for TriangleFunction



int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");

	float surfaceArea, volume;
	surfaceArea = volume = 0.0f;
	int switcher = 0;

	printf("Specify which figure you want to work(1 - cylinder, 2 - hollow cylinder, 3 - ball: ");
	scanf("%d", &switcher);

	switch (switcher)
	{
	case square:	// 1
		printf("Enter a length of a side of square: ");
		float squA = 0.0;	// side of square
		scanf("%f", &squA);
		squareFunction(squA, &perimetrVal, &areaVal);
		break; // 1
	case rightTriangle:	// 2
		printf("Enter the values of sides of a right triangle: ");
		float rTrianglA, rTrianglB;	// side of square
		rTrianglA = rTrianglB = 0.0;
		scanf("%f %f", &rTrianglA, &rTrianglB);
		rightTriangleFunction(rTrianglA, rTrianglB, &perimetrVal, &areaVal);
		break; // 2
	case isoscelesTriangle: // 3
		printf("Enter the value of base and height of triangle: ");
		float isTrianglA, isTrianglH;	// side of square
		isTrianglA = isTrianglH = 0.0;
		scanf("%f %f", &isTrianglA, &isTrianglH);
		isoscelesTriangleFunction(isTrianglA, isTrianglH, &perimetrVal, &areaVal);
		break; // 3
	default:
		printf("Incorrect data!\n");
		return -1;
	}

	printf("Perimetr: %.2f\n", perimetrVal);
	printf("Area: %.2f\n", areaVal);
	return 0;
}

void squareFunction(float a, float *perimeter, float *area)
{
	*perimeter = a * 4.0f;
	*area = a * a;
}


void rightTriangleFunction(float a, float b, float* perimeter, float* area)
{
	float c = sqrt(a * a + b * b);
	*perimeter = a + b + c;
	*area = a * b / 2.0;
}


void isoscelesTriangleFunction(float a, float h, float *perimeter, float *area)
{
	float b = sqrt(a * a / 4.0 + h * h);
	*perimeter = 2.0 * b + a;
	*area = a* h / 2.0;
}
