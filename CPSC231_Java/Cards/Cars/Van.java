public class Van extends FourWheel {
    private static final int NUM_WHEELS = 4;
    private double bedLength;
    
    public Van() {}
    
    public Van(String make, String model, double price, double bedLength) {
        super(make, model, price);
        this.bedLength = bedLength;
    }
    
    public double getBedLength() {
        return bedLength;
    }
    
    public void setBedLength(double bedLength) {
        this.bedLength = bedLength;
    }
    
    public String toString() {
        return super.toString() + ", " + NUM_WHEELS + " wheels, " + bedLength + " feet bed";
    }
    
    public boolean equals(Object o) {
        if (o == null || !(o instanceof Van)) {
            return false;
        }
        Van other = (Van) o;
        return super.equals(other) && bedLength == other.bedLength;
    }
    
    public void drive() {
        System.out.println("Beep beep!");
    }
}