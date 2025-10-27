public class PizzaDriver {
    public static void main(String[] args) {
        // Create some pizzas
        Pizza pizza1 = new Pizza("small", 1, 1, 0);
        Pizza pizza2 = new Pizza("large", 2, 2, 0);
        Pizza pizza3 = new Pizza(pizza2);

        // Create an order and add the pizzas to it
        PizzaOrder order = new PizzaOrder(3);
        order.addPizza(pizza1);
        order.addPizza(pizza2);
        order.addPizza(pizza3);

        // Print out the order details
        System.out.println(order);
    }
}
