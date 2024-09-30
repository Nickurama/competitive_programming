#include <bits/stdc++.h>

void solve()
{
	std::string str;
	std::cin >> str;

	int max = 0;
	char curr = '\0';
	int curr_max = 0;

	for (int i = 0; i < (int)str.size(); i++)
	{
		if (curr == str[i])
		{
			curr_max++;
		}
		else
		{
			max = std::max(max, curr_max);
			curr = str[i];
			curr_max = 1;
		}
	}
	max = std::max(max, curr_max);

	std::cout << max << '\n';
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	solve();

	return 0;
}
