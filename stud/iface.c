#include <stdio.h>
#include "data.h"
#include "iface.h"
#include "file.h"
#include "algo.h"

void menu(void) 
{
	printf("Здесь будет меню.\n");
	puts("------------------------------");
	print_list(pstud, number);
	puts("------------------------------");
	//save_list(pstud, number);
	load_list(pstud, number);
	print_list(pstud, number);
	puts("------------------------------");
	sort_by_name(pstud, number);
	puts("------------------------------");
	print_list(pstud, number);
	puts("------------------------------");
	sort_by_grades(pstud, number);
	puts("------------------------------");
	print_list(pstud, number);
}

static void print_stud(Student *p) 
{
	size_t j;
	printf("%-*s", NAME_LEN, p->name);
	for (j = 0; j < GRADE_LEN; ++j)
		printf("%2d", p->grade[j]);
	printf("\n");
}

size_t print_list(Student *p, size_t n)
{
	size_t i;
	for (i = 0; i < n; ++i)
		print_stud(p + i);
	return n;
}

