#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
using namespace std;
#define debug
HANDLE hout=GetStdHandle(STD_OUTPUT_HANDLE);
struct deep{
	COORD wz;
	int hp,fx;
	bool zj;
}zj,dr[100];
struct _zd{
	int fx;
	COORD wz;
};
vector<_zd> zd;
const bool tx[2][3][3]={{{0,1,1},{1,1,1},{0,1,1}},{{0,1,1},{1,1,0},{0,1,1}}};
const int nx=44,ny=22,color[4]={0x36,0xa6,0x56,0xd6};
int ti=0,dto,zto;
void xz(bool t[3][3],int fx,bool r){
	for(register int i=0;i<3;i++)
		for(register int j=0;j<3;j++)
			t[i][j]=tx[r][i][j];
	while(fx){
		bool b[3][3];
		for(register int i=0;i<3;i++)
			for(register int j=0;j<3;j++)
				b[j][3-1-i]=t[i][j];
		for(register int i=0;i<3;i++)
			for(register int j=0;j<3;j++)
				t[i][j]=b[i][j];
		fx--;
	}
}
void clear(COORD x){
	SetConsoleTextAttribute(hout,0x60);
	for(register int i=0;i<6;i+=2)
		for(register int j=0;j<3;j++){
			COORD ls;
			ls.X=x.X-2+i;
			ls.Y=x.Y-1+j;
    		SetConsoleCursorPosition(hout,ls);
			printf("  ");
		}
}
void add(){
	dr[dto].hp=2;
	dr[dto].zj=0;
	dr[dto].fx=3;
	++dto;
}
void move(deep &x,int fx){
	clear(x.wz);
	if(x.fx!=fx)x.fx=fx;
	switch(fx){
		case 0:if(x.wz.Y>2)x.wz.Y--;break;
		case 3:if(x.wz.X<nx-6)x.wz.X+=2;break;
		case 2:if(x.wz.Y<ny-2)x.wz.Y++;break;
		case 1:if(x.wz.X>4)x.wz.X-=2;break;
	}
	bool lss[3][3];
	xz(lss,fx,x.zj);
	for(register int i=0;i<6;i+=2)
		for(register int j=0;j<3;j++){
			COORD ls;
			ls.X=x.wz.X-2+i;
			ls.Y=x.wz.Y-1+j;
    		SetConsoleCursorPosition(hout,ls);
			if(lss[i/2][j])SetConsoleTextAttribute(hout,color[x.zj]);
			else SetConsoleTextAttribute(hout,0x60);
			printf("  ");
		}
}
void fzd(deep x){
	COORD wz;
	switch(zj.fx){
		case 0:wz.;break;
	}
}
int main(){
	srand(time(0));
#ifdef debug
	printf("本版本为调试版\n若想玩基础开源版\n请用写字板或记事本打开\n并在第⑤行前加上“//”\n若想玩完整版，请联系开发人员\n");
#endif
	printf("按任意键以开始");
	getch();
	zj.zj=0;
	SetConsoleTextAttribute(hout,0x60);
	for(register int i=0;i<nx;i+=2)
		for(register int j=0;j<ny;j++){
			COORD ls;
			ls.X=i;
			ls.Y=j;
    		SetConsoleCursorPosition(hout,ls);
			printf("  ");
		}
	for(register int j=0;j<nx;j+=2){
    	COORD ls;
    	ls.X=j;
    	ls.Y=ny;
    	SetConsoleCursorPosition(hout,ls);
    	cout<<"一";
	}
    for(register int i=0;i<ny+1;i++){
    	COORD ls;
    	ls.X=nx;
    	ls.Y=i;
    	SetConsoleCursorPosition(hout,ls);
    	cout<<'|';
	}
	zj.wz.X=ny,zj.wz.X=5;
	while(1){
		if(kbhit){
			char c=getch();
			switch(c){
				case 'w':move(zj,0);break;
				case 's':move(zj,2);break;
				case 'a':move(zj,1);break;
				case 'd':move(zj,3);break;
				case ' ':fzd(zj);break;
			}
		}
		if(!(rand()%10))add();
		++ti;
	}
	return 0;
}
