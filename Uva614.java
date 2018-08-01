import java.util.*;
import java.io.*;

public class Uva614
{
    static int R , C , y , x ;
    static int [][] path ;
    static boolean block[][][] ;
    static int [] dy = { 0 , -1 , 0 , 1 };
    static int [] dx = {-1 ,  0 , 1 , 0 };


    static boolean valid(int y , int x)
    {
        if( y >= R || x >= C || y < 0 || x < 0 ){
            return false ;
        }
        return true ;
    }

    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pr = new PrintWriter(System.out);
        StringBuilder sb = new StringBuilder();
        int maze = 1 ;

        while( true ){
            StringTokenizer st = new StringTokenizer(br.readLine());
            while(!st.hasMoreTokens()){
                st = new StringTokenizer(br.readLine());
            }
            R = Integer.parseInt(st.nextToken());
            if(R==0){
                break ;
            }
            while(!st.hasMoreTokens()){
                st = new StringTokenizer(br.readLine());
            }
            C = Integer.parseInt(st.nextToken());
            while(!st.hasMoreTokens()){
                st = new StringTokenizer(br.readLine());
            }
            int a = Integer.parseInt(st.nextToken())-1 ;
            while(!st.hasMoreTokens()){
                st = new StringTokenizer(br.readLine());
            }
            int b = Integer.parseInt(st.nextToken())-1 ;
            while(!st.hasMoreTokens()){
                st = new StringTokenizer(br.readLine());
            }
            y = Integer.parseInt(st.nextToken())-1 ;
            while(!st.hasMoreTokens()){
                st = new StringTokenizer(br.readLine());
            }
            x = Integer.parseInt(st.nextToken())-1 ;
            path = new int[R][C];
            block = new boolean[R][C][4];

            for(int i = 0 ; i < R ; i++){
                st = new StringTokenizer(br.readLine());
                for(int j = 0 ; j < C ; j++){
                    int c = Integer.parseInt(st.nextToken());
                    switch (c){
                        case 1 :
                            block[i][j][2] = true ;
                            if( valid(i,j+1) ){
                                block[i][j+1][0] = true ;
                            }
                            break ;
                        case 3 :
                            block[i][j][2] = true ;
                            if( valid(i,j+1) ){
                                block[i][j+1][0] = true ;
                            }
                        case 2:
                            block[i][j][3] = true ;
                            if( valid(i+1,j) ){
                                block[i+1][j][1] = true ;
                            }
                            break ;
                    }
                }
            }

            for(int i = 0 ; i < R ; i++){
                block[i][0][0] = true ;
                block[i][C-1][2] = true ;
            }
            for(int i = 0 ; i < C ; i++){
                block[0][i][1] = true ;
                block[R-1][i][3] = true ;
            }
            path[a][b] = 1 ;
            dfs(a,b);

            sb.append("Maze ").append(maze++).append("\n\n");
            for(int i = 0 ; i < C ; i++){
                sb.append("+---");
            }
            sb.append("+\n");

            for(int i = 0 ; i < R ; i++){
                sb.append("|");
                for(int j = 0 ; j < C ; j++){
                    if( path[i][j] == -1 ){
                        sb.append("???");
                    } else if ( path[i][j] == 0 ){
                        sb.append("   ");
                    } else {
                        sb.append( String.format("%3d" , path[i][j]) );
                    }
                    sb.append( block[i][j][2] ? "|" : " " );

                }
                sb.append('\n');
                for(int j = 0 ; j < C ; j++){
                    if( block[i][j][3] ){
                        sb.append("+---");
                    } else {
                        sb.append("+   ");
                    }
                }
                sb.append("+\n");
            }
            sb.append("\n\n");

            br.readLine();

        }
        pr.print(sb.toString());
        pr.close();
        br.close();
    }



    static boolean dfs(int u , int v)
    {
        if( u == y && v == x ){
            return true ;
        }
        for(int i = 0 ; i < 4 ; i++){
            int r = u + dy[i] ;
            int c = v + dx[i] ;
            if( !block[u][v][i]  && path[r][c] == 0 ){
                path[r][c] = path[u][v] + 1 ;
                if(dfs(r,c)){
                    return true ;
                }
            }
        }
        path[u][v] = -1 ;
        return false ;
    }


}
