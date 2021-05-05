#include <cstdio>
#include <graphics.h>
using namespace std;
struct vector
{
    int n,v[50];
};

int xmax=600,ymax=600;

vector citire(char file[])
{
    int i;
    vector a;
    FILE *f=fopen(file,"r");
    fscanf(f,"%i",&a.n);
    for(i=0;i<a.n;i++)
    {
        fscanf(f,"%i",&a.v[i]);
    }
    return a;
}

void draw(vector a,int width,int turn)
{
    cleardevice();
    int i,j=0;
    for(i=0;j<a.n;i=i+width)
    {
        rectangle(i,xmax/a.v[j],i+width,xmax);
        if(j==turn)
        {
            setcolor(GREEN);
            circle(i+width/2,(xmax/a.v[j])/2,10);
            setcolor(RED);
            circle(i+width+width/2,(xmax/a.v[j+1])/2,10);
            setcolor(BLACK);
        }
        j++;
    }
    Sleep(1000);
}

vector bubblesort(vector a)
{
    int width=xmax/a.n-1;
    int i,j,r,h;
    for(i=0;i<a.n;i++)
    {
        for(j=0;j<a.n-i-1;j++)
        {
            draw(a,width,j);
            if(a.v[j]>a.v[j+1])
            {
                r=a.v[j];
                a.v[j]=a.v[j+1];
                a.v[j+1]=r;
            }
        }
    }
}

int main()
{
    initwindow(xmax,ymax);
    setbkcolor(WHITE);
    cleardevice();
    setcolor(BLACK);
    vector a;
    a=citire("vector.in");
    a=bubblesort(a);
    return 0;
}
