#include <bits/stdc++.h>

void print_vector(std::vector<int>& vect)
{
	if (vect.size() < 0)
		return;
	std::cout << vect.size() << '\n';
	for (int i = 0; i < vect.size() - 1; i++)
		std::cout << vect[i] << ' ';
	std::cout << vect[vect.size() - 1] << '\n';
}

void solve()
{
	int n;
	std::cin >> n;

	unsigned long long sum = (unsigned long long)(n + (unsigned long long)n * n) / 2;

	if (sum % 2 != 0)
	{
		std::cout << "NO\n";
		return;
	}

	std::cout << "YES\n";

	unsigned long long goal = sum / 2;
	std::vector<int> greedy;
	std::vector<int> remain;
	greedy.reserve(n / 2 + 1);
	remain.reserve(n);

	unsigned long long partial_sum = 0;
	int curr = n;
	int offset_num;
	while (partial_sum <= goal) // add greedy sum towards goal
	{
		if (partial_sum + curr > goal)
		{
			offset_num = goal - partial_sum;
			if (offset_num > 0)
				greedy.push_back(offset_num);
			break;
		}

		greedy.push_back(curr);
		partial_sum += curr;
		curr--;
	}

	while (curr > 0) // fill other with remaining numbers
	{
		if (curr == offset_num)
		{
			curr--;
			continue;
		}
		remain.push_back(curr--);
	}

	// print each vector
	print_vector(greedy);
	print_vector(remain);
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	solve();

	return 0;
}
