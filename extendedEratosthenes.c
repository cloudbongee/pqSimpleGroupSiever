
#include "eratosthenes.h" 


// The extended prime sieve throws out two lists corresponding to primes and non primes
struct primeComplement *extendedPrimeSieve(int n)
{


	int *sieve = calloc(n+1,sizeof(int));
	int p = 2;
	while((p * p) <= n)
	{
		if(sieve[p] == 0)
		{
			for(int i = p * p; i < (n + 1); i+=p)
			{
				sieve[i] = 1;
			}
		}
		p+=1;
	}

	
	// count the primes
	int countPrimes = 0;
	for(p = 2; p < (n+1); p++)
	{
		if(sieve[p] == 0)
		{
			countPrimes++;
		}
	}

	
	int *list = malloc(sizeof(int) * (countPrimes));
	if(list == NULL)
	{
		fprintf(stderr, "Memory error\n");
		exit(1);
	}	

	int *nonPrimeList = malloc(sizeof(int) * (n - countPrimes - 1));
	int index = 0;
	int indexNonPrime = 0;
	for(p = 2; p < (n+1); p++)
	{
		if(sieve[p] == 0)
		{
			list[index] = p;
			index++;	
		}
		else
		{	
			nonPrimeList[indexNonPrime] = p;
			indexNonPrime++;	
		}
	}

	free(sieve);
	
	struct intList *primes = malloc(sizeof(struct intList));
	if(primes == NULL)
	{
		fprintf(stderr, "Memory error\n");
		exit(1);
	}

	struct intList *nonPrimes = malloc(sizeof(struct intList));
	if(nonPrimes == NULL)
	{
		fprintf(stderr, "Memory error\n");
		exit(1);
	}

	struct primeComplement *result = malloc(sizeof(struct primeComplement));
	if(result == NULL)
	{
		fprintf(stderr, "Memory error\n");
		exit(1);
	}

	primes->len = countPrimes;
	primes->list = list;

	nonPrimes->len = n - countPrimes - 1;
	nonPrimes->list = nonPrimeList;

	
	result->primes = primes;
	result->nonPrimes = nonPrimes;
	
	return result;

}

void freePrimeComplements(struct primeComplement *c)
{
	freeIntList(c->primes);
	freeIntList(c->nonPrimes);
	free(c);
}

