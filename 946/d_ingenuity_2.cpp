#include <iostream>
#include <bits/stdc++.h>

#define ROVER 'R';
#define HELICOPTER 'H';

void addHeli(char *out_str, int i, int *heli_satisfied)
{
	out_str[i] = HELICOPTER;
	*heli_satisfied = 1;
}

void addRover(char *out_str, int i, int *rover_satisfied)
{
	out_str[i] = ROVER;
	*rover_satisfied = 1;
}

void direction(int *has_current, int *has_opposite, int *started_heli, int *rover_satisfied, int *heli_satisfied, char *out_str, int i, int dir_NS, int *dir_started_heli)
{
	// O ... C
	if (*has_opposite)
	{
		if (*started_heli && (dir_NS == *dir_started_heli))
		{
			*started_heli = 0;
			addHeli(out_str, i, heli_satisfied);
		}
		else
		{
			addRover(out_str, i, rover_satisfied);
		}
		*has_opposite = 0;
		return;
	}

	// C ... C
	if (*has_current)
	{
		if (*started_heli && (dir_NS == *dir_started_heli))
		{
			*started_heli = 0;
			addRover(out_str, i, rover_satisfied);
		}
		else
		{
			addHeli(out_str, i, heli_satisfied);
		}
		*has_current = 0;
		return;
	}

	// ... C
	if (!(*heli_satisfied) && !(*started_heli))
	{
		*started_heli = 1;
		*dir_started_heli = dir_NS;
		addHeli(out_str, i, heli_satisfied);
	}
	else
	{
		addRover(out_str, i, rover_satisfied);
	}
	*has_current = 1;
}

char *solve(char *str, int n, char *out_str)
{
	int rover_satisfied = 0;
	int heli_satisfied = 0;

	int started_heli = 0;
	int dir_started_heli = 0;

	int hasN = 0;
	int hasS = 0;
	int hasE = 0;
	int hasW = 0;

	for (int i = 0; i < n; i++)
	{
		if (str[i] == 'N')
			direction(&hasN, &hasS, &started_heli, &rover_satisfied, &heli_satisfied, out_str, i, 1, &dir_started_heli);
		else if (str[i] == 'S')
			direction(&hasS, &hasN, &started_heli, &rover_satisfied, &heli_satisfied, out_str, i, 1, &dir_started_heli);
		else if (str[i] == 'E')
			direction(&hasE, &hasW, &started_heli, &rover_satisfied, &heli_satisfied, out_str, i, 0, &dir_started_heli);
		else // 'W'
			direction(&hasW, &hasE, &started_heli, &rover_satisfied, &heli_satisfied, out_str, i, 0, &dir_started_heli);
	}

	out_str[n] = 0;

	if (hasN || hasS || hasE || hasW || !rover_satisfied || !heli_satisfied)
	{
		out_str[0] = 'N';
		out_str[1] = 'O';
		out_str[2] = 0;
	}

	return out_str;
}
 
int main()
{
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		int n;
		scanf("%d", &n);
		char str[n + 1];
		scanf("%s", str);
		char out_str[n + 2];
		printf("%s\n", solve(str, n, out_str));
	}
	return 0;
}
