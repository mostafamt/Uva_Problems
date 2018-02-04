import java.util.* ;
import java.io.* ;
/**
 * 599 - The Forrest for the Trees
 * @author mostafa
 */

public class Uva599 {
    
    static final int N = 26 ;
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        PrintWriter pr = new PrintWriter(System.out);
        HashSet<Character> [] adjSet = new HashSet[N];
        int n = sc.nextInt();
        while(n-->0)
        {
            String str = sc.next();
            int numOfSets = 0 ;
            int connectedNodes = 0 ;
            int trees = 0 ;
            for (int i = 0; i < N; i++)
                adjSet[i] = new HashSet();
            while(str.charAt(0)!='*')
            {
                char from = str.charAt(1);
                char to = str.charAt(3);
                // first char in parentheses
                boolean containsFirst = false ;
                int indexOfContainsFirst = -1 ;
                for (int j = 0; j < numOfSets ; j++)
                    if(adjSet[j].contains(from)){
                        containsFirst = true ;
                        indexOfContainsFirst = j ;
                        break ;
                    }
                //second char in parentheses
                boolean containsSecond = false ;
                int indexOfContainsSecond = -1 ;
                for (int j = 0; j < numOfSets ; j++)
                    if(adjSet[j].contains(to)){
                        containsSecond = true ;
                        indexOfContainsSecond = j ;
                        break ;
                    }
                if(!containsFirst && !containsSecond)
                {
                    trees++ ;
                    connectedNodes += 2 ;
                    adjSet[numOfSets].add(from);
                    adjSet[numOfSets++].add(to);
                }
                else if( !containsFirst && containsSecond )
                {
                    connectedNodes++ ;
                    adjSet[indexOfContainsSecond].add(from);
                }
                else if( containsFirst && !containsSecond )
                {
                    connectedNodes++ ;
                    adjSet[indexOfContainsFirst].add(to);
                }
                else
                {
                    if(indexOfContainsFirst!=indexOfContainsSecond)
                    {
                        adjSet[indexOfContainsFirst].addAll(adjSet[indexOfContainsSecond]);
                        adjSet[indexOfContainsSecond].clear();
                        trees-- ;
                    }
                }
                str = sc.next();
            }
            int acorns = ((sc.next().length()+1)/2) - connectedNodes ;
            pr.println("There are "+trees+" tree(s) and "+acorns+" acorn(s).");
        }
        
        sc.close();
        pr.close();
    }
}
