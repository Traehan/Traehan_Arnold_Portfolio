import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Random;


public class Game {
   ArrayList<Player> players;
   private Dealer dealer;
   private int numSpoonsAvailable;


   public Game(int numPlayers) {
       players = new ArrayList<Player>();
       this.dealer = new Dealer();//setting dealer
       this.numSpoonsAvailable = numPlayers - 1;//one less spoon than amount of players
       for (int i = 0; i < numPlayers; i++) {
           Player c = new Player(i, dealer);//setting overloaded player to add to to arraylist of players
           players.add(c);
       }
   }


   public Dealer getDealer() {
       return dealer;
   }


   public int getNumSpoons() {
       return numSpoonsAvailable;
   }


   public void setDealer(Dealer d) {
       dealer = d;
   }


   public void play() {
       while (numSpoonsAvailable > 0) {
           Deck j = new Deck();//set deck
           Player currentPlayer = players.get(0);//getting the first player
           Player nextPlayer;//having next player to run the turns
           LinkedList<Card> discardPile = new LinkedList<Card>();//discard pile initiation
           Card passedCard = new Card(dealer.deals(1).get(0));//cannot return a taketurn without a passedcard as parameter, so drawing first card
           while (numSpoonsAvailable > 0) {
               for (Player p : players) {//enhanced loop to loop around every card for every players
                   passedCard = p.takeTurn(passedCard);
                   p.stealSpoon();
                   numSpoonsAvailable -= 1;
                   if (numSpoonsAvailable == 0) {//stops game once theres no spoons
                       break;
                   }
               }
               discardPile.add(passedCard);//the last passed card that is equal to the taketurn of the last player is discarded
               passedCard = new Card(dealer.deals(1).get(0));//get new passed card for taketurn method and passed around
           }
           Player loser = null;
           for (Player k : players) {
               if (k.hasSpoon == false) {
                   loser = new Player(k);
               }//finding loser so can print
           }
           System.out.println("Game over! Player number " + loser.getPlayerNum() + " is a loser!");
           break;
       }
   }
}




