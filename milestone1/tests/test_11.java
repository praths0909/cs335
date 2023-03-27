public class ExceptionHandlingExample {
    public static void main(String[] args) {
        int a = 5, b = 0;

        try {
            int c = a / b;
            System.out.println("Result: " + c);
        } catch (ArithmeticException e) {
            System.out.println("Exception: " + e.getMessage());
        }

        System.out.println("Program completed");
    }
}
