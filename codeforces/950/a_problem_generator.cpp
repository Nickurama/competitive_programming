#include <iostream>
#include <bits/stdc++.h>

int algorithm(int m, char *bank, int n)
{
	int count[7];
	for (int i = 0; i < 7; i++)
		count[i] = 0;

	for (int i = 0; i < n; i++)
		count[bank[i] - 65]++;

	int missing = 0;
	for (int i = 0; i < 7; i++)
	{
		int left = m - count[i];
		if (left > 0)
			missing += left;
	}
	return missing;
}

int main()
{
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		int n, m;
		scanf("%d %d", &n, &m);
		char bank[n + 1];
		scanf("%s", bank);
		printf("%d\n", algorithm(m, bank, n));
	}
	return 0;
}

