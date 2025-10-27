import java.util.LinkedList;

public class Dealer {
    private Deck m_deck;

    public Dealer() {
        m_deck = new Deck();
    }

    public LinkedList<Card> deals(int n) {
        LinkedList<Card> dealtCards = new LinkedList<Card>();
        for (int i = 0; i < n; i++) {
            Card card = m_deck.deal();
            if (card != null) {
                dealtCards.add(card);
            } else {
                break;
            }
        }
        return dealtCards;
    }

    public int size() {
        return m_deck.size();
    }

    public String toString() {
        return m_deck.toString();
    }
}
