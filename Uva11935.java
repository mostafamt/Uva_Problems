import java.io.*;

public class Uva11935
{
    static final double EPS = 0.0005 ;
    static final int MAX = 50 ;
    static String [] events ;
    static int idx ;

    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringBuilder sb = new StringBuilder();
        String str ;
        while( !( str = br.readLine() ).equals("0 Fuel consumption 0") ){
            events = new String[MAX] ;
            idx = 0 ;
            while( true ){
                events[idx++] = str ;
                if( str.matches(".+Goal") ){
                    break ;
                }
                str = br.readLine();
            }
            double low = 0.0 ;
            double high = 1000000000.0;
            while( high - low >= EPS ){
                double mid = (low+high)/2.0 ;

                if( simulate(mid) ){
                    high = mid ;
                } else {
                    low = mid ;
                }

            }
            sb.append( String.format("%.3f",high) ).append("\n");
        }
        pw.print(sb.toString());
        br.close();
        pw.close();
    }

    static boolean simulate( double fuel )
    {
        Jeep jeep = new Jeep(fuel);

        for (int i = 0; i < idx ; i++) {

            String[] a = events[i].split(" ");
            int size = a.length;

            if (events[i].matches("(.)+Fuel consumption(.)+")) {
                int distance = Integer.parseInt(a[0]);
                boolean can = jeep.move(distance);
                if (!can) {
                    return false;
                }
                int consumption = Integer.parseInt(a[size - 1]);
                jeep.change_cosumption(consumption);
            } else if (events[i].matches(".+Leak")) {
                int d = Integer.parseInt(a[0]);
                boolean can = jeep.move(d);
                if (!can) {
                    return false;
                }
                jeep.set_new_leak();
            } else if (events[i].matches(".+Gas station")) {
                int d = Integer.parseInt(a[0]);
                boolean can = jeep.move(d) ;
                if( !can ){
                    return false ;
                }
                jeep.gas_station(fuel);
            } else if (events[i].matches(".+Mechanic")) {
                int d = Integer.parseInt(a[0]);
                boolean can = jeep.move(d);
                if( !can ){
                    return false ;
                }
                jeep.fix_all();
            } else {
                Integer d = Integer.parseInt(a[0]) ;
                boolean can = jeep.move(d) ;
                if( !can ){
                    return false ;
                }
            }
        }



        return true ;
    }


    static class Jeep
    {
        int consumption ;
        double distance ;
        double fuel ;
        int num_of_leaks;

        public Jeep(double fuel)
        {
            this.consumption = 0 ;
            this.distance = 0 ;
            this.num_of_leaks = 0 ;
            this.fuel = fuel ;
        }

        public boolean move(int new_distance)
        {
            double d = (new_distance - distance)/100.0 ;
            fuel -= d * consumption ;
            fuel -= (new_distance - distance) * this.num_of_leaks;
            distance = new_distance ;
            return fuel > 0 ? true : false ;
        }

        public void change_cosumption(int consumption)
        {
            this.consumption = consumption ;
        }

        public void set_new_leak()
        {
            this.num_of_leaks++ ;
        }

        public void fix_all()
        {
            this.num_of_leaks = 0 ;
        }

        public void gas_station(double fuel)
        {
            this.fuel = fuel ;
        }

    }

}

