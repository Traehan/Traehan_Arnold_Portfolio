public class PizzaOrder {
    private Pizza[] order;
    private int numPizzas;

    public PizzaOrder() {
        order = new Pizza[1];
        order[0] = new Pizza();
        numPizzas = 1;
    }

    public PizzaOrder(int numPizzas) {
        order = new Pizza[numPizzas];

        for (int i = 0; i < numPizzas; i++) {
            order[i] = new Pizza();
        }

        this.numPizzas = numPizzas;
    }

    public int addPizza(Pizza pizza) {
        if (numPizzas >= order.length) {
            return -1;
        }

        order[numPizzas] = pizza;
        numPizzas++;

        return 1;
    }

    public double calcTotal() {
        double total = 0;

        for (int i = 0; i < numPizzas; i++) {
            total += order[i].calcCost();
        }

        return total;
    }

    public String toString() {
        String orderString = "";

        for (int i = 0; i < numPizzas; i++) {
            orderString += "Pizza " + (i+1) + ":\n" + order[i].toString() + "\n\n";
        }
        return orderString;
    }
}

