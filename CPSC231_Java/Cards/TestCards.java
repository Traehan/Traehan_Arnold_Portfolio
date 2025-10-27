import java.util.LinkedList;

public class TestCards {
    public static void main(String[] args) {
        // Test the Card class
        Card card1 = new Card(Card.ACE, Card.SPADES);
        Card card2 = new Card(Card.JACK, Card.HEARTS);
        Card card3 = new Card(7, Card.CLUBS);
        System.out.println(card1);
        System.out.println(card2);
        System.out.println(card3);
        System.out.println(card1.equals(new Card(Card.ACE, Card.HEARTS)));
        
        // Test the Deck class
        Deck deck1 = new Deck();
        System.out.println(deck1);
        System.out.println(deck1.size());
        Card dealtCard = deck1.deal();
        System.out.println(dealtCard);
        System.out.println(deck1.size());
        System.out.println(deck1);
        Deck deck2 = new Deck(deck1);
        System.out.println(deck2);
        System.out.println(deck2.size());
        
        // Test the Dealer class
        Dealer dealer = new Dealer();
        System.out.println(dealer);
        System.out.println(dealer.size());
        LinkedList<Card> dealtCards = dealer.deals(3);
        System.out.println(dealtCards);
        System.out.println(dealer.size());
        dealtCards = dealer.deals(50);
        System.out.println(dealtCards);
        System.out.println(dealer.size());
    }
}
