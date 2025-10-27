import java.util.ArrayList;
import java.util.Scanner;
import java.util.LinkedList;




public class SpoonsDriver{
   public static void main(String[] args){
       int numPlayers = 3;
       Game game = new Game(numPlayers);//self explanatory
       game.play();
       System.out.print(game);
   }
}
