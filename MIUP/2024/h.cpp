#include <bits/stdc++.h>

void solve()
{
	long long N, M;
	std::cin >> N >> M;

	std::unordered_map<int, std::vector<int>> children;
	std::unordered_map<int, std::vector<int>> fathers;
	std::vector<int> result;
	std::vector<int> tops;
	int K, V;
	for (int i = 0; i < M; i++)
	{
		std::cin >> K >> V;
		children[K].emplace_back(V);
		children[V].emplace_back(K);
	}

	std::unordered_set<int> closed;
	for (int i = 0; i < N; i++)
	{
		bool has_children = children.find(i) != children.end();
		bool has_father = fathers.find(i) != fathers.end();
		if (!has_children && !has_father)
		{
			closed.insert(i);
			tops.emplace_back(i);
		}
		else if (!has_father)
		{
			tops.emplace_back(i);
		}
	}

	std::vector<int> next;
	while (!tops.empty())
	{
		std::sort(tops.begin(), tops.end());
		for (int i = 0; i < tops.size(); i++)
		{
			int curr = tops[i];
			bool has_children = children.find(curr) != children.end();
			bool has_father = fathers.find(curr) != fathers.end();
			if (!has_children && !has_father)
			{
				result.emplace_back(curr);
				continue;
			}

			closed.insert(curr);
			result.emplace_back(curr);
			for (int j = 0; j < children[curr].size(); j++)
			{
				if (closed.find(children[curr][j]) != closed.end())
				{
					continue;
				}

				bool can_develop = true;
				for (int f = 0; f < fathers[children[curr][j]].size(); f++)
				{
					if (closed.find(fathers[children[curr][j]][f]) == closed.end())
					{
						can_develop = false;
						break;
					}
				}

				if (can_develop)
				{
					next.emplace_back(children[tops[i]][j]);
				}
			}
		}
		tops = next;
		next.clear();
	}

	for (int i = 0; i < N; i++)
	{
		if (closed.find(i) == closed.end())
		{
			std::cout << "IMPOSSIBLE\n";
			return;
		}
	}

	for (int i = 0; i < result.size() - 1; i++)
	{
		std::cout << result[i] << " ";
	}
	std::cout << result[result.size() - 1] << '\n';
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	solve();

	return 0;
}
