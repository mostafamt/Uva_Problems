import java.util.* ;
import java.io.* ;

public class Uva11340
{
	public static void main(String[]args) throws IOException
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pr = new PrintWriter(System.out);
		StringBuilder sb = new StringBuilder();
		int tc = Integer.parseInt(br.readLine());
		while(tc-->0)
		{
			Map<String,Integer> map = new HashMap<>();
			int n = Integer.parseInt(br.readLine());
			while(n-->0)
			{
				StringTokenizer st = new StringTokenizer(br.readLine());
				map.put(st.nextToken(),Integer.parseInt(st.nextToken()) );
			}
			n = Integer.parseInt(br.readLine());
			double ans = 0.0 ;
			while(n-->0)
			{
				char [] arr = br.readLine().toCharArray();
				for(int i=0 ; i<arr.length ; ++i )
					if(map.containsKey((arr[i])+""))
						ans += map.get((arr[i]+""));
			}
			sb.append( String.format("%.2f$\n",ans/100) );
		}
		pr.print(sb.toString());
		br.close();
		pr.close();
		
	}
}
