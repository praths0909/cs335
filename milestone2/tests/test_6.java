import java.util.*;

public class Example {
    public static void main(String[] args) {
        // Create a new ArrayList object
        ArrayList list = new ArrayList();

        // Add some elements to the list
        list.add("apple");
        list.add("banana");
        list.add("cherry");

        // Print out the elements in the list
        for (String fruit : list) {
            System.out.println(fruit);
        }
    }
}
