#include <bits/stdc++.h>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::vector<bool> vect;
	vect.reserve(n + 1);
	int curr;
	for (int i = 0; i < n - 1; i++)
	{
		std::cin >> curr;
		vect[curr] = true;
	}

	for (int i = 1; i <= n; i++)
	{
		if (!vect[i])
		{
			std::cout << i << '\n';
			return 0;
		}
	}
	return 0;
}
