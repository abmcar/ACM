import java.io.BufferedInputStream;
import java.util.Scanner;

class Main {
    public static Scanner scanner = new Scanner(new BufferedInputStream(System.in));
    public static int[] nums = new int[233];

    public static void main(String[] args) {
        String oriString = scanner.next();
        int ans = 0;
        for (int i = 0; i < oriString.length(); i += 2)
            nums[i / 2] = (oriString.charAt(i) - '0');
        for (int i = 0; i < oriString.length() / 2 + 1; i++) {
            if (nums[i] == 0) {
                int nowMax = 0;
                for (int j = i + 1; j <= oriString.length() / 2 + 1; j++)
                    if (nums[j] == 1) {
                        nowMax = j - i;
                        break;
                    }
                for (int j = i - 1; j >= 0; j--)
                    if (nums[j] == 1) {
                        nowMax = Math.min(nowMax, i - j);
                        break;
                    }
                ans = Math.max(ans, nowMax);
            }
        }
        System.out.println(ans);
    }
}
