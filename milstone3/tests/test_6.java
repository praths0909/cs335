import java.util.*;

public class Example {
    public static void main(String[] args) {
        // Create a new ArrayList object
        ArrayList list = new float[3];

        // Add some elements to the list
       list[0]=1.0;
       list[1]=2.0;
       list[2]=3.0;
        float ans=0;
        // Print out the elements in the list
        for (int num : list) {
            ans=ans+num;
        }
    }
}
