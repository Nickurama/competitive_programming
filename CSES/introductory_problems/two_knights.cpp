#include <bits/stdc++.h>

long long fact(int n)
{
	long long result = 1;
	for (int i = n; i > 1; i--)
		result *= i;
	return result;
}

long long C(long long n, long long r)
{
	return fact(n) / (fact(r) * fact(n - r));
}

long long C2(long long n)
{
	return (double)fact(n) / (2 * (double)fact(n - 2));
}

unsigned long long fast_C2(unsigned long long n)
{
	return (n * (n - 1)) / 2;
}

unsigned long long recursive(int n)
{
	if (n <=  1)
	{
		std::cout << "0\n";
		return 0;
	}

	unsigned long long result = recursive(n - 1);

	long long num_edges = 2 * n - 1;
	long long area = n * n;

	// for each edge, add the rest of the board as a potential other knight
	result += num_edges * (area - 1);

	// remove duplicated pairs when both knights are on edges
	result -= fast_C2(num_edges);

	// remove attacking positions (corners)
	if (n >= 3)
		result -= 2 * 3; // each of the 3 corners attacks 2 positions

	// remove attacking positions (side-corners)
	if (n == 3)
		result -= 1 * 2; // each of the 2 side-corners attacks 1 position (the other
						// is already accounted for in the corner removal)
	else if (n >= 4)
	{
		result -= 4 * 3; // each of the 4 side-corners attack 3 positions
		result += 2; // duplicated removal of last 2 spots before corner
	}

	// remove attacking position (middles)
	if (n >= 5)
		result -= 2 * (n - 4) * 4; // each of the (n - 4) middle positions attack 4 positions

	std::cout << result << '\n';
	return result;
}

void solve()
{
	int n;
	std::cin >> n;
	recursive(n);
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	solve();

	return 0;
}
