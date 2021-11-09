#include<cstdio>//gikmqstvwxyz
#include<string.h>
using namespace std;

char a[99999][9999];
int numar=0;

void citire(char nume_fisier[])
{
    FILE *f=fopen(nume_fisier,"r");
    while(!feof(f))
        fscanf(f,"%s",a[numar++]);
    numar--;
    int i;
    fclose(f);
}

void biggest()
{
    char h[9999];
    h[0]=NULL;
    bool gasit;
    int i,j;
    for(i=0;i<numar;i++)
    {
        gasit=false;
        for(j=0;j<strlen(a[i])&&!gasit;j++)
            if(strchr("gikmqstvwxyz",a[i][j]))
            {
                gasit=true;
            }
        if(!gasit && strlen(a[i])>strlen(h))
        {
            strcpy(h,a[i]);
        }
    }
    printf("%s",h);
}

int main()
{
    citire("7linedisplay.in");
    biggest();
    return 0;
}
