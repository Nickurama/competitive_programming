#include <iostream>
#include <bits/stdc++.h>

#define INF 1e11
 
long long algorithm(int num_months, long long *cost, long long *happiness, long long salary)
{
	long long total_happiness = 0;
	for (int i = 0; i < num_months; i++)
		total_happiness += happiness[i];
	long long memoization[num_months][total_happiness + 1];

	// first month
	for (int h = 0; h <= total_happiness; h++)
		memoization[0][h] = INF;
	if (cost[0] == 0)
		memoization[0][happiness[0]] = 0;
	else
		memoization[0][0] = 0;

	// all other months
	for (int m = 1; m < num_months; m++)
	{
		for (long long h = 0; h <= total_happiness; h++)
		{
			long long curr_money = salary * m;

			long long previous_cost = INF;
			long long previous_happiness = h - happiness[m];
			if (cost[m] <= curr_money && previous_happiness >= 0 && (cost[m] + memoization[m - 1][previous_happiness]) <= curr_money)
				previous_cost = memoization[m - 1][previous_happiness] + cost[m];

			memoization[m][h] = std::min(memoization[m - 1][h], previous_cost);
		}
	}

	// printf("h:    ");
	// for (int h = 0; h <= total_happiness; h++)
	// 	printf("%d ", h);
	// printf("\n");
	//
	// for (int m = 0; m < num_months; m++)
	// {
	// 	printf("m[%d] ", m);
	// 	for (int h = 0; h <= total_happiness; h++)
	// 	{
	// 		if (memoization[m][h] >= INF)
	// 			printf("INF ");
	// 		else
	// 			printf("%lld ", memoization[m][h]);
	// 	}
	// 	printf("\n");
	// }

	long long result = 0;
	for (long long i = total_happiness; i >= 0; i--)
	{
		if (memoization[num_months - 1][i] < INF)
		{
			result = i;
			break;
		}
	}
	return result;
}
 
int main()
{
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		int num_months;
	  	long long salary;
		scanf("%d %lld", &num_months, &salary);
		long long cost[num_months];
		long long happiness[num_months];
		for (int i = 0; i < num_months; i++)
			scanf("%lld %lld", &cost[i], &happiness[i]);
		printf("%lld\n", algorithm(num_months, cost, happiness, salary));
	}
	return 0;
}
