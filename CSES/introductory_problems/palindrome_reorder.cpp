#include <bits/stdc++.h>

void solve()
{
	std::string str;
	std::cin >> str;

	// bool cache[26];
	// std::memset(cache, 0, 26 * sizeof(bool));
	//
	// std::string result = "";
	// for (int i = 0; i < str.size(); i++)
	// {
	// 	if (cache[str[i] - 'A'])
	// 	{
	// 		cache[str[i] - 'A'] = false;
	// 		result.insert(0, 1, str[i]);
	// 		result += str[i];
	// 		continue;
	// 	}
	//
	// 	cache[str[i] - 'A'] = true;
	// }
	//
	// int leftovers = 0;
	// for (int i = 0; i < 26; i++)
	// {
	// 	if (cache[i])
	// 	{
	// 		if (leftovers > 0)
	// 		{
	// 			std::cout << "NO SOLUTION";
	// 			return;
	// 		}
	// 		leftovers++;
	// 		result.insert(result.size() / 2, 1, i + 'A');
	// 	}
	// }

	int arr[26];
	std::memset(arr, 0, 26 * sizeof(int));

	for (int i = 0; i < (int)str.size(); i++)
		arr[str[i] - 'A']++;

	int odd_counter = 0;
	int odd_index = 0;
	for (int i = 0; i < 26; i++)
	{
		if (arr[i] % 2 != 0)
		{
			odd_index = i;
			odd_counter++;
		}
	}

	if (odd_counter > 1)
	{
		std::cout << "NO SOLUTION";
		return;
	}

	std::string result;
	if (odd_counter > 0)
		result = odd_index + 'A';

	for (int i = 0; i < 26; i++)
	{
		if (arr[i] == 0)
			continue;
		result.insert(0, arr[i] / 2, (i + 'A'));
		result.insert(result.size(), arr[i] / 2, (i + 'A'));
	}

	std::cout << result << '\n';
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	solve();

	return 0;
}
