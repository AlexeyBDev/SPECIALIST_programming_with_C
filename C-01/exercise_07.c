/* Вычислить периметр и площадь:
1.квадрата со стороной, равной а.
2.прямоугольного треугольника с катетами a и b.
3.равнобедренного треугольника с основанием a и высотой h.
4.равнобокой трапеции с длинами оснований a и b и высотой h.
5.равностороннего треугольника со стороной, равной a.
*/

//#include <stdio.h>
//#include <math.h>
//#include <locale.h>
//
//enum figur { square = 1, rightTriangle, isoscelesTriangle, isoscelesTrapezoid, equilateralTriangle };
//
//// calculation functions parameters
//void squareFunction(float a, float* perimeter, float* area); // for square
//void rightTriangleFunction(float a, float b, float *perimeter, float *area); // for rectangle
//void isoscelesTriangleFunction(float a, float h, float *perimeter, float *area); // for TriangleFunction
//void isoscelesTrapezoidFunction(float a, float b, float h, float *perimeter, float *area); // for isoscelesTrapezoid
//void equilateralTriangleFunction(float a, float *perimeter, float *area); // for equilateralTriangle
//
//
//int main(int argc, char* argv[])
//{
//	setlocale(LC_ALL, "Russian");
//
//	float perimetrVal, areaVal;
//	perimetrVal = areaVal = 0.0f;
//	float a = 0.0;
//	int switcher = 0;
//
//	printf("Specify which figure you want to work(1 - square, 2 - rectangle, 3 - isosceles triangle, \
//4 - isosceles trapezoid, 5 - equilateral triangle): ");
//	scanf("%d", &switcher);
//
//	switch (switcher)
//	{
//		case square:	// 1
//			printf("Enter a length of a side of square: ");
//			float squA = 0.0;	// side of square
//			scanf("%f", &squA);
//			squareFunction(squA, &perimetrVal, &areaVal);
//			break; // 1
//		case rightTriangle:	// 2
//			printf("Enter the values of sides of a right triangle: ");
//			float rTrianglA, rTrianglB;	// side of square
//			rTrianglA = rTrianglB = 0.0;
//			scanf("%f %f", &rTrianglA, &rTrianglB);
//			rightTriangleFunction(rTrianglA, rTrianglB, &perimetrVal, &areaVal);
//			break; // 2
//		case isoscelesTriangle: // 3
//			printf("Enter the value of base and height of triangle: ");
//			float isTrianglA, isTrianglH;	// side of square
//			isTrianglA = isTrianglH = 0.0;
//			scanf("%f %f", &isTrianglA, &isTrianglH);
//			isoscelesTriangleFunction(isTrianglA, isTrianglH, &perimetrVal, &areaVal);
//			break; // 3
//		case isoscelesTrapezoid: // 4
//			printf("Enter the lengths of the bases and the height of the trapezoid: ");
//			float trapA, trapB, trapH;
//			trapA = trapB = trapH = 0.0;
//			scanf("%f %f %f", &trapA, &trapB, &trapH);
//			isoscelesTrapezoidFunction(trapA, trapB, trapH, &perimetrVal, &areaVal);
//		break; // 4
//		case equilateralTriangle: // 5
//			printf("Enter the value of side of equilateral triangle: ");
//			float a;
//			a = 0.0;
//			scanf("%f", &a);
//			equilateralTriangleFunction(a, &perimetrVal, &areaVal);
//		break; // 5
//		default:
//			printf("Incorrect data!\n");
//			return -1;
//	}
//
//	printf("Perimetr: %.2f\n", perimetrVal);
//	printf("Area: %.2f\n", areaVal);
//	return 0;
//}
//
//void squareFunction(float a, float *perimeter, float *area)
//{
//	*perimeter = a * 4.0f;
//	*area = a * a;
//}
//
//
//void rightTriangleFunction(float a, float b, float* perimeter, float* area)
//{
//	float c = sqrt(a * a + b * b);
//	*perimeter = a + b + c;
//	*area = a * b / 2.0;
//}
//
//
//void isoscelesTriangleFunction(float a, float h, float *perimeter, float *area)
//{	
//	float b = sqrt(a * a / 4.0 + h * h);
//	*perimeter = 2.0 * b + a;
//	*area = a* h / 2.0;
//}
//
//
//void isoscelesTrapezoidFunction(float a, float b, float h, float *perimeter, float *area)
//{
//	float delta = (b - a) / 2.0;
//	float c = sqrt(delta * delta + h * h);
//	*perimeter = a + b + c * 2.0;
//	*area = (a + b) * h / 2.0;
//}
//
//void equilateralTriangleFunction(float a, float *perimeter, float *area)
//{
//	*perimeter = 3.0 * a;
//	*area = sqrt(3.0) * a * a / 4.0;
//}
