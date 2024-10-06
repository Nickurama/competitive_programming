#include <bits/stdc++.h>

bool isBeingAttacked(int row, int col, std::vector<std::pair<int, int>>& queens_location)
{
	for (std::pair<int, int> queen : queens_location)
	{
		if (row == queen.first)
			return true;
		if (col == queen.second)
			return true;

		// (row + 1) + (col + 1) - 1
		// int this_diagonal0 = row + col + 1;
		// int that_diagonal0 = queen.first + queen.second + 1;
		if (row + col == queen.first + queen.second)
			return true;

		// (n - row) + (col + 1) - 1
		// int this_diagonal1 = 8 - row + col;
		// int that_diagonal1 = 8 - queen.first + queen.second;
		if (col - row == queen.second - queen.first)
			return true;
	}
	return false;
}

int search(int queens, int count, int row, int col, bool board[8][8], std::vector<std::pair<int, int>>& queens_location)
{
	if (queens == 8)
		return count + 1;

	// check when reaching the end of the board
	if (row > 7)
		return count;

	// calculate new position (newRow, newCol)
	int newCol = col;
	int newRow = row;
	if (col == 7)
	{
		newCol = 0;
		newRow++;
	}
	else
	{
		newCol++;
	}

	// subset where board[row][col] has a queen
	if (!board[row][col] && !isBeingAttacked(row, col, queens_location))
	{
		board[row][col] = true;
		queens_location.emplace_back(row, col); // might not work cuz pair
		count = search(queens + 1, count, newRow, newCol, board, queens_location);
		queens_location.pop_back();
		board[row][col] = false;
	}

	// subset where board[row][col] does not have a queen
	count = search(queens, count, newRow, newCol, board, queens_location);

	return count;
}

void solve()
{
	bool board[8][8];
	std::memset(board, false, 8 * 8 * sizeof(bool));
	std::vector<std::pair<int, int>> queens_location;
	queens_location.reserve(8);

	char curr;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			std::cin >> curr;
			if (curr == '*')
				board[i][j] = true;
		}
	}

	std::cout << search(0, 0, 0, 0, board, queens_location) << '\n';
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	solve();

	return 0;
}
