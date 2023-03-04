#include<cstdio>
#include<stdlib.h>
#include<time.h>
#include<graphics.h>
using namespace std;

int xa,ya,xb,yb,xc,yc,xmax,ymax;

void GetDesktopResolution(int& horizontal, int& vertical)
{
   RECT desktop;
   // Get a handle to the desktop window
   const HWND hDesktop = GetDesktopWindow();
   // Get the size of screen to the variable desktop
   GetWindowRect(hDesktop, &desktop);
   // The top left corner will have coordinates (0,0)
   // and the bottom right corner will have coordinates
   // (horizontal, vertical)
   horizontal = desktop.right;
   vertical = desktop.bottom;
}

void setup_window()
{
    GetDesktopResolution(xmax,ymax);
    //se initializeaza desenul , se face backgroundul alb si se face culoarea de scris neagra
    initwindow(xmax,ymax);
    setbkcolor(BLACK);
    cleardevice();
    xa=xmax/2;
    ya=0;
    xb=0;
    yb=ymax;
    xc=xmax;
    yc=ymax;
    putpixel(xa,ya,WHITE);
    putpixel(xb,yb,WHITE);
    putpixel(xc,yc,WHITE);
}

void modul(int &x)
{
    if(x<0)
    {
        x=-x;
    }
}

bool inTriangle(int x,int y)
{
    int a1,a2,a3,a;
    a=xa*(yb-yc)+xb*(yc-ya)+xc*(ya-yb)/2;
    a1=x*(yb-yc)+xb*(yc-y)+xc*(y-yb)/2;
    a2=xa*(y-yc)+x*(yc-ya)+xc*(ya-y)/2;
    a3=xa*(yb-y)+xb*(y-ya)+x*(ya-yb)/2;
    modul(a);
    modul(a1);
    modul(a2);
    modul(a3);
    if(a==a1+a2+a3)
    {
        return true;
    }
    return false;
}

int main()
{
    setup_window();
    int x,y,unde;
    srand(time(NULL));
    do
    {
        x=rand()%xmax+1;
        y=rand()%ymax+1;
    }while(!inTriangle(x,y));
    putpixel(x,y,WHITE);
    while(!ismouseclick(WM_LBUTTONDOWN))
    {
        unde=rand()%3+1;
        if(unde==1)
        {
            x=(x+xa)/2;
            y=(y+ya)/2;
            putpixel(x,y,BLUE);
        }
        else if(unde==2)
        {
            x=(x+xb)/2;
            y=(y+yb)/2;
            putpixel(x,y,GREEN);
        }
        else
        {
            x=(x+xc)/2;
            y=(y+yc)/2;
            putpixel(x,y,RED);
        }
    }
    getmouseclick(WM_LBUTTONDOWN,x,y);
    closegraph();
    return 0;
}
