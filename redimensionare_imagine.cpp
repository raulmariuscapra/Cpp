#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>

struct pixel
{
    int r,g,b;
};

struct imagine
{
    int h,w;
    pixel *mat;
};

imagine citire_imagine(char *nume_fisier,int &k)
{
	FILE *f=fopen(nume_fisier,"r");
    imagine imag;
    int i,j;
    fscanf(f,"%i%*c%i%*c",&imag.h,&k);
	imag.w=imag.h;
    imag.mat=(pixel*)malloc(imag.h*imag.w*sizeof(pixel));
    for(i=0;i<imag.h;++i)
    {
        for(j=0;j<imag.w;++j)
        {
            fscanf(f,"%i%*c%i%*c%i%*c",&imag.mat[i*imag.w+j].r,&imag.mat[i*imag.w+j].g,&imag.mat[i*imag.w+j].b);
        }
    }
	fclose(f);
    return imag;
}

void afisare_imagine(imagine imag)
{
    int i,j;
    for(i=0;i<imag.h;++i)
    {
        for(j=0;j<imag.w;++j)
        {
            printf("%3i %3i %3i ",imag.mat[i*imag.w+j].r,imag.mat[i*imag.w+j].g,imag.mat[i*imag.w+j].b);
        }
        printf("\n");
    }
}

pixel maxim(imagine imag,int sus,int stanga,int k)
{
	pixel max;
	max.r=0;
	max.g=0;
	max.b=0;
	int i,j;
	int jos=sus+k,dreapta=stanga+k;
	for(i=sus;i<jos;++i)
	{
		for(j=stanga;j<dreapta;++j)
		{
			if(max.r<imag.mat[i*imag.w+j].r)
			{
				max.r=imag.mat[i*imag.w+j].r;
			}
			if(max.g<imag.mat[i*imag.w+j].g)
			{
				max.g=imag.mat[i*imag.w+j].g;
			}
			if(max.b<imag.mat[i*imag.w+j].b)
			{
				max.b=imag.mat[i*imag.w+j].b;
			}
		}
	}
	return max;
}

imagine redimensionare_imagine(imagine imag,int k)
{
	imagine redimensionata;
	redimensionata.h=imag.h/k;
	redimensionata.w=imag.w/k;
	int i,j;
	redimensionata.mat=(pixel*)malloc(redimensionata.h*redimensionata.w*sizeof(pixel));
	for(i=0;i<redimensionata.h;++i)
	{
		for(j=0;j<redimensionata.w;++j)
		{
			redimensionata.mat[i*redimensionata.w+j] = maxim(imag,i*k,j*k,k);
		}
	}
	return redimensionata;
}

int main()
{
	imagine imag;
	int k;
    imag=citire_imagine((char*)"redimensionare_imagine.in",k);
    afisare_imagine(imag);
	afisare_imagine(redimensionare_imagine(imag,k));
    free(imag.mat);
	return 0;
}