public interface Shape {
    public double area();
    public double perimeter();
}

public class Rectangle implements Shape {
    private double length;
    private double width;

    public Rectangle(double length, double width) {
        this.length = length;
        this.width = width;
    }

    public double area() {
        return length * width;
    }

    public double perimeter() {
        return 2 * (length + width);
    }
}

public class Circle implements Shape {
    private double radius;

    public Circle(double radius) {
        this.radius = radius;
    }

    public double area() {
        return Math.PI * radius * radius;
    }

    public double perimeter() {
        return 2 * Math.PI * radius;
    }
}

public class InterfaceExample {
    public static void main(String[] args) {
        Shape[] shapes = new Shape[2];
        shapes[0] = new Rectangle(4, 5);
        shapes[1] = new Circle(3);

        for (Shape s : shapes) {
            System.out.println("Area: " + s.area());
            System.out.println("Perimeter: " + s.perimeter());
        }
    }
}
