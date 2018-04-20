import java.util.*;
import java.io.*;

public class Uva10258
{
    static final int MaxTeams = 102 ;

    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pr = new PrintWriter(System.out);
        StringBuilder sb = new StringBuilder();
        StringTokenizer st ;
        int tc = Integer.parseInt(br.readLine());
        br.readLine();
        while(tc-->0)
        {
            Team [] teams = new Team[MaxTeams];
            for (int i = 0; i < MaxTeams; i++)
                teams[i] = new Team(i);
            String str = "";
            while(br.ready() && !( str = br.readLine() ).equals("") )
            {
                st = new StringTokenizer(str);
                int id = Integer.parseInt(st.nextToken());
                int problem = Integer.parseInt(st.nextToken());
                int time = Integer.parseInt(st.nextToken());
                char state = st.nextToken().charAt(0);
                switch (state)
                {
                    case 'C':
                        teams[id].accepted(problem,time);
                        break;
                    case 'I':
                        teams[id].inaccepted(problem);
                        break;
                    default:
                        teams[id].submit();
                }
            }
            Arrays.sort(teams);
            for (int i = 0; i < MaxTeams; i++) {
                if (teams[i].isSubmitted()) {
                    sb.append(teams[i].getID() + " " + teams[i].getnumOfSolvedProblems() + " " + teams[i].getPT() + "\n");
                }
            }
            if(tc!=0)
                sb.append("\n");
        }
        pr.print(sb.toString());
        br.close();
        pr.close();
    }

    static class Team implements Comparable<Team>
    {
        private final int nProblems = 11 ;
        private final int pProblem = 20 ;
        private int id ;
        private int nSolved;
        private int totalPenality;
        private int nSubmitted;
        int [] pts ;

        public Team(int id)
        {
            this.id = id ;
            nSolved = totalPenality = nSubmitted = 0  ;
            pts = new int[nProblems];
        }

        boolean isSubmitted()
        {
            return nSubmitted > 0 ? true : false ;
        }

        int getnumOfSolvedProblems()
        {
            return nSolved;
        }

        int getPT()
        {
            return totalPenality;
        }

        int getID()
        {
            return this.id ;
        }

        void accepted(int problemID , int time)
        {
            if(pts[problemID] != -1) {
                totalPenality += pts[problemID] + time;
                pts[problemID] = -1 ;
                nSolved++;
            }
            nSubmitted++ ;
        }

        void inaccepted(int problemID)
        {
            if(pts[problemID]!=-1)
                pts[problemID] += pProblem;
            nSubmitted++ ;
        }

        void submit()
        {
            nSubmitted++ ;
        }

        public int compareTo(Team t)
        {
            if(this.nSolved != t.nSolved)
                return t.nSolved - this.nSolved;
            else if(this.totalPenality != t.totalPenality)
                return this.totalPenality - t.totalPenality;
            else
                return this.id - t.id ;
        }

    }
}
