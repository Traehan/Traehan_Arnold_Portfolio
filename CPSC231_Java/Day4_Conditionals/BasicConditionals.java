public class BasicConditionals{
    public static void main (String[] args){
        /*
         * BOOLEAN Expressions:
         * Statements that evaluate to either true or fals
         * OPERATORS: ==, !=, <, <=, >, >=
         * 
         * CHAINING BOOLEAN EXPRESSIONS
         * and ---> &&
         * or ----> ||
         * 
         */
        boolean g = true;
        boolean f = false;
        System.out.println(g && f); // false
        System.out.println(g || f); // true
        System.out.println(!g); // false

        int age = 21;
        if (age > 21) {
            System.out.println ("your best days are over :C");
        } else if (age < 21){
            System.out.println("you are still too young!");

        } else{
            System.out.println("you are 21!");
        }
    }
}