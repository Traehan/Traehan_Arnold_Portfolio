public class Pizza {
    private String size;
    private int numCheeseToppings;
    private int numPepperoniToppings;
    private int numVeggieToppings;

    public Pizza() {
        size = "medium";
        numCheeseToppings = 0;
        numPepperoniToppings = 0;
        numVeggieToppings = 0;
    }

    public Pizza(String size, int numCheeseToppings, int numPepperoniToppings, int numVeggieToppings) {
        this.size = size;
        this.numCheeseToppings = numCheeseToppings;
        this.numPepperoniToppings = numPepperoniToppings;
        this.numVeggieToppings = numVeggieToppings;
    }

    public Pizza(Pizza otherPizza) {
        this.size = otherPizza.size;
        this.numCheeseToppings = otherPizza.numCheeseToppings;
        this.numPepperoniToppings = otherPizza.numPepperoniToppings;
        this.numVeggieToppings = otherPizza.numVeggieToppings;
    }

    public double calcCost() {
        double cost = 0;

        if (size.equals("small")) {
            cost = 10;
        } else if (size.equals("medium")) {
            cost = 12;
        } else if (size.equals("large")) {
            cost = 14;
        }

        cost += numCheeseToppings * 2;
        cost += numPepperoniToppings * 2;
        cost += numVeggieToppings * 2;

        return cost;
    }

    public String toString() {
        return "Size: " + size + "\nCheese Toppings: " + numCheeseToppings + "\nPepperoni Toppings: " + numPepperoniToppings + "\nVeggie Toppings: " + numVeggieToppings + "\nCost: $" + calcCost();
    }

    public boolean equals(Pizza otherPizza) {
        return (size.equals(otherPizza.size) && numCheeseToppings == otherPizza.numCheeseToppings && numPepperoniToppings == otherPizza.numPepperoniToppings && numVeggieToppings == otherPizza.numVeggieToppings);
    }

    // getters and setters omitted for simplicity
}
