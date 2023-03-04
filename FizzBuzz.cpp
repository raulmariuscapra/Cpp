#include<stdio.h>

int main()
{
	int n,i;
	printf("n=");
	scanf("%i",&n);
	for(i=1;i<=n;++i)
	{
		if(!(i%15))
		{
			printf("FizzBuzz\n");
		}
		else if(!(i%5))
		{
			printf("Buzz\n");
		}
		else if(!(i%3))
		{
			printf("Fizz\n");
		}
		else
		{
			printf("%i\n",i);
		}
	}
	return 0;
}