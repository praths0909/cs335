public class ExceptionHandlingExample {
    public static void main(String[] args) {
        int a = 5, b = 0;

        try {
            int c = a / b;
           
        } catch (ArithmeticException e) {

           int d=a*b;
        }

       
    }
}
