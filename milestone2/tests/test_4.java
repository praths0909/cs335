import java.util.ArrayList;
import java.util.Collections;

public class ImportExample {
    public static void main(String args[]) {
        ArrayList myList = new ArrayList();
        myList.add(3);
        myList.add(1);
        myList.add(4);
        myList.add(1);
        myList.add(5);

        System.out.println("Original list: " + myList);

        Collections.sort(myList);

        System.out.println("Sorted list: " + myList);
    }
}
