    #include <iostream>
    #include <bits/stdc++.h>
     
    struct tuple_hash
    {
    	size_t operator()(std::tuple<long long, long long, long long> const &tuple) const
    	{
    		return std::get<0>(tuple) * 7LL + std::get<1>(tuple) * 13LL + std::get<2>(tuple) * 17LL;
    	}
    };
     
    long long inc_if_exists(std::unordered_map<std::tuple<long long, long long, long long>, long long, tuple_hash> *hashmap,
    							std::tuple<long long, long long, long long> key)
    {
    	std::unordered_map<std::tuple<long long, long long, long long>, long long>::iterator it = hashmap->find(key);
    	if(it == hashmap->end())
    	{
    		(*hashmap)[key] = 1;
    		return 1;
    	}
     
    	(*hashmap)[key] = (long long)it->second + 1LL;
    	return (long long)it->second;
    }
     
    long long algorithm(long long *nums, int n)
    {
    	long long beautiful_pairs = 0;
     
    	std::unordered_map<std::tuple<long long, long long, long long>, long long, tuple_hash> hashmap;
     
    	for (int i = 0; i < n - 2; i++)
    	{
    		long long exists = inc_if_exists(&hashmap, std::make_tuple(nums[i], nums[i + 1], nums[i + 2]));
    		long long exists0 = inc_if_exists(&hashmap, std::make_tuple(0, nums[i + 1], nums[i + 2]));
    		long long exists1 = inc_if_exists(&hashmap, std::make_tuple(nums[i], 0, nums[i + 2]));
    		long long exists2 = inc_if_exists(&hashmap, std::make_tuple(nums[i], nums[i + 1], 0));
     
    		beautiful_pairs += exists0 + exists1 + exists2 - 3LL*exists;
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
    		long long nums[n];
    		for (int i = 0; i < n; i++)
    			scanf("%lld", &nums[i]);
    		printf("%lld\n", algorithm(nums, n));
    	}
    	return 0;
    }
