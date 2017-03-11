#ifndef DATA_H
#define DATA_H

#define NAME_LEN		20
#define GRADE_LEN		3

typedef struct {
	char name[NAME_LEN];
	int grade[GRADE_LEN];		// оценка по предмету
} Student;

extern size_t   number;
extern Student *pstud;

#endif