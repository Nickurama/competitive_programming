#include <algorithm>
#include <cstdio>
#include <vector>

long long solve(std::vector<int>& vect, unsigned long long sum)
{
	if (vect.size() <= 2)
		return -1;
	std::sort(vect.begin(), vect.end());
	double avg = (double)sum / (double)vect.size();
	long long middle_index = vect.size() / 2; // strictly more than half
	long long min_avg = 2 * vect[middle_index]; // min_avg to call robin_hood
	if (avg > min_avg)
		return 0;

	unsigned long long needs = vect.size() * min_avg + 1; // + 1 because >, not >=
	return needs - sum; // sum = "has"
}

int main()
{
	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		int n;
		scanf("%d", &n);

		unsigned long long sum = 0;
		std::vector<int> vect;
		vect.reserve(n);
		int curr;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &curr);
			sum += curr;
			vect.emplace_back(curr);
		}

		printf("%lld\n", solve(vect, sum));
	}

	return 0;
}
