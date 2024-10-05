#include <bits/stdc++.h>

void solve2()
{
	int a, b;
	std::cin >> a >> b;

	std::cout << (((a + b) % 3 != 0) || a > 2 * b || b > 2 * a ? "NO\n" : "YES\n");
}

void solve()
{
	int a, b;
	std::cin >> a >> b;

	int diff = std::abs(a - b);
	if (std::min(a, b) < diff || std::max(a, b) < 2 * diff)
	{
		std::cout << "NO\n";
		return;
	}

	if (a < b)
	{
		a -= diff;
		b -= 2 * diff;
	}
	else
	{
		a -= 2 * diff;
		b -= diff;
	}

	// a == b
	if (a % 3 == 0)
	{
		std::cout << "YES\n";
		return;
	}
	std::cout << "NO\n";
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int t;
	std::cin >> t;
	while (t--)
		solve();

	return 0;
}
