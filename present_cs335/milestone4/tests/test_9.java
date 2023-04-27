class Main {
  int fil = 7;
  public static int call(int a){
    return 2*a;
  }
  public static void main(String[] args) {
    System.out.println(fil);
    int a=0;
    while(a>0)
    a=a-1;
    a=call(a);
    System.out.println(a);
  }
}
