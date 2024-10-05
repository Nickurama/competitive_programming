#include <bits/stdc++.h>

void move(int from, int to)
{
	std::cout << from << " " << to << '\n';
}

void move(int stackMax, int from, int to)
{
	if (stackMax == 1)
	{
		move(from, to);
		return;
	}

	int mid = 0;
	if (from != 1 && to != 1)
		mid = 1;
	else if (from != 2 && to != 2)
		mid = 2;
	else if (from != 3 && to != 3)
		mid = 3;

	move(stackMax - 1, from, mid);
	move(from, to);
	move(stackMax - 1, mid, to);
}

int fastPow(int base, int power)
{
	int result = 1;
	while (power--)
		result *= base;
	return result;
}

void solve()
{
	int n;
	std::cin >> n;
	std::cout << (fastPow(2, n) - 1) << '\n';
	move(n, 1, 3);
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	solve();

	return 0;
}
