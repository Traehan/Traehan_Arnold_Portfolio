public class Motorcycle extends TwoWheel {
    private double weight;
    
    public Motorcycle() {}
    
    public Motorcycle(String make, String model, double price, double weight) {
        super(make, model, price);
        this.weight = weight;
    }
    
    public double getWeight() {
        return weight;
    }
    
    public void setWeight(double weight) {
        this.weight = weight;
    }
    
    public String toString() {
        return super.toString() + ", " + weight + " lbs";
    }
    
    public boolean equals(Object o) {
        if (o == null || !(o instanceof Motorcycle)) {
            return false;
        }
        Motorcycle other = (Motorcycle) o;
        return super.equals(other) && weight == other.weight;
    }
    
    public void drive() {
        System.out.println("Vroom!");
    }
}