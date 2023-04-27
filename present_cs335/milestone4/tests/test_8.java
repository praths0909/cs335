class ttttt {
  int fil = 7;
  public static void main(String[] args) {
    System.out.println(fil);
    // Create a regular car and call its move() method
    int[][] arr  = new int[3][3];
    int a = 0;
    for(int i = 0;i<3;i++){
      for(int j = 0;j<3;j++){
        arr[i][j] = i+j;
        // a = a+1;
      }
    }
    int p = arr[0][0];
    System.out.println(p);
  }
}
