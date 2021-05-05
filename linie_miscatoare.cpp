#include <cstdio>
#include <graphics.h>
using namespace std;

int main()
{
    int xmax=1800,ymax=800,x1=50,y1=50,x2,y2=ymax-50;
    initwindow(xmax,ymax);
    setbkcolor(WHITE);
    cleardevice();
    setcolor(BLUE);
    while(x1<xmax)
    {
        x2=x1;
        moveto(x1,y1);
        circle(x1,y1,50);
        lineto(x2,y2);
        circle(x2,y2,50);
        x1+=10;
        Sleep(100);
        cleardevice();
    }
    return 0;
}
