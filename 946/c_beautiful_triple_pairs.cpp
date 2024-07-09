#include <iostream>
#include <bits/stdc++.h>
 
struct tuple_hash
{
	size_t operator()(std::tuple<unsigned long, unsigned long, unsigned long> const &tuple) const
	{
		return std::get<0>(tuple) * 7 + std::get<1>(tuple) * 13 + std::get<2>(tuple) * 17;
	}
};

unsigned long inc_if_exists(std::unordered_map<std::tuple<unsigned long, unsigned long, unsigned long>, unsigned long, tuple_hash>
							*hashmap, std::tuple<unsigned long, unsigned long, unsigned long> key)
{
	auto found = hashmap->find(key);
	if(found == hashmap->end())
	{
		(*hashmap)[key] = 1;
		return 1;
	}

	(*hashmap)[key] = found->second + 1;
	return found->second;
}
 
unsigned long algorithm(unsigned long *nums, int n)
{
	unsigned long beautiful_pairs = 0;
 
	std::unordered_map<std::tuple<unsigned long, unsigned long, unsigned long>, unsigned long, tuple_hash> hashmap;

	for (int i = 0; i < n - 2; i++)
	{
		unsigned long exists = inc_if_exists(&hashmap, std::make_tuple(nums[i], nums[i + 1], nums[i + 2]));
		unsigned long exists0 = inc_if_exists(&hashmap, std::make_tuple(0, nums[i + 1], nums[i + 2]));
		unsigned long exists1 = inc_if_exists(&hashmap, std::make_tuple(nums[i], 0, nums[i + 2]));
		unsigned long exists2 = inc_if_exists(&hashmap, std::make_tuple(nums[i], nums[i + 1], 0));

		std::unordered_map<std::tuple<unsigned long, unsigned long, unsigned long>, unsigned long>::iterator it;

		// std::cout << "==============" << std::endl;
		// for (it = hashmap.begin(); it != hashmap.end(); it++)
		// 	std::cout << "cnt((" << std::get<0>(it->first) << "," << std::get<1>(it->first) << "," << std::get<2>(it->first) << ")) = " <<
		// 		it->second << std::endl;

		beautiful_pairs += exists0 + exists1 + exists2 - 3*exists;
	}

	return beautiful_pairs;
}
 
int main()
{
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		int n;
		scanf("%d", &n);
		unsigned long nums[n];
		for (int i = 0; i < n; i++)
			scanf("%lu", nums + i);
		printf("%lu\n", algorithm(nums, n));
	}
	return 0;
}
