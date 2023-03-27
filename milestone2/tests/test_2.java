public class JavaStyleDeclarationsExample {
    private int myPrivateInt = 10;
    protected String myProtectedString = "Hello, world!";
    public double myPublicDouble = 3.14159;
    static boolean myStaticBoolean = true;
    int[][][] a = new int[10][20][30];
    int b = 40;
    int b = 30;
    public void printValues(String[] args) {
        System.out.println("myPrivateInt = " + myPrivateInt);
        System.out.println("myProtectedString = " + myProtectedString);
        System.out.println("myPublicDouble = " + myPublicDouble);
        System.out.println("myStaticBoolean = " + myStaticBoolean);

    }

    public static void main(String[] args) {
        JavaStyleDeclarationsExample example = new JavaStyleDeclarationsExample();
        example.printValues();
    }
}
