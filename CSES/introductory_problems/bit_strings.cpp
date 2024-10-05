#include <bits/stdc++.h>

void solve()
{
	int n;
	std::cin >> n;
	int result = 1;

	while (n--)
		result = (result * 2) % 1000000007;
		
	std::cout << result << '\n';
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	solve();

	return 0;
}
