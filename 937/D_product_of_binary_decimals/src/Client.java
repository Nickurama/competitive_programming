import java.io.*;

public class Client
{
	public static void main(String[] args) throws IOException
	{
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(reader.readLine());
		for (int i = 0; i < n; i++)
			algorithm(Integer.parseInt(reader.readLine()));
	}

	public static void algorithm(int n)
	{
		if (isBinary(n))
		{
			System.out.println("YES");
			return;
		}
		int currBinary = 10;
		while (currBinary < n)
		{
			if (n % currBinary == 0)
			{
				n /= currBinary;
				if (n == 1)
				{
					System.out.println("YES");
					return;
				}
				currBinary = 10;
			}
			else
			{
				currBinary = increaseBinary(currBinary);
			}
		}

		if (currBinary == n)
		{
			System.out.println("YES");
		}
		else
			System.out.println("NO");
	}

	public static boolean isBinary(int n)
	{
		String num = Integer.toString(n);
		for (int i = 0; i < num.length(); i++)
		{
			Character c = num.charAt(i);
			if (c != '1' && c != '0')
				return false;
		}
		return true;
	}

	public static int increaseBinary(int n)
	{
		String num = Integer.toString(n);
		StringBuilder builder = new StringBuilder();
		int currInd = 0;
		boolean endedOnOne = true;
		for (int i = 0; i < num.length(); i++)
		{
			currInd = num.length() - 1 - i;
			Character currNum = num.charAt(currInd);

			if (currNum == '1')
				builder.insert(0, "0");
			else
			{
				endedOnOne = false;
				builder.insert(0, "1");
				if (currInd == 0)
					break;
				builder.insert(0, num.substring(0, currInd));
				break;
			}
			//System.out.println(builder.toString());
		}
		if (endedOnOne)
			builder.insert(0, "1");
		return Integer.parseInt(builder.toString());
	}
}
