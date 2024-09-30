#include <bits/stdc++.h>

void solve()
{
	int n;
	std::cin >> n;

	long long moves = 0;
	int curr;
	int curr_max = 0;
	for (int i = 0; i < n; i++)
	{
		std::cin >> curr;
		if (curr < curr_max)
			moves += curr_max - curr;
		else
			curr_max = curr;
	}

	std::cout << moves << '\n';
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	solve();

	return 0;
}
