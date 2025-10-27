import java.util.LinkedList;
import java.util.Random;


public class Player {
   public int playerNum;
   private LinkedList<Card> hand;
   public static int numSpoonsAvailable;
   public boolean hasSpoon;
   private int numMatches;
   private int matchValue;
  
   public Player(Player other){
       this.playerNum = other.playerNum;
       this.hand = other.hand;
       this.hasSpoon = other.hasSpoon;
       this.numMatches = other.numMatches;
       this.matchValue = other.matchValue;
      
   }
 
  
   public Player(int playerNum, Dealer dealer) {
       this.playerNum = playerNum;
       this.hand = dealer.deals(4);
       this.hasSpoon = false;
       this.numMatches = matchDetect(hand);
       this.matchValue = 0;
   }


   public int getPlayerNum(){
       return this.playerNum;
   }
   public int getNumMatches(){
       return this.numMatches;
   }
   public int getMatchValue(){
       return this.matchValue;
   }
   public LinkedList<Card> getHand(){
       return this.hand;
   }
   public boolean getHasSpoon(){
       return this.hasSpoon;
   }
  
   public int matchDetect(LinkedList<Card> hand) {
       Card previousCard = null; // initialize previousCard to null
       int numMatches = 0; // initialize the number of matches to 0
       int matchValue = -1; // initialize the match value to -1
       for (Card currentCard : hand) {
           if (previousCard != null && currentCard.equals(previousCard)) {
               numMatches++; // increment the number of matches
               matchValue = currentCard.getValue(); // set the match value to the current card's value
           }
           previousCard = currentCard;
       }
       return numMatches;
   }


   public Card takeTurn(Card passedCard) {
       hand.add(passedCard); // add the passed card to the player's hand
       int numMatches = matchDetect(hand); // detect how many matches are in the hand
       if (numMatches > 0) {
           // if there are matches, keep the card with the highest matching value
           Card highestMatch = null;
           for (Card card : hand) {
               if (card.getValue() == passedCard.getValue() && (highestMatch == null || card.getSuit() > highestMatch.getSuit())) {
                   highestMatch = card;
               }
           }
           hand.remove(highestMatch); // remove the highest matching card from the hand
           return highestMatch; // return the highest matching card to pass along
       } else {
           // if there are no matches, pass along a random card
           Random random = new Random();
           int randomIndex = random.nextInt(hand.size());
           Card cardToPass = hand.get(randomIndex);
           hand.remove(randomIndex); // remove the randomly chosen card from the hand
           return cardToPass; // return the randomly chosen card to pass along
       }
   }


   public void stealSpoon() {
       // Check if the player has already stolen a spoon
       if (hasSpoon) {
           System.out.println("You already stole a spoon!");
           return;
       }
      
       // Check if the player has 4 of a kind
       int matches = matchDetect(hand);
       if (matches == 4) {
           System.out.println("You have 4 of a kind! Steal a spoon!");
           hasSpoon = true;
           numSpoonsAvailable--;
           return;
       }
      
       // Check if a spoon has already been stolen
       if (numSpoonsAvailable == 0) {
           System.out.println("A spoon has been stolen! Steal a spoon!");
           hasSpoon = true;
           return;
       }
      
       System.out.println("You can't steal a spoon yet!");
   }
}
