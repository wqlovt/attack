/*
 ============================================================================
 Name        : aa.c
 Author      : LOVT
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int a = 10, b;

//1-（求和 k = 0到z）（lambda的K次）e（-lambda）（1-（q/p）(z-k)次方）/k！
double AttackerSuccessProbability(double q, int z)
{
	double p = 1.0 - q;
	double lambda = z * (q/p);
	double sum = 1.0;
	int i, k;

	for(k = 0; k < z; k ++)
	{
		double poisson = exp(-lambda);
		for(i = 1; i < k; i ++)
		{
			poisson *= lambda / i;
		}
		sum -= poisson * (1 - pow(q/p, z - k));
	}
	return sum;
}

int main(void) {
	double q = 0.3;
	int i;

	for(i = 1; i < 50; i ++)
	{
		printf("%f", AttackerSuccessProbability(q, i));
		printf("\n");
	}
	return EXIT_SUCCESS;
}


