#include <bits/stdc++.h>

unsigned long long recursive(int n)
{
	if (n <=  1)
	{
		std::cout << "0\n";
		return 0;
	}

	long long cache = 8 * (n - 4);
	unsigned long long result = recursive(n - 1) + (2LL * n - 1) * (n * n - n) - (cache + 16);

	if (n == 2)
		result += cache + 16;
	else if (n == 3)
		result += cache + 8;
	else if (n == 4)
		result += cache;

	std::cout << result << '\n';
	return result;
}

void solve2() // not my solution
{
	int k;
	std::cin >> k;
	for (long long n = 1; n <= k; n++)
		std::cout << n * n * (n * n - 1) / 2 - 4 * (n - 1) * (n - 2) << std::endl;
}

void solve()
{
	int n;
	std::cin >> n;
	recursive(n);
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	solve2();

	return 0;
}
