import java.util.Scanner; 

public class LabProgram {
   public static void main(String[] args) {
      Scanner scnr = new Scanner(System.in);
      int number;
      double total;
      double max;
      double average;
      
      number = 0;
      total = 0.0;
      max = 0.0;
      average = 0.0;
      
      while (number >= 0.0) {
         total = total + number;
         number = scnr.nextInt();
      
      if (number > max){
         max = number;
      
      if (number < 0){
      System.out.print(max);
      System.out.printf("%.2f\n", average);
      }
      }
      }
   }
}