
#include "indexSieve.h"

int fact(int n)
{
	if(n == 1)
	{
		return n;
	}

	return n * fact(n-1);
}

int indexSieve(int G, int H)
{
	return (fact((int)(G/H))%G != 0);	
}

int main(int argc, char *argv[])
{
	if(argc!=3)
	{
		fprintf(stderr ,"Usage: indexSieve [G-size] [H-size]\n");
		return 1;
	}

	int G = atoi(argv[1]);
	int H = atoi(argv[2]);


	if(G <= 2 && H <= 2)
	{
		fprintf(stderr, "Incorrect arguments, too small \n");
		return 1;
	}

	if(G%H!=0)
	{
		fprintf(stderr, "Input violates lagrange's theorem\n");
		return 1;
	}

	if(indexSieve(G,H) == 1)
	{
		printf("H contains a (non-trivial) normal subgroup\n");
	}
	
	return 0;
}
