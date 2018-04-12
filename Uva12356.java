import java.io.*;
import java.util.*;
// will gives TLE , you can use cpp .
public class Uva12356
{
	public static void main(String [] args) throws IOException
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pr = new PrintWriter(System.out);
		StringBuilder sb = new StringBuilder();
		while(true)
		{
			StringTokenizer st = new StringTokenizer(br.readLine());
			int s = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			if(s==0) break;
			int [] left = new int[s+1];
			int [] right = new int[s+1];
			for(int i = 1 ; i <= s ; i++)
			{
				left[i]=i-1;
				right[i]=i+1;
			}
			left[1] = right[s] = -1 ;
			while(b-->0)
			{
				st = new StringTokenizer(br.readLine());
				int l = Integer.parseInt(st.nextToken());
				int r = Integer.parseInt(st.nextToken());
				if(left[l]==-1)
					sb.append("* ");
				else
					sb.append(left[l]+" ");
				if(right[r]==-1)
					sb.append("*\n");
				else
					sb.append(right[r]+"\n");
				if(right[r]!=-1)
					left[right[r]] = left[l];
				if(left[l]!=-1)
					right[left[l]] = right[r];
			}
			sb.append("-\n");
		}
		pr.print(sb.toString());
		pr.close();
		br.close();
	}
}
