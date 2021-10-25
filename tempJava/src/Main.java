import java.io.BufferedInputStream;
import java.util.Scanner;

class Main {
    public static int n, m, p, q, t;
    public static Scanner scanner = new Scanner(new BufferedInputStream(System.in));
    public static int N = 3333;
    public static int Mod = 555555555;
    public static Long[][] an = new Long[N + 10][N + 10];

    public static void main(String[] args) {
        for (int i = 0; i < N; i++)
            an[i][1] = 1L;
        for (int i = 0; i < N; i++)
            for (int j = 1; j <= i; j++)
                an[i][j] = (an[i - 1][j] + an[i - 1][j - 1]) % Mod;
        get();
        long k = 0;
        int m1 = min(n, p);
        int m2 = min(n, p);
        for (int i = 0; i <= m1; i++)
            for (int j = 0; j <= m2; j++)
                if ((i * m) + (j * n) - (2 * i * j) == t && (p - i) % 2 == 0 && (q - j) % 2 == 0)
                    k = (k + an[n][i] * an[m][j] % Mod * (an[(p - i) / 2 + n - 1][n - 1] * an[(q - j) / 2 + m - 1][m - 1] % Mod)) % Mod;
        System.out.println(k);
    }

    private static void get() {
        n = scanner.nextInt();
        m = scanner.nextInt();
        p = scanner.nextInt();
        q = scanner.nextInt();
        t = scanner.nextInt();
    }

    private static int min(int n, int p) {
        return Math.min(n, p);
    }
}
