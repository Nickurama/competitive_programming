import java.io.*;

public class Client
{
	public static void main(String[] args) throws IOException
	{
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(reader.readLine());
		String[] tokens;
		for (int i = 0; i < n; i++)
		{
			tokens = reader.readLine().split(" ");
			whatIs(Integer.parseInt(tokens[0]), Integer.parseInt(tokens[1]), Integer.parseInt(tokens[2]));
		}
	}

	public static void whatIs(int a, int b, int c)
	{
		if (a < b && b < c)
			System.out.println("STAIR");
		else if (a < b && b > c)
			System.out.println("PEAK");
		else
			System.out.println("NONE");
	}
}
