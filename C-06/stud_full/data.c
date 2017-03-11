#include "stud.h"

student *astud;
int nstud;

static
student a[NSTUD]={	{"Ivanov K.", 2, {4,4,5}},
				{"Konovalov I.", 1, {5,4,5}},
				{"Kim B.", 1, {3,4,5}}
			 };

void init(void)
{
	astud=a;
	nstud=3;
}