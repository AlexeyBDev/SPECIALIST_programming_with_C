#include <stdlib.h>
#include <stdio.h>
#include "data.h"
#include "file.h"

static void save_stud(Student *p, FILE *out)
{
	size_t j;
	fprintf(out, "%-*s", NAME_LEN, p->name);
	for (j = 0; j < GRADE_LEN; ++j)
		fprintf(out, "%2d", p->grade[j]);
	fprintf(out, "\n");
}

size_t save_list(Student *p, size_t n)
{
	size_t i;
	FILE *out = fopen("student_list.txt", "wt");
	if (!out) { perror("student_list.txt"); exit(1); };

	for (i = 0; i < n; ++i)
		save_stud(p + i, out);
	fclose(out);
	return n;
}

static void load_stud(Student *p, FILE *inp)
{
	size_t j;
	fscanf(inp, "%s", p->name);
	for (j = 0; j < GRADE_LEN; ++j)
		//fscanf(inp, "%2d", &p->grade[j]);
		fscanf(inp, "%2d", p->grade + j);
	//fscanf(inp, "\n");
}

size_t load_list(Student *p, size_t n)
{
	size_t i;
	FILE *inp = fopen("student_list.txt", "rt");
	if (!inp) { perror("student_list.txt"); exit(1); };

	for (i = 0; i < n; ++i)
		load_stud(p + i, inp);
	fclose(inp);
	return n;
}
