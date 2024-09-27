#include <iostream>

int algorithm(int x, int y)
{
	int screens = 0;
	int big_slots = 0;
	int slots = 0;

	// big icons
	for (int i = 0; i < y; i++)
	{
		slots -= 4;
		big_slots -= 1;

		if (slots < 0 || big_slots < 0)
		{
			screens++;
			slots += 15;
			big_slots += 2;
		}
	}

	// small icons
	for (int i = 0; i < x; i++)
	{
		slots--;
		if (slots < 0)
		{
			screens++;
			slots += 15;
		}
	}

	return screens;
}


int main()
{
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		printf("%d\n", algorithm(x, y));
	}
	return 0;
}
