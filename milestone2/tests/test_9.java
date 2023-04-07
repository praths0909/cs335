class Main {
  public static int call(int a){
    return 2*a;
  }
  public static void main(String[] args) {
    int a=0;
    for(int i=0;i<100;i++)
    a+=1;
    while(a>0)
    a-=1;
    a=call(a);
      do {
        a=a+2;
      }    
      while(a<10);
  }
}
