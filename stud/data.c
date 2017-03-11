#include <stdlib.h>
#include "data.h"

static Student list[10] /*=
{
	{"Сидоров", {4, 4, 5} },
	{ "Петров", {5, 5, 5} },
	{ "Иванов", {4, 3, 5} },
}*/;

//size_t   number = sizeof list / sizeof *list;
size_t   number = 7;
Student *pstud = list;