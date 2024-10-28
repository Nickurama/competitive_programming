#include <bits/stdc++.h>

void solve()
{
	int E, T;
	std::cin >> E;
	std::cin >> T;
	std::vector<std::vector<int>> m(T, std::vector<int>(E));
	for (int i = 0; i < T; i++)
	{
		for (int j = 0; j < E; j++)
		{
			std::cin >> m[i][j];
		}
	}

	int k = -1;
	for (int i = 0; i < T; i++)
	{
		int sum = 0;
		for (int j = 0; j < E; j++)
		{
			sum += m[i][j];
			if (sum > k && k != -1)
			{
				std::cout << "Maxwell daemon!\n";
				return;
			}
		}

		if (k < 0)
		{
			k = sum;
		}
		else
		{
			if (k != sum)
			{
				std::cout << "Maxwell daemon!\n";
				return;
			}
		}
	}
	std::cout << "Total energy is " << k << ", no physical law broken.\n";
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
