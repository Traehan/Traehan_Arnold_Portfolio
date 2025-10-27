public class Sedan extends FourWheel {
    private static final int NUM_WHEELS = 4;
    private int numCupHolders;
    
    public Sedan() {}
    
    public Sedan(String make, String model, double price, int numCupHolders) {
        super(make, model, price);
        this.numCupHolders = numCupHolders;
    }
    
    public int getNumCupHolders() {
        return numCupHolders;
    }
    
    public void setNumCupHolders(int numCupHolders) {
        this.numCupHolders = numCupHolders;
    }
    
    public String toString() {
        return super.toString() + ", " + NUM_WHEELS + " wheels, " + numCupHolders + " cup holders";
    }
    
    public boolean equals(Object o) {
        if (o == null || !(o instanceof Sedan)) {
            return false;
        }
        Sedan other = (Sedan) o;
        return super.equals(other) && numCupHolders == other.numCupHolders;
    }
    
    public void drive() {
        System.out.println("Honk honk!");
    }
}