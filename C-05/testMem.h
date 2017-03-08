#ifndef TEST_MEM_BUB
#define TEST_MEM_BUB

#define TEST_VAR 140

int d = 50;


int staticVarF()
{
	static int i = 0;
	int j = 0;
	if(i == 0) printf("static i |   j  \n");
	printf("%d        | %d\n", i, j);
	i++;
	j++;
}

#endif

