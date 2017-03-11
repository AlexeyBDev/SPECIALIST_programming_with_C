#include <stdlib.h>
#include <string.h>
#include "data.h"
#include "algo.h"

static int namecmp(const void *e1, const void *e2)
{
	return strcmp((*(const Student *)e1).name, 
				  (*(const Student *)e2).name
	);
}

size_t sort_by_name(Student *p, size_t n)
{
	qsort(p, n, sizeof(Student), namecmp);

	return n;
}

static int gradescmp(const void *e1, const void *e2)
{
	int s1, s2;
	size_t j;
	for (s1 = s2 = 0, j = 0; j < GRADE_LEN; ++j)
	{
		s1 += ((const Student *)e1)->grade[j];
		s2 += ((const Student *)e2)->grade[j];
	}
	return -(s1-s2);
}

size_t sort_by_grades(Student *p, size_t n)
{
	qsort(p, n, sizeof(Student), gradescmp);

	return n;
}