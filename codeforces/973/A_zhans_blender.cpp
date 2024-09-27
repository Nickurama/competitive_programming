#include <iostream>

void solve()
{
	int n, x, y;
	std::cin >> n >> x >> y;

	int throughput = std::min(x, y);
	int result = n / throughput;
	if (n % throughput != 0)
		result++;

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
