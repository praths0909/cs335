public class test {
  // int a=2;
  // int c;
  // int a=2;
  // int b=3;
  // public static int foo(){
  //   return 8;
  // }
  public static void main(){
    // // int b=a;
    // a=3;
    // System.out.println(a);
    // int k=0;
    int [][]b=new int[3][3];
    for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
        b[i][j]=i+j;
        int f = i +j;
        int g = b[i][j];
      System.out.println(f);
      System.out.println(g);
      }
    }
    for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
        // b[i][j]=i+j;
        // int f = i +j;
        int g = b[i][j];
      // System.out.println(f);
      System.out.println(g);
      }
    }
    // for(int j=0;j<2;j=j+1){
    //   i=i+1;
    // // }
    // int i = 0;
    // int j = 0;
    // int p;
    // p = b[i][j];
    // System.out.println(p);
  }
}