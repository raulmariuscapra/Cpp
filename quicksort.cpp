#include <cstdio>
#include <graphics.h>
using namespace std;
struct vector
{
    int n,v[50];
};

int xmax=600,ymax=600;
int tmp[500];

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
    fclose(f);
    return a;
}

void QuickSort(vector &a, int st, int dr)
{
	if(st < dr)
	{
		//pivotul este inițial a.v[st]
		int m = (st + dr) / 2;
		int aux = a.v[st];
		a.v[st] = a.v[m];
		a.v[m] = aux;
		int i = st , j = dr, d = 0;
		while(i < j)
		{
			if(a.v[i] > a.v[j])
			{
				aux = a.v[i];
				a.v[i] = a.v[j];
				a.v[j] = aux;
				d = 1 - d;
			}
			i += d;
			j -= 1 - d;
		}
		QuickSort(a, st , i - 1);
		QuickSort(a, i + 1 , dr);
	}
}

void MergeSort(vector &a, int st, int dr)
{
	if(st < dr)
	{
		int m = (st + dr) / 2;
		MergeSort(a, st , m);
		MergeSort(a, m + 1 , dr);
		//Interclasare
		int i = st, j = m + 1, k = 0;
		while( i <= m && j <= dr )
			if( a.v[i] < a.v[j])
				tmp[++k] = a.v[i++];
			else
				tmp[++k] = a.v[j++];
		while(i <= m)
			tmp[++k] = a.v[i++];
		while(j <= dr)
			tmp[++k] = a.v[j++];
		for(i = st ; i <= dr ; i ++)
			a.v[i] = tmp[i];
	}
}

void afisare(vector a)
{
    int i;
    for(i=0;i<a.n;i++)
    {
        printf("%3i ",a.v[i]);
    }
    printf("\n");
}

int main()
{
    vector a;
    a=citire((char*)"vector.in");
    afisare(a);
    QuickSort(a,0,a.n-1);
    afisare(a);
    return 0;
}
