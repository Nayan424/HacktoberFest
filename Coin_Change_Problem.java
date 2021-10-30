import java.util.Arrays;
import java.util.*;

class CoinChange
{
  // Function to count the no of ways.
	public static long countWays(int S[], int m, int n)
	{
		/* table[i] will be storing the number of solutions or value i. We need n+1 rows as the table is
		 constructed in bottom up manner using the base case (n = 0) */
    
		long[] table = new long[n+1];

		// Initialize all table values as 0
		Arrays.fill(table, 0);
		table[0] = 1;

		/* Pick all coins one by one and update the table[] values after the index greater than or equal to
		   the value of the picked coin */
		for (int i=0; i<m; i++)
    {
			for (int j=S[i]; j<=n; j++)
      {
				table[j] += table[j-S[i]];
      }
    }
		return table[n];
	}

	// Main method 
	public static void main(String args[])
	{
    Scanner sc=new Scanner(System.in);
    int n=sc.nextInt();
    int arr[]=new int[n];
    int val=sc.nextInt();
    for(int i=0;i<n;i++)
    {
      arr[i]=sc.nextInt();
    }
    System.out.println(countWays(arr, n, val));
	}
}
