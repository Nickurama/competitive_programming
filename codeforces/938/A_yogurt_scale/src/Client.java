import java.io.*;

public class Client
{
	public static void main(String[] args) throws IOException
	{
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(reader.readLine());
		String[] tokens;
		for (int i = 0; i < t; i++)
		{
			tokens = reader.readLine().split(" ");
			System.out.println(yogurt(Integer.parseInt(tokens[0]), Integer.parseInt(tokens[1]), Integer.parseInt(tokens[2])));
		}
	}

	public static int yogurt(int n, int a, int b)
	{
		if (a + a < b)
			return n * a;
		else
			return ((n / 2) * b) + a * (n % 2);
	}
}
