import java.io.*;

public class Client
{
	public static final String BLACK = "##";
	public static final String WHITE = "..";

	public static void main(String[] args) throws IOException
	{
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(reader.readLine());
		for (int i = 0; i < n; i++)
		{
			drawSquare(Integer.parseInt(reader.readLine()));
		}
	}

	public static void drawSquare(int n)
	{
		StringBuilder builder = new StringBuilder();
		for (int i = 0; i < n + 1; i++)
		{
			if (i % 2 == 0)
				builder.append(BLACK);
			else
				builder.append(WHITE);
		}
		String line = builder.toString();
		String startBlack = line.substring(0, line.length() - 2);
		String startWhite = line.substring(2, line.length());
		for (int i = 0; i < n; i++)
		{
			if (i % 2 == 0)
			{
				System.out.println(startBlack);
				System.out.println(startBlack);
			}
			else
			{
				System.out.println(startWhite);
				System.out.println(startWhite);
			}
		}
	}
}
