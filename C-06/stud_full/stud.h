#ifndef STUD_H
#define STUD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define NSTUD		15
#define MAXNAME		20
#define MAXMARKS	 3

typedef struct
{
	char name[MAXNAME+1];
	int year;
	int mark[MAXMARKS];
}student;

typedef struct
{
	const wchar_t * txt;
	int (* cmd)(student *, int);
}menu_item;

void init(void);
int input(student *, int);
int load(student *, int);
int sortname(student *, int);
int sortyear(student *, int);
int sortmark(student *, int);
int output(student *, int);
int save(student *, int);

void menu(const menu_item *, int);

#endif