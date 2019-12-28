#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
using namespace std;
//#define debug 
const char head[9]="вСобсрио";
int i;
int main(){
	srand(time(0));
    HANDLE hout=GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos={30,18},ss={0,10},bb={0,0};
	int fx[4]={-2,0,2,0},fy[4]={0,1,0,-1},j=1,rn,rm,ln,lm;
	int k;
	printf("windows");
	scanf("%d",&k);
	if(k==10)rn=94,ln=0,rm=29,lm=0;
	else ln=0,rn=78,lm=0,rm=42;
	while(1){
		if(kbhit()){
			char cc=getch();
			switch(cc){
				case 'w':i=3;break;
				case 's':i=1;break;
				case 'a':i=0;break;
				case 'd':i=2;break;
				case ' ':system("cls");break;
			}
		}
#ifdef debug
		SetConsoleTextAttribute(hout,0x05+235);
		SetConsoleCursorPosition(hout,bb);
		printf("            ");
#endif
		SetConsoleTextAttribute(hout,0x10*j|0x07);
		SetConsoleCursorPosition(hout,pos);
		putchar(' ');
		putchar(' ');
		pos.X+=fx[i],pos.Y+=fy[i];
		if(pos.X>rn)pos.X=ln;
		if(pos.X<ln)pos.X=rn;
		if(pos.Y<lm)pos.Y=rm;
		if(pos.Y>rm)pos.Y=lm;
		SetConsoleCursorPosition(hout,pos);
		putchar(head[2*i]);
		putchar(head[2*i+1]);
#ifdef debug
		cout<<j;
		bb.X=pos.X;
		bb.Y=pos.Y-5;
		SetConsoleCursorPosition(hout,bb);
		printf("(%d,%d)",pos.X,pos.Y);
#endif
		Sleep(72);
		j=(j+1)%(0x10-1)+1;
	}
	return 0;
}
