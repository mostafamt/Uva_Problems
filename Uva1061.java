import java.util.*;
import java.io.*;

// NOTE : Don't forget to remove curly braces if you have one possible answer

public class Uva1061
{
    static Map<String,String [] > table = new HashMap<>();
    static Map<String,String> map ;
    static String [] all_combination ;
    static String [] RH_combination;

    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pr = new PrintWriter(System.out);
        StringBuilder sb = new StringBuilder("");


        table.put("A", new String[]{"AA","AO"} );
        table.put("B", new String[]{"BB","BO"} );
        table.put("AB", new String[]{"AB"} );
        table.put("O", new String[]{"OO"} );
        table.put("+",new String[]{"++","+-"});
        table.put("-", new String[]{"--"});
        ///////////////////////////////////////////////
        map = new HashMap<>();
        map.put("AO","A");
        map.put("AA","A");
        map.put("BB","B");
        map.put("BO","B");
        map.put("AB","AB");
        map.put("OO","O");
        map.put("++","+");
        map.put("+-","+");
        map.put("--","-");
        ///////////////////////////////////////////////
        all_combination = new String[]{"AA","AB","AO","BB","BO","OO"};
        RH_combination = new String[]{"++","+-","--"};

        String line = "" ;
        int tc = 1 ;
        LOOP : while( !( line = br.readLine() ).equals("E N D") ){
            while( line.isEmpty() ){
                line = br.readLine();
                if( line.equals("E N D") ){
                    break LOOP ;
                }
            }
            sb.append("Case "+ tc++ + ": " );
            StringTokenizer st = new StringTokenizer(line);
            String parent1 = st.nextToken();
            String parent2 = st.nextToken();
            String child = st.nextToken();
            if( child.equals("?") ){
                String parent1_blood = parent1.substring(0,parent1.length()-1);
                String parent1_RH = parent1.substring(parent1.length()-1);
                String parent2_blood = parent2.substring(0,parent2.length()-1);
                String parent2_RH = parent2.substring(parent2.length()-1);
                String [] parent1_bloods = table.get(parent1_blood);
                String [] parent2_bloods = table.get(parent2_blood);
                String [] parent1_RHs = table.get(parent1_RH);
                String [] parent2_RHs = table.get(parent2_RH);
                Set<String> set = new HashSet<>();
                for(int i = 0 ; i < parent1_bloods.length ; i++){
                    for(int j = 0 ; j < parent2_bloods.length ; j++){
                        for (int m = 0; m < parent1_RHs.length; m++) {
                            for (int n = 0; n < parent2_RHs.length; n++) {
                                String s1 = parent1_bloods[i];
                                String s2 = parent2_bloods[j];
                                String s3 = parent1_RHs[m];
                                String s4 = parent2_RHs[n];
                                for(int k = 0 ; k < s1.length() ; k++){
                                    for(int l = 0 ; l < s2.length() ; l++){
                                        char c1 = s1.charAt(k);
                                        char c2 = s2.charAt(l);
                                        char [] u = {c1,c2};
                                        Arrays.sort(u);
                                        String ans1 = new String(u);
                                        ans1 = map.get(ans1);
                                        for (int o = 0; o < s3.length(); o++) {
                                            for (int p = 0; p < s4.length(); p++) {
                                                char sign1 = s3.charAt(o);
                                                char sign2 = s4.charAt(p);
                                                char [] v = {sign1,sign2};
                                                Arrays.sort(v);
                                                String signs = new String(v);
                                                String ans2 = map.get(signs);
                                                String ans = ans1 + ans2 ;
                                                set.add(ans);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                sb.append( parent1 + " " + parent2 +" ");
                int sz = set.size();
                if( sz == 1 ){
                    for(String s :set){
                        sb.append(s);
                    }
                    sb.append('\n');
                } else {
                    sb.append("{");
                    int i = 0;
                    for (String s : set) {
                        i++;
                        if (i == sz) {
                            sb.append(s + "}").append('\n');
                        } else {
                            sb.append(s + ", ");
                        }
                    }
                }
            } else if( parent1.equals("?") ){
                Set<String> set = new HashSet<>();
                String parent2_blood = parent2.substring(0,parent2.length()-1);
                String parent2_RH = parent2.substring(parent2.length()-1,parent2.length());
                String [] parent2_bloods = table.get(parent2_blood);
                String [] parent2_RHs = table.get(parent2_RH);
                String child_blood = child.substring(0,child.length()-1);
                String child_RH = child.substring(child.length()-1,child.length());
                for (int i = 0; i < all_combination.length; i++) {
                    for (int j = 0; j < parent2_bloods.length; j++) {
                        String one = all_combination[i];
                        String two = parent2_bloods[j];

                        for (int k = 0; k < one.length(); k++) {
                            for (int l = 0; l < two.length(); l++) {
                                char c1 = one.charAt(k);
                                char c2 = two.charAt(l);
                                char [] a = {c1 , c2};
                                Arrays.sort(a);
                                String ans = a[0] + "" + a[1];
                                ans = map.get(ans);
                                if( ans.equals(child_blood) ){
                                    // work here
                                    // one
                                    String [] signs = table.get(parent2_RH);
                                    for (int q = 0; q < signs.length; q++) {
                                        for (int m = 0; m < RH_combination.length; m++) {
                                            String sign1 = signs[q];
                                            String sign2 = RH_combination[m];
                                            for (int n = 0; n < sign1.length(); n++) {
                                                for (int o = 0; o < sign2.length(); o++) {
                                                    char c3 = sign1.charAt(n);
                                                    char c4 = sign2.charAt(o);
                                                    char [] arr = {c3,c4};
                                                    Arrays.sort(arr);
                                                    String sum = new String(arr);
                                                    sum = map.get(sum);
                                                    if( sum.equals(child_RH) ){
                                                        String sign_sum = sign2 ;
                                                        sign_sum = map.get(sign_sum);
                                                        String blood = map.get(one);
                                                        String cnt = blood +""+ sign_sum ;
                                                        set.add(cnt);
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                int sz = set.size();
                int i = 0 ;
                if( sz == 0 ) {
                    sb.append(" IMPOSSIBLE ");
                }else if( sz == 1 ){
                    for(String s : set){
                        sb.append(s+" ");
                    }
                } else {
                    sb.append("{");
                    for (String s: set) {
                        i++ ;
                        if( i == sz ){
                            sb.append( s + "} " );
                        } else {
                            sb.append( s + ", " );
                        }
                    }
                }
                sb.append(parent2 + " " + child).append('\n');
            } else {
                Set<String> set = new HashSet<>();
                String p1_rh = parent1.substring(parent1.length()-1,parent1.length());
                String blood_p1 = parent1.substring(0,parent1.length()-1);
                String [] parent = table.get(blood_p1);
                String c_rh = child.substring(child.length()-1,child.length());
                String blood_c = child.substring(0,child.length()-1);
                for (int i = 0; i < all_combination.length; i++) {
                    for (int j = 0; j < parent.length; j++) {
                        String one = all_combination[i];
                        String two = parent[j];

                        for (int k = 0; k < one.length(); k++) {
                            for (int l = 0; l < two.length(); l++) {
                                char c1 = one.charAt(k);
                                char c2 = two.charAt(l);
                                char[] a = {c1, c2};
                                Arrays.sort(a);
                                String ans = a[0] + "" + a[1];
                                ans = map.get(ans);
                                if (ans.equals(blood_c)) {
                                    // work here
                                    String[] signs = table.get(p1_rh);
                                    for (int q = 0; q < signs.length; q++) {
                                        for (int m = 0; m < RH_combination.length; m++) {
                                            String sign1 = signs[q];
                                            String sign2 = RH_combination[m];
                                            for (int n = 0; n < sign1.length(); n++) {
                                                for (int o = 0; o < sign2.length(); o++) {
                                                    char c3 = sign1.charAt(n);
                                                    char c4 = sign2.charAt(o);
                                                    char[] arr = {c3, c4};
                                                    Arrays.sort(arr);
                                                    String sum = new String(arr);
                                                    sum = map.get(sum);
                                                    if (sum.equals(c_rh)) {
                                                        String sign_sum = sign2;
                                                        sign_sum = map.get(sign_sum);
                                                        String blood = map.get(one);
                                                        String cnt = blood + "" + sign_sum;
                                                        set.add(cnt);
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                sb.append(parent1);
                int sz = set.size();
                int i = 0 ;
                if( sz == 0 ) {
                    sb.append(" IMPOSSIBLE ");
                }else if( sz == 1 ){
                    for(String s : set){
                        sb.append(s+" ");
                    }
                } else {
                    sb.append(" {");
                    for (String s : set) {
                        i++;
                        if (i == sz) {
                            sb.append(s + "} ");
                        } else {
                            sb.append(s + ", ");
                        }
                    }
                }
                sb.append(child).append('\n');
            }
        }

        pr.print(sb.toString());
        br.close();
        pr.close();
    }
}
