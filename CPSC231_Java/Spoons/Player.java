import java.util.LinkedList;

public class Player {
    private LinkedList<Card> m_hand;
    private boolean m_hasSpoon;
    
    public Player() {
        m_hand = new LinkedList<>();
        m_hasSpoon = false;
    }
    
    public void addToHand(Card card) {
        m_hand.add(card);
    }
    
    public Card playCard(int index) {
        return m_hand.remove(index);
    }
    
    public boolean hasSpoon() {
        return m_hasSpoon;
    }
    
    public void setHasSpoon(boolean hasSpoon) {
        m_hasSpoon = hasSpoon;
    }
    
    public int getHandSize() {
        return m_hand.size();
    }
    
    public Card getCard(int index) {
        return m_hand.get(index);
    }
    
    public LinkedList<Card> getHand() {
        return m_hand;
    }
}
