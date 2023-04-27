

public class Example {
    int fil = 7;
    public static int fact2(int n) {
        int ans;
        if (n == 0) {
            return 1;
        } else {
            ans = n;
            return ans;
        }
    }
    public static int fact(int n) {
        int ans;
        if (n == 0) {
            return 1;
        } else {
            ans = n*fact2(n-1);
            return ans;
        }
    }

    public static void main() {
        System.out.println(fil);
        int n = 5;
        System.out.println(n);
        n = fact(n); 
        System.out.println(n);
    }
}
