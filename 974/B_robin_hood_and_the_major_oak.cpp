#include <cstdio>

void solve(int n, int k) // 2 2
{
	// n^n = odd number when n is odd, otherwise even
	// n = 1 -> odd
	// n = 2 -> even
	// n = 3 -> odd
	// n = 4 -> even
	// n = 5 -> odd

	// odd + even + odd + even...
	// odd + even = odd
	// every 2 numbers is an odd sum

	if (k % 2 == 0)
	{
		// perfect parity of odd + even
		int odds = k / 2; // divide by 2
		if (odds % 2 == 0)
		{
			// even number of odd + even
			printf("YES\n"); // even
		}
		else
		{
			// odd number of odd + even
			printf("NO\n"); // odd
		}
	}
	else
	{
		// extra odd/even (check last)

		int odds = (k - 1) / 2; // divide by 2

		if (n % 2 == 0)
		{
			// last/first is even
			if (odds % 2 == 0)
			{
				// even number of odd + even
				printf("YES\n"); // even + even
			}
			else
			{
				// odd number of odd + even
				printf("NO\n"); // odd + even
			}
		}
		else
		{
			// last/first is odd
			if (odds % 2 == 0)
			{
				// even number of odd + even
				printf("NO\n"); // even + odd
			}
			else
			{
				// odd number of odd + even
				printf("YES\n"); // odd + odd
			}
		}
	}
}

int main()
{
	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		int n, k;
		scanf("%d %d", &n, &k);
		solve(n, k);
	}

	return 0;
}
