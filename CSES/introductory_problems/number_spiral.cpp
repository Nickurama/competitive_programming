#include <bits/stdc++.h>

void solve()
{
	int x, y;
	std::cin >> y >> x;

	unsigned long long len = std::max(x, y);
	unsigned long long result = len * len - len + 1;
	if (len % 2 == 0)
		result += y - x;
	else
		result += x - y;

	std::cout << result << '\n';
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
