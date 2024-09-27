#include <iostream>
#include <bits/stdc++.h>

bool sortOrder(int a, int b)
{
	return a - b > 0;
}

void algorithm(int *cubes, int n, int f, int k)
{
	int chosen_value = cubes[f - 1];
	std::sort(cubes, cubes + n, sortOrder);
	if (cubes[k - 1] > chosen_value)
		printf("NO\n");
	else if (cubes[k - 1] < chosen_value)
		printf("YES\n");
	else
	{
		if (k >= n)
			printf("YES\n");
		else if (cubes[k] == chosen_value)
			printf("MAYBE\n");
		else // cubes[k] < chosen_value
			printf("YES\n");
	}
}

int main()
{
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		int n, f, k;
		scanf("%d %d %d", &n, &f, &k);
		int cubes[n];
		for (int i = 0; i < n; i++)
			scanf("%d", cubes + i);
		algorithm(cubes, n, f, k);
	}
	return 0;
}

