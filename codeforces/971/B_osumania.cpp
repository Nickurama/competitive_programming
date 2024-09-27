#include <cstdio>

int solve(char *row)
{
	if (row[0] == '#')
		return 1;
	else if (row[1] == '#')
		return 2;
	else if (row[2] == '#')
		return 3;
	return 4;
}

int main()
{
	int t, n;
	char rows[500][5];

	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		scanf("%d", &n);
		for (int j = 0; j < n; j++)
		{
			scanf("%4s", rows[j]);
		}

		printf("%d", solve(rows[n - 1]));
		for (int j = n - 2; j >= 0; j--)
		{
			printf(" %d", solve(rows[j]));
		}
		printf("\n");
	}
	return 0;
}
