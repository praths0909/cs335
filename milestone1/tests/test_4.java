package mypackage;

protected class MyProtectedClass {
    private int myPrivateInt = 10;

    protected void printValue() {
        System.out.println("myPrivateInt = " + myPrivateInt);
    }
}

public class MyClass extends MyProtectedClass {
    public static void main(String[] args) {
        MyClass myClass = new MyClass();
        myClass.printValue();
    }
}
