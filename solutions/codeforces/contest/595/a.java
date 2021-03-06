import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.StringTokenizer;

public class template {
  private static final PrintWriter out = new PrintWriter(System.out);
  private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  private static StringTokenizer st;

  private static String next() {
    while (st == null || !st.hasMoreElements()) {
      try {
        st = new StringTokenizer(br.readLine());
      } catch (final IOException e) {
        e.printStackTrace();
      }
    }
    return st.nextToken();
  }

  private static int nextInt() {
    return Integer.parseInt(next());
  }

  private static long nextLong() {
    return Long.parseLong(next());
  }

  private static double nextDouble() {
    return Double.parseDouble(next());
  }

  private static String nextLine() {
    final String res = null;
    while (res == null || res.isEmpty()) {
      try {
        return br.readLine();
      } catch (final IOException e) {
        e.printStackTrace();
      }
    }
    return res;
  }

  public static void main(final String[] args) {
    int n, m;
    n = nextInt();
    m = nextInt();

    int ans = 0;
    while (n-- > 0) {
      for (int i = 0; i < m; ++i) {
        int a = nextInt(), b = nextInt();
        if (a == 1 || b == 1)
          ++ans;
      }
    }
    System.out.print(ans);
  }
}
