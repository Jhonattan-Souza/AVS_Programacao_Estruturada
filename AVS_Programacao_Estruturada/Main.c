#include <stdio.h>

int fatorial(int num);
int fibonacci(int num);
int ehPrimo(int num);

int main()
{
}

int fatorial(int num)
{
	return num * fatorial(num-1);
}

int fibonacci(int num)
{
	if(num == 1 || num ==2) return 1;
	else return fibonacci(num-1)+fibonacci(num-2);
}

int ehPrimo(int num)
{
	if (num<2) return 0;

	for (int i = (int)num / 2; i >= 2; i--)
		if ((num%i) == 0) return 0;
	
	return 1;
}