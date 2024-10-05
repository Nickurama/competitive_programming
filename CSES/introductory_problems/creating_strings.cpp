#include <bits/stdc++.h>

void solve(std::string start, std::string left)
{
	if (left.empty())
		std::cout << start << '\n';

	for (int i = 0; i < (int)left.length(); i++)
	{
		if (i > 0 && left[i - 1] == left[i])
			continue;
		std::string newLeft = left.substr(0, i) + left.substr(i + 1, left.size() - (i + 1));
		solve(start + left[i], newLeft);
	}
}

int fact(int n)
{
	int result = 1;
	while (n-- > 0)
		result *= n + 1;
	return result;
}

void solve()
{
	std::string chars;
	std::cin >> chars;
	std::sort(chars.begin(), chars.end());

	int combinations = fact(chars.size());
	int divider = 1;
	int same_count = 1;
	for (int i = 0; i < (int)chars.size(); i++)
	{
		if (i - 1 >= 0 && chars[i] == chars[i - 1])
		{
			same_count++;
		}
		else if (i - 1 >= 0)
		{
			divider *= fact(same_count);
			same_count = 1;
		}
	}
	divider *= fact(same_count);
	combinations /= divider;
	std::cout << combinations << '\n';

	solve("", chars);
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	solve();

	return 0;
}
