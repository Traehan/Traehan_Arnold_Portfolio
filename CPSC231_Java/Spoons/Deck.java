import java.util.LinkedList;
import java.util.Random;

public class Deck {

    private LinkedList<Card> m_cards;

    // Default constructor to initialize a new deck of 52 cards
    public Deck() {
        m_cards = new LinkedList<>();
        for (int suit = 0; suit < 4; suit++) {
            for (int value = 2; value <= 14; value++) {
                m_cards.add(new Card(value, suit));
            }
        }
    }

    // Copy constructor to create a new deck from another deck
    public Deck(Deck other) {
        m_cards = new LinkedList<>();
        for (Card card : other.m_cards) {
            m_cards.add(new Card(card));
        }
    }

    // toString method to display each card currently in the deck
    @Override
    public String toString() {
        return m_cards.toString();
    }

    // size method to return the number of cards in the deck
    public int size() {
        return m_cards.size();
    }

    // deal method to remove and return a random card from the deck
    public Card deal() {
        if (m_cards.isEmpty()) {
            return null;
        }
        Random random = new Random();
        int index = random.nextInt(m_cards.size());
        return m_cards.remove(index);
    }
}
