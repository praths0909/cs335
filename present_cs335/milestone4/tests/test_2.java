//loops

public class loops {   
    int fil = 7;
    int sum=0;
    public static void main(String[] args) {
        System.out.println(fil);
    //    int a = 3;
    //    int b = 5;
    //    int c = a +b*b*10;
    //    System.out.println(c);
    // int sum=0;
    for(int i=0;i<5;i++){
        int j=0;
        while(j<5){
            int k=0;
            do{
                if(k%2==0){
                sum=sum+2;
                }
                else{
                    sum=sum+3;
                }
                k++;
            }
            while(k<5);
            j++;
        }
    }
    System.out.println(sum);
    }
}
