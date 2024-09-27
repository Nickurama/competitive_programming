#include <cstdio>

int solve(int x, int y, int k) // 9 11 3
{
	int result = 0;

	int min_steps_for_x = x / k; // 3
	if (x % k > 0)
		min_steps_for_x++;
	result += min_steps_for_x * 2; // accounting for Y steps

	int increments = min_steps_for_x;
	int y_value = increments * k;
	int remaining = y - y_value; 
	int increments_left = remaining / k; 
	if (remaining > 0 && remaining % k > 0)
		increments_left++;

	if (increments_left > 0)
		result += increments_left * 2;
	else if (increments_left < 0)
		result--;

	return result;
}

int main()
{
	int t, x, y, k;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		scanf("%d %d %d", &x, &y, &k);
		printf("%d\n", solve(x, y, k));
	}
	return 0;
}
