//� ������ ���� ��������� �������� 10 ��. � ������ ��������� ����
//�� �������� �� 10% ������, ��� � ����������.
//1. ������� �� �� �������� � 10-� ����?
//2. � ����� ���� �� ������� �������� ������ 20 ��?
//3. �� ������� ���� ��� ��������� ������ �������� 100 ��?
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
//	double x,	//���������� ������
//		  s;	//��������� ������
//	int	  n;	//������� ����
//
//	puts(setlocale(LC_CTYPE,""));
//
//	for(n=1, x=START_DIST; n<FINAL_DAY; ++n, x *= FACTOR)
//		DUMP(n,x);
//	printf("� %d-� ���� ��������� �������� %.3f ��\n\n",n,x);
//
//	for(n=1, x=START_DIST; x<FINAL_DIST; ++n, x *= FACTOR)
//		DUMP(n,x);
//	printf("� %d-� ���� ��������� �������� %.3f ��\n\n",n,x);
//
//	for(n=1, s=x=START_DIST; s<TOTAL_DIST; ++n, s += x *= FACTOR)
//		DUMP(n,s);
//	printf("�� %d ���� ��������� �������� %.3f ��\n\n",n,s);
//
//}