/* Вычислить площадь поверхности и объем:
   1.цилиндра (радиус r, высота h).
   2.полого цилиндра (радиусы R и r, высота h).
   3.шара(S=4r2, V=(3/4) r3).
 */

//#include <stdio.h>
//#define _USE_MATH_DEFINES
//#include <math.h>
//#include <locale.h>
//
//enum figur { cylinder = 1, hollowCylinder, ball };
//
//// calculation functions parameters
//void cylinderFunction(float r, float h, float *surfaceArea, float* volume); // for cylinder
//void hollowCylinderFunction(float R, float r, float h, float *surfaceArea, float *volume); // for hollow cylinder
//void ballFunction(float r, float *surfaceArea, float *volume); // for ball
//
//
//
//int main()
//{
//	setlocale(LC_ALL, "Russian");
//
//	float surfaceAreaVal, volumeVal;
//	surfaceAreaVal = volumeVal = 0.0f;
//	int switcher = 0;
//
//	printf("Specify which figure you want to work(1 - cylinder, 2 - hollow cylinder, 3 - ball: ");
//	scanf("%d", &switcher);
//
//	switch (switcher)
//	{
//	case cylinder:	// 1
//		printf("Enter the radius and height of cylinder: ");
//		float r, h;
//		r = h = 0.0;
//		scanf("%f %f", &r, &h);
//		cylinderFunction(r, h, &surfaceAreaVal, &volumeVal);
//		break; // 1
//	case hollowCylinder:	// 2
//		printf("Enter large and small radius and height of a hollow cylinder: ");
//		float hCil_R, hCil_r, hCil_h;	
//		hCil_R = hCil_r = hCil_h = 0.0;
//		scanf("%f %f %f", &hCil_R, &hCil_r, &hCil_h);
//		hollowCylinderFunction(hCil_R, hCil_r, hCil_h, &surfaceAreaVal, &volumeVal);
//		break; // 2
//	case ball: // 3
//		printf("Enter a value for the radius of the ball: ");
//		float ballR = 0;
//		scanf("%f", &ballR);
//		ballFunction(ballR, &surfaceAreaVal, &volumeVal);
//		break; // 3
//	default:
//		printf("Incorrect data!\n");
//		return -1;
//	}
//
//	printf("Surface area: %.2f m2\n", surfaceAreaVal);
//	printf("Volume: %.2f m3\n", volumeVal);
//	return 0;
//}
//
//void cylinderFunction(float r, float h, float *surfaceArea, float *volume)
//{
//	*surfaceArea = 2.0 * M_PI * r * (h + r);
//	*volume = M_PI * r * r * h;
//}
//
//
//void hollowCylinderFunction(float R, float r, float h, float *surfaceArea, float *volume)
//{
//	*surfaceArea = 2.0 * M_PI * (R * R - r * r) + R * h;
//		*volume = M_PI * h * (R * R - r * r);
//}
//
//
//void ballFunction(float r, float *surfaceArea, float *volume)
//{
//	*surfaceArea = 4.0 * r * r;
//	*volume = 3.0 / 4.0 * r * r * r;
//}
