public class Vehicle {
    private String make;
    private String model;
    private double price;
    
    public Vehicle() {}
    
    public Vehicle(String make, String model, double price) {
        this.make = make;
        this.model = model;
        this.price = price;
    }
    
    public String getMake() {
        return make;
    }
    
    public String getModel() {
        return model;
    }
    
    public double getPrice() {
        return price;
    }
    
    public void setMake(String make) {
        this.make = make;
    }
    
    public void setModel(String model) {
        this.model = model;
    }
    
    public void setPrice(double price) {
        this.price = price;
    }
    
    public String toString() {
        return make + " " + model + ", $" + price;
    }
    
    public boolean equals(Object o) {
        if (o == null || !(o instanceof Vehicle)) {
            return false;
        }
        Vehicle other = (Vehicle) o;
        return make.equals(other.make) && model.equals(other.model) && price == other.price;
    }
    
    public void drive() {
        System.out.println("Vroom vroom!");
    }
}