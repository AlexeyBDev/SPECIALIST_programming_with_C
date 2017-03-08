// эксперементы с €зыком на тему классов пам€ти

#include <stdio.h>
#include <locale.h>
#include "testMem.h"	// файл с внешними данными

// глобальные переменные
int c;
extern int d;

int main()
{
	setlocale(LC_CTYPE, "rus");
	// переменна€ указатель
	int *p;
	printf("јдрес переменной p = %p\n\n", &p);
	// вз€тие адреса глобальной переменной c
	p = &c;													// c объ€влена в данном файле
	printf("јдрес глобальной переменной c = %p\n", p);
	p = &d;
	printf("јдрес глобальной переменной extern d = %p\n\n", p);
	// разность адресов глобальных переменных
	printf("–азность адресов глобальных переменных c = %p\n", &c - &d); // наход€тс€ близко
	printf("–азность адресов глобальной переменной \n"
		"и переменной со стека c - p = %p\n\n", (&c - &p)); // наход€тс€ далеко

	auto int a = 10;
	p = &a;
	printf("ѕеременна€ типа auto int a = %d\n", a);
	printf("јдрес переменной типа auto int &a = %p\n\n", p);

	int b = 100;
	p = &b;
	printf("ѕеременна€ типа int b = %d\n", b);
	printf("јдрес переменной типа int &b = %p\n\n", p);

	printf("int с = %d\n", c);
	d = 135;
	printf("int d = %d\n\n", d);

	// p = &TEST_VAR; // получить адрес макроса нельз€!!!
	printf("TEST_VAR = %d\n\n", TEST_VAR);
	// static переменные
	printf("“естирование статических переменные: ");
	for (int k = 0; k < 5; ++k) staticVarF();

	// тестирование регистровых переменных
	register int reg;
	for (reg = 0; reg < 1000000; ++reg);
	printf("–егистрова€ переменна€ reg = %d\n\n", reg);


	return 0;
}