import java.util.LinkedList;
import java.util.Random;

public class Deck {
    
    private LinkedList<Card> m_cards;
    
    // default constructor - creates a fresh deck of 52 cards
    public Deck() {
        m_cards = new LinkedList<Card>();
        for (int s = Card.HEARTS; s <= Card.DIAMONDS; s++) {
            for (int v = Card.ACE; v <= Card.KING; v++) {
                m_cards.add(new Card(v, s));
            }
        }
    }
    
    // copy constructor
    public Deck(Deck other) {
        m_cards = new LinkedList<Card>();
        for (Card c : other.getCards()) {
            m_cards.add(new Card(c));
        }
    }
    
    // getters and setters
    public LinkedList<Card> getCards() {
        return m_cards;
    }
    
    public void setCards(LinkedList<Card> cards) {
        m_cards = cards;
    }
    
    // toString method
    public String toString() {
        return m_cards.toString();
    }
    
    // size method
    public int size() {
        return m_cards.size();
    }
    
    // deal method - removes a random card from the list and returns it
    public Card deal() {
        Random random = new Random();
        int index = random.nextInt(m_cards.size());
        return m_cards.remove(index);
    }
    
}
