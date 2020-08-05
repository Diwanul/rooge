#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
using namespace std;
//#define debug
HANDLE hout=GetStdHandle(STD_OUTPUT_HANDLE);
struct diep{
    COORD wz;
    int hp,fx;
    bool zj,used,f;
}zj,dr[1000000];
struct _zd{
    int fx;
    COORD wz;
    bool used,zj;
    _zd(int f,COORD x,bool zzj){fx=f,wz=x,used=0,zj=zzj;}
    _zd(){};
}zd[100000000];
const bool tx[2][3][3]={{{0,1,1},{1,1,0},{0,1,1}},{{0,1,1},{1,1,1},{0,1,1}}};
const int nx=88,ny=44,color[2]={0x33,0xaa};
int ti=0,dto,zto;
bool pd1(COORD a,COORD b){
    return abs(a.X-b.X)<3&&abs(a.Y-b.Y)<2;
}
bool pd2(COORD a,COORD b,bool c){
    return c?abs(a.X-b.X)<2:abs(a.Y-b.Y)<2;
}
bool pd3(COORD a,COORD b){
    return abs(a.X-b.X)<5&&abs(a.Y-b.Y)<3;
}
void hpp(){
    COORD ls;
    ls.X=nx+2;
    ls.Y=1;
    SetConsoleCursorPosition(hout,ls);
    SetConsoleTextAttribute(hout,0x34);
    printf("hp:%d/5",zj.hp);
    for(register int i=0;i<5;i++){
        if(i<zj.hp)SetConsoleTextAttribute(hout,0x44);
        else SetConsoleTextAttribute(hout,0x88);
        cout<<"  ";
    }
}
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
void sc(diep x){
    bool lss[3][3];
    xz(lss,x.fx,x.zj);
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
void js(){
    const char s[9]="You died";
    SetConsoleTextAttribute(hout,0x0f);
    system("cls");
    COORD ls={44,22};
    SetConsoleCursorPosition(hout,ls);
    SetConsoleCursorPosition(hout,ls);
    int dt=8;
    while(dt--){
        while(kbhit())getch();
        putchar(s[7-dt]);
        ls.X++;
        SetConsoleCursorPosition(hout,ls); 
        Sleep(500);
    }
    puts("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    getch();
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
#ifdef debug
    if(dto)return;
#endif
    dr[dto].hp=2;
    dr[dto].zj=0;
    dr[dto].fx=rand()%4;
    dr[dto].wz.X=rand()%42*2+2;
    dr[dto].wz.Y=rand()%42+1;
    ++dto;
    sc(dr[dto-1]);
}
void move(diep &x,int fx){
    clear(x.wz);
    diep xx=x;
    if(x.fx!=fx)x.fx=fx;
    switch(fx){
        case 0:if(x.wz.Y>2)x.wz.Y--;break;
        case 3:if(x.wz.X<nx-6)x.wz.X+=2;break;
        case 2:if(x.wz.Y<ny-2)x.wz.Y++;break;
        case 1:if(x.wz.X>4)x.wz.X-=2;break;
    }
    bool bbb=0;
    if(!x.zj)bbb=pd3(x.wz,zj.wz);
    for(register int i=0;i<dto;i++)
        if((x.wz.X!=dr[i].wz.X||x.wz.Y!=dr[i].wz.Y)&&pd3(x.wz,dr[i].wz))
            bbb=1;
    if(bbb)x.wz=xx.wz;
    sc(x);
}
void fzd(diep x){
    COORD wz;
    switch(x.fx){
        case 1:wz.X=x.wz.X-2,wz.Y=x.wz.Y;break;
        case 0:wz.X=x.wz.X,wz.Y=x.wz.Y-1;break;
        case 3:wz.X=x.wz.X+2,wz.Y=x.wz.Y;break;
        case 2:wz.X=x.wz.X,wz.Y=x.wz.Y+1;break;
    }
    if(!x.f)zd[zto++]=_zd(x.fx,wz,x.zj);
}
void pdr(int xx){
    if(pd2(dr[xx].wz,zj.wz,1)&&(dr[xx].fx==0&&dr[xx].wz.Y>=zj.wz.Y||dr[xx].fx==2&&dr[xx].wz.Y<=zj.wz.Y)||pd2(dr[xx].wz,zj.wz,0)&&(dr[xx].fx==1&&dr[xx].wz.X>=zj.wz.X)||(dr[xx].fx==3&&dr[xx].wz.X<=zj.wz.X))fzd(dr[xx]);
    else if(pd2(dr[xx].wz,zj.wz,1)&&dr[xx].wz.Y>zj.wz.Y&&dr[xx].fx||dr[xx].wz.Y>zj.wz.Y&&abs(dr[xx].wz.Y-zj.wz.Y)<=abs(dr[xx].wz.X-zj.wz.X))move(dr[xx],0);
    else if(pd2(dr[xx].wz,zj.wz,0)&&dr[xx].wz.X>zj.wz.X&&dr[xx].fx!=1||dr[xx].wz.X>zj.wz.X&&abs(dr[xx].wz.X-zj.wz.X)<=abs(dr[xx].wz.Y-zj.wz.Y))move(dr[xx],1);
    else if(pd2(dr[xx].wz,zj.wz,1)&&dr[xx].wz.Y<zj.wz.Y&&dr[xx].fx!=2||dr[xx].wz.Y<zj.wz.Y&&abs(dr[xx].wz.Y-zj.wz.Y)<=abs(dr[xx].wz.X-zj.wz.X))move(dr[xx],2);
    else move(dr[xx],3);
    dr[xx].f=!dr[xx].f;
}
void pzd(int xx){
    bool bb=0;
    bb|=pd1(zd[xx].wz,zj.wz);
    for(register int i=0;i<dto;i++)
        bb|=!dr[i].used&pd1(zd[xx].wz,dr[i].wz);
    if(!bb){
        SetConsoleTextAttribute(hout,0x60);
        SetConsoleCursorPosition(hout,zd[xx].wz);
        printf("  ");
    }
    switch(zd[xx].fx){
        case 1:zd[xx].wz.X-=2;break;
        case 0:zd[xx].wz.Y--;break;
        case 3:zd[xx].wz.X+=2;break;
        case 2:zd[xx].wz.Y++;break;
    }
    if(pd1(zd[xx].wz,zj.wz))zd[xx].used=1,zj.hp--,zj.used=(zj.hp<=0),hpp();
    if(zj.used)js();
    if(!zd[xx].used)
        for(register int i=0;i<dto;i++)
            if(!dr[i].used&&pd1(zd[xx].wz,dr[i].wz)){
                zd[xx].used=1,dr[i].hp--,dr[i].used=(dr[i].hp<=0);
                if(dr[i].used)clear(dr[i].wz);
                break;
            }
    if(!zd[xx].used)
        for(register int i=0;i<zto;i++)
            if(i!=xx&&!zd[i].used&&zd[xx].wz.X==zd[i].wz.X&&zd[xx].wz.Y==zd[i].wz.Y){
                zd[xx].used=1,zd[i].used=1;
                break;
            }
    if(zd[xx].wz.X>=nx||zd[xx].wz.Y>=ny||zd[xx].wz.Y<=0||zd[xx].wz.X<=0)zd[xx].used=1;
    if(!zd[xx].used){
        SetConsoleTextAttribute(hout,zd[xx].zj?0xa0:0xf0);
        SetConsoleCursorPosition(hout,zd[xx].wz);
        printf("  ");
    }
}
int main(){
    srand(time(0));
#ifdef debug
    printf("本版本为调试版\n若想玩基础开源版\n请打开源代码并在第⑤行前加上“//”\n然后编译运行\n若想玩完整版，请联系开发人员\n\n\n仅供OIer娱乐\n\n\n\n\t\t\t\t-------by Diwanul\n");
#endif
#ifndef debug
    printf("按任意键开始"); 
#endif
    getch();
    system("cls");
    zj.zj=1;
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
    zj.wz.Y=rand()%42+1;zj.wz.X=rand()%42*2+2;
    zj.hp=5;
    sc(zj);
    hpp();
    while(1){
        if(kbhit()){
            char c=getch();
            switch(c){
                case 'w':move(zj,0);break;
                case 's':move(zj,2);break;
                case 'a':move(zj,1);break;
                case 'd':move(zj,3);break;
                case ' ':fzd(zj);break;
                case 'p':getch();break;
            }
        }
        for(register int i=0;i<dto;i++)
            if(!dr[i].used)
                pdr(i);
#ifdef debug
        COORD ls;
        ls.X=nx+2,ls.Y=2;
        SetConsoleCursorPosition(hout,ls);
        SetConsoleTextAttribute(hout,0xde);
        printf("(%d,%d)%d %d",zj.wz.X,zj.wz.Y,zj.fx,zj.hp);
        ls.Y++;
        SetConsoleCursorPosition(hout,ls);
        printf("(%d,%d)%d %d",dr[0].wz.X,dr[0].wz.Y,dr[0].fx,dr[0].hp);ls.Y++;
        SetConsoleCursorPosition(hout,ls);
        printf("(%d %d)%d",zd[0].wz.X,zd[0].wz.Y,zd[0].fx);
#endif
        for(register int i=0;i<zto;i++)
            if(!zd[i].used){
                pzd(i);
                if(zj.used)break;
            }
#ifdef debug
        ls.X=nx+2,ls.Y++;
        SetConsoleCursorPosition(hout,ls);
        SetConsoleTextAttribute(hout,0xde);
        printf("(%d,%d)%d %d",zj.wz.X,zj.wz.Y,zj.fx,zj.hp);ls.Y++;
        SetConsoleCursorPosition(hout,ls);
        printf("(%d,%d)%d %d",dr[0].wz.X,dr[0].wz.Y,dr[0].fx,dr[0].hp);ls.Y++;
        SetConsoleCursorPosition(hout,ls);
        printf("(%d %d)%d",zd[0].wz.X,zd[0].wz.Y,zd[0].fx);
#endif
        if(zj.used)break;
        if(!(ti%30))add();
        ++ti;
        Sleep(200);
    }
    return 0;
}
