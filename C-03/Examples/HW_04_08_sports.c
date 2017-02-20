//В первый день спортсмен пробежал 10 км. В каждый следующий день
//он пробегал на 10% больше, чем в предыдущий.
//1. Сколько км он пробежит в 10-й день?
//2. В какой день он впервые пробежит больше 20 км?
//3. За сколько дней его суммарный пробег превысит 100 км?
//#include <math.h>
//#include <stdio.h>
//#include <locale.h>
//
//#define FINAL_DAY	10
//#define START_DIST	10
//#define FINAL_DIST	20
//#define TOTAL_DIST	100
//#define PERCENT		10
//#define FACTOR		(100+PERCENT)/100.0
//
////#define DEBUG 
//
//#ifndef	DEBUG
//#define DUMP(ival,fval)
//#else
//#define DUMP(ival,fval)	printf(#ival"=%d\t"#fval"=%f\n",ival,fval)
//#endif
//
//int main()
//{
//	double x,	//ежедневный пробег
//		  s;	//суммарный пробег
//	int	  n;	//счетчик дней
//
//	puts(setlocale(LC_CTYPE,""));
//
//	for(n=1, x=START_DIST; n<FINAL_DAY; ++n, x *= FACTOR)
//		DUMP(n,x);
//	printf("В %d-й день спортсмен пробежал %.3f км\n\n",n,x);
//
//	for(n=1, x=START_DIST; x<FINAL_DIST; ++n, x *= FACTOR)
//		DUMP(n,x);
//	printf("В %d-й день спортсмен пробежал %.3f км\n\n",n,x);
//
//	for(n=1, s=x=START_DIST; s<TOTAL_DIST; ++n, s += x *= FACTOR)
//		DUMP(n,s);
//	printf("За %d дней спортсмен пробежал %.3f км\n\n",n,s);
//
//}