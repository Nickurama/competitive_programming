#include <bits/stdc++.h>

void solve()
{
	int n;
	std::cin >> n;

	long long power = 5;
	int result = 0;
	while (power <= n)
	{
		result += n / power;
		power *= 5;
	}
	std::cout << result << '\n';
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	solve();

	return 0;
}
