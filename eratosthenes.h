#ifndef _ERATOSTHENES_H_
#define _ERATOSTHENES_H_

#include<stdio.h>
#include<stdlib.h>

struct intList
{
        int len;
        int *list;
};


struct primeComplement
{
	struct intList *primes;
	struct intList *nonPrimes;
};

struct intList *primeSieve(int n);

struct primeComplement *extendedPrimeSieve(int n);

void freeIntList(struct intList *l);

void freePrimeComplements(struct primeComplement *c);

#endif
