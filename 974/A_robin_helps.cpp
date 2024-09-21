#include <cstdio>

int solve(int* p, int n, int k)
{
	int result = 0;

	int m = 0;
	for (int i = 0; i < n; i++)
	{
		if (p[i] >= k)
		{
			m += p[i];
		}
		else if (p[i] == 0 && m > 0)
		{
			m--;
			result++;
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
		int n, k;
		scanf("%d %d", &n, &k);
		int p[50];
		for (int i = 0; i < n; i++)
			scanf("%d", p + i);
		printf("%d\n", solve(p, n, k));
	}

	return 0;
}
