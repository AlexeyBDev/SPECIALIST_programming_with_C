#include<stdio.h>
#include<conio.h>
#include<windows.h>
void gotoxy(int x,int y)
{
	COORD c={x,y};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
main()
{
	int key,dx=1,dy=0;
	int m[2][100],l=5,i;//l- tekuchi razmer zmei//
m[0][0]=40;m[1][0]=12;
m[0][1]=39;m[1][1]=12;
m[0][2]=38;m[1][2]=12;
m[0][3]=37;m[1][3]=12;
m[0][4]=36;m[1][4]=12;
while(1)
{
	gotoxy( m[0][0],m[1][0]);
	putchar(1);
	for(i=1;i<l;i++)
	{gotoxy( m[0][i],m[1][i]);
	putchar('o');
	}
if(kbhit()!=0)
{
	key=getch();
	if(key==27)break;
	if(key==0) key=getch();
	if(key==75){dy=0;dx=-1;}
	if(key==77){dy=0;dx=1;}
    if(key==72){dy=-1;dx=0;}
	if(key==80){dy=1;dx=0;}
}gotoxy(m[0][l-1],m[1][l-1]);
putchar(' ');
for(i=l-1;i>0;i--)
{m[0][i]=m[0][i-1];
m[1][i]=m[1][i-1];
}
m[0][0]+=dx;m[1][0]+=dy;
Sleep(100);

}


}