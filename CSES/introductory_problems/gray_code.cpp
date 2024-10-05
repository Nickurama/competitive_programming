#include <bits/stdc++.h>

int powerInt(int base, int power)
{
	int result = 1;
	for (int i = 0; i < power; i++)
		result *= base;
	return result;
}

inline void swap(std::string& str, int i)
{
	str[i] == '1' ? str[i] = '0' : str[i] = '1';
}

void solve()
{
	int n;
	std::cin >> n;

	int remaining[16];
	int power = 1;
	remaining[0] = power;
	for (int i = 1; i < n; i++)
	{
		power *= 2;
		remaining[i] = power;
	}

	std::string result(n, '0');
	std::cout << result << '\n';
	for (int i = 1; i < pow(2, n); i++)
	{
		for (int i = 0; i < n; i++)
		{
			remaining[i]--;
			if (remaining[i] == 0)
			{
				swap(result, i);
				remaining[i] = powerInt(2, i + 1);
			}
		}
		std::cout << result << '\n';
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	solve();

	return 0;
}
