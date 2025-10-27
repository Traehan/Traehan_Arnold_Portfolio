public class FourWheel extends Vehicle {
    private static final int NUM_WHEELS = 4;
    
    public FourWheel() {}
    
    public FourWheel(String make, String model, double price) {
        super(make, model, price);
    }
    
    public String toString() {
        return super.toString() + ", " + NUM_WHEELS + " wheels";
    }
    
    public boolean equals(Object o) {
        if (o == null || !(o instanceof FourWheel)) {
            return false;
        }
        FourWheel other = (FourWheel) o;
        return super.equals(other);
    }
    
    public void drive() {
        System.out.println("Zoom zoom!");
    }
}

