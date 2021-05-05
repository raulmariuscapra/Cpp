#include <cstdio>
using namespace std;

int mutari=0;

void hanoi(int disc,char start,char finish, char intermediar)
{
    if(disc>1)
    {
        hanoi(disc-1,start,intermediar,finish);
    }
    mutari++;
    printf("%i:%c->%c\n",mutari,start,finish);
    if(disc>1)
    {
        hanoi(disc-1,intermediar,finish,start);
    }
}

int main()
{
    int numardiscuri;
    printf("Numarul de discuri=");
    scanf("%i",&numardiscuri);
    hanoi(numardiscuri,'A','B','C');
    return 0;
}
