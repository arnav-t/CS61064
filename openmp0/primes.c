#include <stdio.h>
#include <omp.h>
#include <math.h>

int isPrime(long n)
{
	for(int i=2;i<=sqrt(n);++i)
		if(n%i == 0)
			return 0;
	return 1;
}

int main()
{
	// Serial	
	printf("Serial implementation:\n");	
	float startTime = omp_get_wtime();
	long numPrimes = 0;
	for(long i=2; i<131072; ++i)
	{
		if(isPrime(i))
			numPrimes += 1;
	}
	printf("Primes found: %ld\nSerial Execution time: %f\n", 
			numPrimes, omp_get_wtime() - startTime);
	
	// Parallel
	printf("\nParallel implementation:\n");		
	startTime = omp_get_wtime();
	numPrimes = 0;
	long i = 2;
	#pragma omp parallel
	{
		while(i < 131072)
		{
			if(isPrime(i))
				numPrimes += 1;
			i += 1;
		}
	}
	printf("Primes found: %ld\nParallel Execution time: %f\n", 
			numPrimes, omp_get_wtime() - startTime);
	return 0;
}
