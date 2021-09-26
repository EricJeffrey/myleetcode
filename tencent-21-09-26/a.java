import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
    static ArrayList<Integer> primelist = new ArrayList<>();
    static boolean isprime(int x) {
        for (long i = 2; i * i  <= x; i++) {
            if (x % i == 0) return false;
        }
        return true;
    }
    static void getallprimes() {
        for (int i = 2; i <= 100000; i++) {
            if (isprime(i)) primelist.add(i);
        }
    }

    static int lower_bound(ArrayList<Integer> array, int key) {
        int low = 0, high = array.size();
        int mid;
        while (low < high) {
            mid = low + (high - low) / 2;
            if (key <= array.get(mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        if (low < array.size() && array.get(low) < key) {
            low++;
        }
        return low;
    }

    static int nextprime(int x) {
        return primelist.get(lower_bound(primelist, x));
    }

    public static void main(String[] args) {
        getallprimes();
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        for (int i = 0; i < t; i++) {
            int x = scanner.nextInt();
            int u = nextprime(1 + x);
            long v = nextprime(u + x);
            System.out.println(u * v);
        }
    }
}
