#include <cstdio>
#include <graphics.h>
#include <math.h>
using namespace std;
struct coor
{
    double x,y;
};

coor coordonatele(float o,float r,float adaugx,float adaugy)
{
    //se calc coordonatele punctului cel mai de jos al unui pendul/
    coor c;
    c.x=adaugx+r*sin(o);
    c.y=adaugy+r*cos(o);
    return c;
}

void updateacc(float a1,float a2,float &v1,float &v2,float g,float m1,float m2,float &o1,float &o2,float r1,float r2)
{
    //aici se calculeaza acceleratia velocitatea si unghiul urmator(o formula)/
    float num1=-g*(2*m1+m2)*sin(o1),num2=-m2*g*sin(o1-2*o2),num3=-2*sin(o1-o2)*m2,num4=(v2*v2*r2+v1*v1*r1*cos(o1-o2)),jos=r1*(2*m1+m2-m2*cos(2*o1-2*o2));
    a1=(num1+num2+num3*num4)/jos;
    num1=2*sin(o1-o2);
    num2=v1*v1*r1*(m1+m2);
    num3=g*(m1+m2)*cos(o1);
    num4=v2*v2*r2*m2*cos(o1-o2);
    jos=r2*(2*m1+m2-m2*cos(2*o1-2*o2));
    a2=(num1*(num2+num3+num4))/jos;
    v1+=a1;
    v2+=a2;
    o1+=v1;
    o2+=v2;
    v1*=0.999;
    v2*=0.999;
}

void draw(float x1,float x2,float y1,float y2,float cx,float cy)
{
    //se deseneaza pendulul/
    moveto(cx,cy);
    lineto(x1,y1);
    circle(x1,y1,15);
    lineto(x2,y2);
    circle(x2,y2,15);
    Sleep(30);
    cleardevice();
}

int main()
{
    int xmax=600,ymax=600;
    float pi=2*acos(0.0);
    //m-masa,o-unghi de inclinare,r-lungimea pendulului,v-velocitatea,a-acceleratia,cx,cy- centrul/
    float m1=10,m2=10,o1=0,o2=0,r1=100,r2=100,g=1,v1=0.1,v2=0.1,a1,a2,cx=xmax/2,cy=200;
    coor c1,c2;
    initwindow(xmax,ymax);
    setbkcolor(WHITE);
    cleardevice();
    setcolor(BLUE);
    while(true)
    {
        c1=coordonatele(o1,r1,cx,cy);
        c2=coordonatele(o2,r2,c1.x,c1.y);
        draw(c1.x,c2.x,c1.y,c2.y,cx,cy);
        updateacc(a1,a2,v1,v2,g,m1,m2,o1,o2,r1,r2);
    }
    return 0;
}
