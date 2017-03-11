#include "stud.h"

int inpstud(student *p);
void outstud(student *p, int ordernum);
void outtitle(void);
const char *getlimline(const wchar_t *tips, int maxlen);
int getlimint(const wchar_t *tips, int min, int max);

int input(student *p, int n)
{
	int k;
	fflush(stdin);
	for(k=n; k<NSTUD && inpstud(p+k); ++k);
	return k;
}

int output(student *p, int n)
{
	int k;
	outtitle();
	for(k=0; k<n; ++k,++p)
		outstud(p,k+1);
	printf("\n");
	return k;
}

void outtitle(void)
{
	char buf[MAXNAME+1];
	wprintf(L" %C %-*s %-*s %*s\n",'\xFC',MAXNAME,L"Ф.И.О.",4,L"Курс",6,L"Оценки");
	memset(buf,'-',MAXNAME);buf[MAXNAME]=0;
	printf("-- %.*s ",MAXNAME,buf);
	memset(buf,'-',4);buf[4]=0;
	printf("%.*s ",4,buf);
	memset(buf,'-',6);buf[6]=0;
	printf("%.*s\n",6,buf);
}

void outstud(student *p, int k)
{
	int i;
	printf("%2d %-*s %*d ",k,MAXNAME,p->name,4,p->year);
	for(i=0; i<MAXMARKS; ++i)
		printf("%2d",p->mark[i]);
	printf("\n");
}

int inpstud(student *p)
{
	int i;
    const char *str=getlimline(L"Ф.И.О.", MAXNAME);
	if(!*str) return 0;
	strcpy(p->name,str);
	
	p->year = getlimint(L"Курс", 1, 5);

	for(i=0; i<MAXMARKS; ++i)
	{
		wchar_t buf[32];
		swprintf(buf,L"Оценка[%d]",i+1);
		p->mark[i] = getlimint(buf, 2, 5);
	}
	fflush(stdin);
	return 1;
}

const char *getlimline(const wchar_t *tips, int maxlen)
{
	int i;
	static char buf[256];
	
	wprintf(L"%s (не более %d символов): ",tips,maxlen);
	fgets(buf,sizeof buf,stdin);
	i=(int)strlen(buf);
	if(maxlen<i) buf[maxlen]=0;
	else if(buf[i-1]=='\n') buf[--i]=0;
	return buf;
}

int getlimint(const wchar_t *tips, int min, int max)
{
	int ival,err=0;
	do
	{
		if(err)	{wprintf(L"\tОшибка!\n"); fflush(stdin);}
		wprintf(L"%s (%d-%d): ",tips, min, max );
	}while(err = scanf("%d",&ival)!=1 || ival<min || ival>max);
	return ival;
}
