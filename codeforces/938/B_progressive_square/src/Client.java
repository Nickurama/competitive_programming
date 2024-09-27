import java.io.*;
import java.util.HashSet;
import java.util.Stack;

public class Client
{
	static Stack<Integer> possibleNeighbors;
	static HashSet<Integer> visited;
	static int numFound;
	static int[][] matrixFound;
	public static void main(String[] args) throws IOException
	{
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(reader.readLine());
		String[] tokens;
		String[] secondTokens;
		for (int r = 0; r < t; r++)
		{
			tokens = reader.readLine().split(" ");
			int n = Integer.parseInt(tokens[0]);
			int c = Integer.parseInt(tokens[1]);
			int d = Integer.parseInt(tokens[2]);
			secondTokens = reader.readLine().split(" ");
			numFound = 0;
			matrixFound = new int[n][n];
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					matrixFound[i][j] = Integer.parseInt(secondTokens[n * i + j]);
			isProgressiveSquare(n, c, d);
		}
	}

	public static void isProgressiveSquare(int n, int c, int d)
	{
		possibleNeighbors = new Stack<Integer>();
		visited = new HashSet<Integer>();
		numFound++;
		possibleNeighbors.push(matrixFound[0][0]);

		while (possibleNeighbors.size() > 0)
		{
			int current = possibleNeighbors.pop();
			visited.add(current);

			int toAdd = current - c;
			if (!visited.contains(toAdd) && toAdd >= 1 && isInMatrix(n, toAdd))
			{
				possibleNeighbors.push(toAdd);
			}

			toAdd = current + d;
			if (!visited.contains(toAdd) && isInMatrix(n, toAdd))
			{
				possibleNeighbors.push(toAdd);
			}

			toAdd = current + c;
			if (!visited.contains(toAdd) && isInMatrix(n, toAdd))
			{
				possibleNeighbors.push(toAdd);
			}

			toAdd = current - d;
			if (!visited.contains(toAdd) && toAdd >= 1 && isInMatrix(n, toAdd))
			{
				possibleNeighbors.push(toAdd);
			}
		}

		System.out.println(visited.size());
		if (visited.size() == n * n)
		{
			System.out.println("YES");
		}
		else
		{
			System.out.println("NO");
		}
	}

	
	static boolean isInMatrix(int n, int toFind)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (matrixFound[i][j] == toFind)
				{
					return true;
				}
			}
		}
		return false;
	}
}
