//recursion
public class test {
        int fil = 7;
    public class nestedtest{
    public static int factorial(int n) {
        int ans;
        if (n == 0) {
            return 1;
        } else {
            ans = n*factorial(n-1);
            return ans;
        }
        // return 120;
    }

    public static int fibonacci(int n){
        if(n==0){
            return 1;
        }
        else if(n==1){
            return 1;
        }
        else{
        int r1=fibonacci(n-1);
        int r2=fibonacci(n-2);
        return r1+r2;
        }
    }

    public static void main() {
        System.out.println(fil);
        long p=5;
        int n=(int)(p);
        // System.out
        int r,m;
        System.out.println(n);
        r = factorial(n); 
        System.out.println(r);
        int []a=new int[10];
        for(int i=0;i<10;i++){
            int b=fibonacci(i);
            a[i]=b;
            int q=a[i];
            System.out.println(q);
        }
        r=7;
        n=5;
        do{
            if(n%3==1){
            r=(r*r)/r&4|6^10;}
            else {
                r=(r*4)/r&4|6^10;
            }
            n--;
            System.out.println(r);
        }
        while(n>0);
        for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
          for(int k=0;k<2;k++){
            for(int l=0;l<3;l++){
              a[i][j][k][l]=i+j+k+l;
              int q=a[i][j][k][l];
              System.out.println(q);
            }
          }
        }
      }

    }
}
}