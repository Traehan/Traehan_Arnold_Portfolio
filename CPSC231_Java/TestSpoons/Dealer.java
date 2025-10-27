import java.util.LinkedList;

public class Dealer {
    
    private Deck m_deck;
    
    // default constructor
    public Dealer() {
        m_deck = new Deck();
    }
    
    // deals n cards randomly from the deck
    public LinkedList<Card> deals(int n) {
        LinkedList<Card> dealtCards = new LinkedList<Card>();
        for (int i = 0; i < n; i++) {
            if (m_deck.size() > 0) {
                dealtCards.add(m_deck.deal());
            }
        }
        return dealtCards;
    }
    
    // size method
    public int size() {
        return m_deck.size();
    }
    
    // toString method
    public String toString() {
        return m_deck.toString();
    }
    
}
