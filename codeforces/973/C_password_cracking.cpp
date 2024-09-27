#include <iostream>

void guess(const std::string& str)
{
	std::cout << "! " + str << std::endl;
	// int result;
	// std::cin >> result;
}

bool query(const std::string& str)
{
	std::cout << "? " + str << std::endl;
	int result;
	std::cin >> result;
	if (result < 0)
		std::exit(0);
	return (bool)result;
}

void solve()
{
	int n;
	std::cin >> n;
	if (n < 0)
		std::exit(0);

	std::string result = "0";
	result.reserve(200);
	if (!query(result))
	{
		result = "";
		result.append(n, '1');
		guess(result);
		return;
	}

	bool fowards = true;

	n--;
	while (n--)
	{
		if (fowards)
		{
			result.append("0");
			if (query(result))
				continue;

			result[result.size() - 1] = '1';
			if (query(result))
				continue;

			fowards = false;
			result.pop_back();
		}

		result.insert(0, 1, '0');
		if (query(result))
			continue;

		result[0] = '1';
		if (n == 0) // skips last possible state
			continue;
		if (query(result))
			continue;

		// impossible
		std::exit(0);
	}

	guess(result);
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	// std::cin.tie(0);

	int t;
	std::cin >> t;
	while (t--)
		solve();

	return 0;
}
