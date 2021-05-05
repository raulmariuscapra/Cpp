#include <cstdio>
#define inf 10000000
using namespace std;

struct matrice
{
    int ap,atr,n[50][50];
};

matrice citire(char nume_fisier[])
{
    FILE *f=fopen(nume_fisier,"r");
    int i,j,x;
    matrice s;
    fscanf(f,"%i",&s.ap);
    fscanf(f,"%i",&s.atr);
    for(i=0;i<s.ap;i++)
        for(j=0;j<s.atr;j++)
            fscanf(f,"%i",&s.n[i][j]);
    fclose(f);
    return s;
}

void rezolvare(matrice s)
{
    matrice r;
    int i,j,min=inf,minlocal;
    r.ap=s.ap;
    r.atr=s.atr;
    for(i=0;i<r.ap;i++)
    {
        for(j=0;j<r.atr;j++)
        {
            r.n[i][j]=inf;
        }
    }
    for(j=0;j<r.atr;j++)
    {
        for(i=0;i<r.ap;i++)
        {
            if(i>0 && r.n[i-1][j]!=inf)
            {
                r.n[i][j]=r.n[i-1][j]+1;
            }
            if(s.n[i][j]==1)
            {
                r.n[i][j]=0;
            }
        }
    }
    for(j=0;j<r.atr;j++)
    {
        for(i=r.ap-1;i>=0;i--)
        {
            if(i<r.ap-1 && r.n[i+1][j]<r.n[i][j])
            {
                r.n[i][j]=r.n[i+1][j]+1;
            }
        }
    }
    for(i=0;i<r.ap;i++)
    {
        minlocal=r.n[i][0];
        for(j=1;j<r.atr;j++)
            if(r.n[i][j]>minlocal)
                minlocal=r.n[i][j];
        if(min>minlocal)
            min=minlocal;
    }
    printf("Cele mai bune locuri de instalare sunt:");
    for(i=0;i<r.ap;i++)
    {
        minlocal=r.n[i][0];
        for(j=1;j<r.atr;j++)
            if(r.n[i][j]>minlocal)
                minlocal=r.n[i][j];
        if(min==minlocal)
            printf("%i ",i+1);
    }
    printf("\n");
}

int main()
{
    int i,j;
    matrice prob;
    prob=citire("apartamente.in");
    rezolvare(prob);
    return 0;
}
