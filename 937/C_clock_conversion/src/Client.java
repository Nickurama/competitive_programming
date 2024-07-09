import java.io.*;

public class Client
{
	public static final String PM = "PM";
	public static final String AM = "AM";

	public static void main(String[] args) throws IOException
	{
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(reader.readLine());
		String[] tokens;
		for (int i = 0; i < n; i++)
		{
			tokens = reader.readLine().split(":");
			convert(Integer.parseInt(tokens[0]), Integer.parseInt(tokens[1]));
		}
	}

	public static void convert(int hours, int minutes)
	{
		String modifier = AM;
		if (hours == 0)
			hours = 12;
		else if (hours > 12)
		{
			modifier = PM;
			hours -= 12;
		}
		else if (hours == 12)
			modifier = PM;
		System.out.println(String.format("%02d:%02d %s", hours, minutes, modifier));
	}
}
