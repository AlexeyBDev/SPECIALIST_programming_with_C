#include "stud.h"

//���������� �� �������
static int namecmp(const void *p, const void *q)
{
	return strcmp(((student *)p)->name,((student *)q)->name);
}

int sortname(student *p, int n)
{
	qsort(p,n,sizeof(student),namecmp);
	wprintf(L"��������� ������������� %d\n",n);
	return n;
}

//���������� �� ���� ��������
static int yearcmp(const void *p, const void *q)
{
	return ((student *)p)->year - ((student *)q)->year;
}

int sortyear(student *p, int n)
{
	qsort(p,n,sizeof(student),yearcmp);
	wprintf(L"��������� ������������� %d\n",n);
	return n;
}

//���������� �� �������� ����� (����� ������)
static int markcmp(const void *p, const void *q)
{
	int i, a=0, b=0;
	for(i=0; i<MAXMARKS; ++i)
	{
		a+=((student *)p)->mark[i];
		b+=((student *)q)->mark[i];
	}
	return b-a;
}

int sortmark(student *p, int n)
{
	qsort(p,n,sizeof(student),markcmp);
	wprintf(L"��������� ������������� %d\n",n);
	return n;
}
