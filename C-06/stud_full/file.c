#include "stud.h"

int load(student *p, int n)
{
	FILE *file=fopen("students.dat", "rb");
	if(!file) perror("students.dat");
	else
	{
		fread(&n,sizeof(int),1,file);
		fread(p,sizeof(student),n,file);
		wprintf(L"Студентов считано %d\n",n);
	}
	return n;
}

int save(student *p, int n)
{
	FILE *file=fopen("students.dat", "wb");
	if(!file) {perror("students.dat"); exit(1);}
	fwrite(&n,sizeof(int),1,file);
	fwrite(p,sizeof(student),n,file);
	wprintf(L"Студентов записано %d\n",n);
	return n;
}
