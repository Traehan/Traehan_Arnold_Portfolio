public class Driver {
    public static void main(String[] args) {
        
        Vehicle v1 = new Vehicle("Toyota", "Camry", 25000.00);
        Sedan s1 = new Sedan("Honda", "Accord", 30000.00, 4);
        Van v2 = new Van("Ford", "Transit", 35000.00, 10.0);
        Motorcycle m1 = new Motorcycle("Harley Davidson", "Sportster", 12000.00, 600.0);
        
        
        System.out.println(v1);
        System.out.println(s1);
        System.out.println(v2);
        System.out.println(m1);
        
        
        v1.drive();  
        s1.drive();  
        v2.drive();  
        m1.drive();  
        
        
        Vehicle v3 = new Vehicle("Toyota", "Camry", 25000.00);
        
        
        Sedan s2 = new Sedan("Honda", "Accord", 30000.00, 4);
        
        
        Van v4 = new Van("Ford", "Transit", 35000.00, 10.0);
        
        
        Motorcycle m2 = new Motorcycle("Harley Davidson", "Sportster", 12000.00, 600.0);
        
    }
}
