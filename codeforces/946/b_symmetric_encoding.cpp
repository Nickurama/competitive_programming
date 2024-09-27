#include <iostream>
#include <bits/stdc++.h>

char *algorithm(char *str, int len, char *out_str)
{
	std::set<char> hash;

	// insert all characters from the string in ordered fashion (log n)
	for (int i = 0; i < len; i++)
		hash.insert(str[i]);

	// generate r string from hash set
	char r[hash.size()];
	int n = 0;
	for (std::set<char>::iterator it = hash.begin(); it != hash.end(); it++)
		r[n++] = *it;

	// generate encoding hash map
	std::unordered_map<char, char> encoding_table;
	for (int i = 0; i < n; i++)
		encoding_table[r[i]] = r[n - 1 - i];

	// encode the string
	for (int i = 0; i < len; i++)
		out_str[i] = encoding_table[str[i]];
	out_str[len] = 0;

	return out_str;
}

int main()
{
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		int len;
		scanf("%d", &len);
		char str[len];
		scanf("%s", str);
		char out_str[len];
		printf("%s\n", algorithm(str, len, out_str));
	}
	return 0;
}
