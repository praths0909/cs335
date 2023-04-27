//arrays
public class test_1{
  int fil = 7;
    public void main() {
      System.out.println(fil);
      int[][][][] a = new int[3][4][2][3];
      // int p;
        a[1][2][1][0] = 2;
       int p =a[1][2][1][0];
      System.out.println(p);

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

      int b[][]=new int[5][6];
      for(int i=0;i<5;i++){
        for(int j=0;j<6;j++){
          // System.out.println
          b[i][j]=i*j;
          int r=b[i][j];
          System.out.println(r);
        }
      }
    }
}
