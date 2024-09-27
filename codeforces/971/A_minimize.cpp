#include <cstdio>

int solve(int a, int b)
{
	return b - a;
}

int main()
{
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", solve(a, b));
	}
	return 0;
}
