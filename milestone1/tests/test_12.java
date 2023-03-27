// Define an interface for all vehicles
interface Vehicle {
  void move();
}

// Define a base class for all cars
class Car implements Vehicle {
  String brand;

  public Car(String brand) {
    this.brand = brand;
  }

  public void move() {
    System.out.println("The " + this.brand + " car is moving.");
  }
}

// Define a subclass of Car for sports cars
class SportsCar extends Car {
  public SportsCar(String brand) {
    super(brand);
  }

  public void move() {
    System.out.println("The " + this.brand + " sports car is zooming!");
  }

  public void drift() {
    System.out.println("The " + this.brand + " sports car is drifting!");
  }
}

public class Main {
  public static void main(String[] args) {
    // Create a regular car and call its move() method
    Car myCar = new Car("Toyota");
    myCar.move();

    // Create a sports car and call its move() and drift() methods
    SportsCar mySportsCar = new SportsCar("Ferrari");
    mySportsCar.move();
    mySportsCar.drift();
  }
}
