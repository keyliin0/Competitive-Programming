/*
	answer may overflow
	that's way using java is easier cause of biginteger class
*/
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class main {
    public static BigInteger [] dp = new BigInteger [1005];
    public static BigInteger calc (int rem) {
        if(rem == 0) return BigInteger.ONE;
        if(rem < 0) return BigInteger.ZERO;
        if(!dp[rem].equals(BigInteger.ZERO)) return dp[rem];
        BigInteger ret = BigInteger.ZERO;
        ret = ret.add(calc(rem - 1));
        ret = ret.add(calc(rem - 1));
        ret = ret.add(calc(rem - 2));
        ret = ret.add(calc(rem - 3));
        return dp[rem] = ret;
    }
    public  static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder out = new StringBuilder();
        StringTokenizer tk;
        //tk = new StringTokenizer(in.readLine());
        String s;
        while((s = in.readLine()) != null){
            int n = Integer.parseInt(s);
            for (int i = 0;i <= n;i++)
                dp[i] = BigInteger.ZERO;
            BigInteger ans = calc(n);
            String output = ans.toString();
            System.out.println(output);
        }
    }


}