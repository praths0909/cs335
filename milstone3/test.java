import java.util.ArrayList;
import java.util.Collections;

class Main {
    public static void main(String[] args) {

        int a[]=new int[5];
        for(int i=0;i<5;i++){
            for(int j=i;j<5;j++)
            if(a[i]<a[j]){
                int t;t=a[i];a[i]=a[j];a[j]=t;
            }
        }

    }
}
