import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        for (int i = 0; i < t; i++) {
            int n = scanner.nextInt();
            int[] a = new int[n];
            int[] dp = new int[n];
            for (int j = 0; j < n; j++) {
                a[j] = scanner.nextInt();
                dp[j] = a[j];
            }
            int res = dp[n - 1];
            for (int j = n - 1; j >= 0; j--) {
                int u = a[j];
                if (j + u < n)
                    dp[j] += dp[j + u];
                res = Math.max(dp[j], res);
            }
            System.out.println(res);
        }
    }
}

