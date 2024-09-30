#include <bits/stdc++.h>

void solve()
{
	int n;
	std::cin >> n;

	if (n == 1)
	{
		std::cout << "1\n";
		return;
	}

	if (n == 2 || n == 3)
	{
		std::cout << "NO SOLUTION" << '\n';
		return;
	}

	for (int i = 2; i <= n; i += 2)
		std::cout << i << ' ';

	for (int i = 1; i < n - 1; i += 2)
		std::cout << i << ' ';


	if (n % 2 == 0)
		std::cout << n - 1 << '\n';
	else
		std::cout << n << '\n';
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	solve();

	return 0;
}
