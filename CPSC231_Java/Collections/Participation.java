import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Random; 

        public class Participation{
          public static void main(String[] args){
            
            Random random = new Random();
        
            ArrayList<Integer> al = new ArrayList<Integer>();
            LinkedList<Integer> ll = new LinkedList<Integer>();
        
           
            for (int i = 0; i<100000; ++i){
              al.add(random.nextInt()); 
              ll.add(random.nextInt());
            }
        
            int sumAl = 0;
            int randIndex;
        
          
            double alTimeBefore = System.currentTimeMillis();
        
            
            for (int i = 0; i<20000; ++i){
              randIndex = random.nextInt(100000);
              sumAl += al.get(randIndex);
            }
            
            double alTimeAfter = System.currentTimeMillis();
            
            double alTimeTotal =  alTimeAfter - alTimeBefore;
            
            System.out.println("ARRAY LIST \n\tThe sum: " + sumAl
                                + "\n\tTime elapsed: " + alTimeTotal);
        
            int sumLl = 0;
        
            
            double llTimeBefore = System.currentTimeMillis();
        
            
            for (int i = 0; i<20000; ++i){
              randIndex = random.nextInt(100000);
              sumLl += ll.get(randIndex);
            }
        
            
            double llTimeAfter = System.currentTimeMillis();
           
            double llTimeTotal =  llTimeAfter- llTimeBefore;
            
            System.out.println("linked List \n\tThe sum: " + sumLl
                                + "\n\tTime elapsed: " + llTimeTotal);
        
          }
        }
        