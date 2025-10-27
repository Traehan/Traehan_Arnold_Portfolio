import java.util.Scanner;

public class LabProgram {
   public static void main(String[] args) {
      Scanner scnr = new Scanner(System.in);
      char letter;
      String sentence;
      int count;
      
      letter = scnr.next("what letter");
      sentence = scnr.next("Give me a sentence");
      count = 0;
      
      for (int i = 0; i < sentence.length(); i++){
         if(sentence.charAt(i) == letter){
         count += 1;
      }
      }
      if (count > 1){
      System.out.print(count + " " + letter + "'s");
      }
      else if (count == 0){
         System.out.print(count + " " + letter + "'s");
      }
      else{
         System.out.print(count + " " + letter);
      }
      }
   }




   import java.util.Scanner; 

public class LabProgram {
   public static void main(String[] args) {
      Scanner scnr = new Scanner(System.in);
      String userString;
      // Add more variables as needed

      userString = scnr.next();
      /* Type your code here. */
   }
}