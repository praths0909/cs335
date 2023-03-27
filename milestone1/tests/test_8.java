public class Calculator {
    public int add(int a, int b) {
        return a + b;
    }

    public double add(double a, double b) {
        return a + b;
    }

    public int add(int a, int b, int c) {
        return a + b + c;
    }

    public static void main(String[] args) {
        Calculator calculator = new Calculator();
        
        int sum1 = calculator.add(2, 3);
        double sum2 = calculator.add(2.5, 3.5);
        int sum3 = calculator.add(2, 3, 4);

        System.out.println("Sum of 2 and 3: " + sum1);
        System.out.println("Sum of 2.5 and 3.5: " + sum2);
        System.out.println("Sum of 2, 3, and 4: " + sum3);
    }
}
