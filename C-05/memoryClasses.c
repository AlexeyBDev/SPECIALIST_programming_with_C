// ������������ � ������ �� ���� ������� ������

#include <stdio.h>
#include <locale.h>
#include "testMem.h"	// ���� � �������� �������

// ���������� ����������
int c;
extern int d;

int main()
{
	setlocale(LC_CTYPE, "rus");
	// ���������� ���������
	int *p;
	printf("����� ���������� p = %p\n\n", &p);
	// ������ ������ ���������� ���������� c
	p = &c;													// c ��������� � ������ �����
	printf("����� ���������� ���������� c = %p\n", p);
	p = &d;
	printf("����� ���������� ���������� extern d = %p\n\n", p);
	// �������� ������� ���������� ����������
	printf("�������� ������� ���������� ���������� c = %p\n", &c - &d); // ��������� ������
	printf("�������� ������� ���������� ���������� \n"
		"� ���������� �� ����� c - p = %p\n\n", (&c - &p)); // ��������� ������

	auto int a = 10;
	p = &a;
	printf("���������� ���� auto int a = %d\n", a);
	printf("����� ���������� ���� auto int &a = %p\n\n", p);

	int b = 100;
	p = &b;
	printf("���������� ���� int b = %d\n", b);
	printf("����� ���������� ���� int &b = %p\n\n", p);

	printf("int � = %d\n", c);
	d = 135;
	printf("int d = %d\n\n", d);

	// p = &TEST_VAR; // �������� ����� ������� ������!!!
	printf("TEST_VAR = %d\n\n", TEST_VAR);
	// static ����������
	printf("������������ ����������� ����������: ");
	for (int k = 0; k < 5; ++k) staticVarF();

	// ������������ ����������� ����������
	register int reg;
	for (reg = 0; reg < 1000000; ++reg);
	printf("����������� ���������� reg = %d\n\n", reg);


	return 0;
}