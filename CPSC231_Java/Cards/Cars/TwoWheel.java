public class TwoWheel extends Vehicle {
    private static final int NUM_WHEELS = 2;
    
    public TwoWheel() {}
    
    public TwoWheel(String make, String model, double price) {
        super(make, model, price);
    }
    
    public String toString() {
        return super.toString() + ", " + NUM_WHEELS + " wheels";
    }
    
    public boolean equals(Object o) {
        if (o == null || !(o instanceof TwoWheel)) {
            return false;
        }
        TwoWheel other = (TwoWheel) o;
        return super.equals(other);
    }
    
    public void drive() {
        System.out.println("Vroom vroom!");
    }
}
