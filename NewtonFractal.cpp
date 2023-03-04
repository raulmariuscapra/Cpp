#include<cstdio>
#include<graphics.h>
#include<cmath>
#define TAU 6.283185307

class complex
{
public:
    float real,imag;
    complex(float a=0,float b=0)
    {
        real=a;
        imag=b;
    }
    complex operator+(complex const &x)
    {
        complex y;
        y.real=real+x.real;
        y.imag=imag+x.imag;
        return y;
    }
    complex operator-(complex const &x)
    {
        complex y;
        y.real=real-x.real;
        y.imag=imag-x.imag;
        return y;
    }
    complex operator*(complex const &x)
    {
        complex y;
        y.real=real*x.real-imag*x.imag;
        y.imag=imag*x.real+x.imag*real;
        return y;
    }
    complex operator/(complex const &x)
    {
        complex y;
        y.real=(real*x.real+imag*x.imag)/(x.real*x.real+x.imag*x.imag);
        y.imag=(+imag*x.real-x.imag*real)/(x.real*x.real+x.imag*x.imag);
        return y;
    }

};

float abs(complex x)
{
    return sqrt(x.real*x.real+x.imag*x.imag);
}

float arg(complex z)
{
	return atan2(z.imag,z.real);
}


complex power(complex x,int n)
{
    int i;
    complex x1=complex(1.0,0);
    for(i=0;i<n;i++)
    {
        x1=x1*x;
    }
    return x1;
}

complex f(complex x)
{
    return power(x,3)-complex(1.0,0);
}

complex df(complex x)
{
    return power(x,2)*complex(3.0,0);
}

int main()
{
    int i,j,k,maxiterations=100,shift=5,xmax=1600,ymax=800;
    float tol=0.0001;
    complex z;
    initwindow(xmax,ymax);
    setbkcolor(BLACK);
    cleardevice();
    for(i=0;i<800;i++)
    {
        for(j=0;j<800;j++)
        {
            z = complex((i-400.0)/266.6,(400.0-j)/266.6);
            for(k=0;k<maxiterations;k++)
            {
                if(abs(f(z))<tol)
                {
                    break;
                }
                z=z-(f(z)/df(z));
            }
            if(k!=maxiterations)
			{
				putpixel(i,j,1+(k+shift)%14);
				putpixel(i+800,j,1+int(shift+tol+(arg(z)*14/TAU+8))%14);
			}
        }
    }
    getch();
    closegraph();
    return 0;
}
