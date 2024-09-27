#include <iostream>
#include <vector>

void solve()
{
	int n;
	std::cin >> n;
	unsigned long long sum = 0;
	for (int i = 0; i < n - 2; i++)
	{
		int curr;
		std::cin >> curr;
		sum += curr;
	}
	long long sacrifice;
	std::cin >> sacrifice;
	sacrifice -= sum;
	long long winner;
	std::cin >> winner;
	winner -= sacrifice;
	
	std::cout << winner << '\n';
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
