#include <bits/stdc++.h>
int explore(const std::vector<int>& weights, int k, long long curr_weight, long long goal_weight, long long best_distance)
{
	if (k >= (int)weights.size())
		return best_distance;

	if (!(curr_weight + weights[k] > goal_weight))
	{
		// with weight weights[k]
		curr_weight += weights[k];
		best_distance = (goal_weight - curr_weight) < best_distance ? (goal_weight - curr_weight) : best_distance;
		best_distance = explore(weights, k + 1, curr_weight, goal_weight, best_distance);
		curr_weight -= weights[k];
	}

	// without weight weights[k]
	best_distance = explore(weights, k + 1, curr_weight, goal_weight, best_distance);

	return best_distance;
}

void solve()
{
	int n;
	std::cin >> n;
	std::vector<int> weights;
	weights.reserve(n);
	int curr;
	unsigned long long sum = 0;
	for (int i = 0; i < n; i++)
	{
		std::cin >> curr;
		sum += curr;
		weights.push_back(curr);
	}

	int dist = 2 * explore(weights, 0, 0, sum / 2, sum / 2);
	if (sum % 2 != 0)
		dist++;
	std::cout << dist << '\n';
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	solve();

	return 0;
}
