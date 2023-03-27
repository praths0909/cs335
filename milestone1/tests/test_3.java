import java.util.Scanner;

public class DoWhileSwitchExample {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int choice;

        do {
            System.out.println("Please choose an option:");
            System.out.println("1. Print 'Hello, world!'");
            System.out.println("2. Print the current date and time");
            System.out.println("3. Exit");
            System.out.print("Your choice: ");
            choice = input.nextInt();

            switch (choice) {
                case 1:
                    System.out.println("Hello, world!");
                    break;
                case 2:
                    System.out.println("The current date and time is: " + new java.util.Date());
                    break;
                case 3:
                    System.out.println("Goodbye!");
                    break;
                default:
                    System.out.println("Invalid choice.");
                    break;
            }
        } while (choice != 3);
    }
}
