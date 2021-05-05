#include<cstdio>
using namespace std;

int i=-1;
int s(int t)
{
    i++;
    if(t==1)
        return 0;
    if(t==2)
        return 1;
    return s(t-2)+s(t-1);
}

int main()
{
    s(6);
    printf("%i",i);
}
