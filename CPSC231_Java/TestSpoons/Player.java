import java.util.LinkedList;

public class Player {
    private int m_playerNum;
    private LinkedList<Card> m_hand;
    private static int m_numSpoonsAvailable = 4; // shared across all instances
    private boolean m_hasSpoon;

    public Player(int playerNum, Dealer dealer) {
        m_playerNum = playerNum;
        m_hand = new LinkedList<>();
        for (int i = 0; i < 4; i++) {
            m_hand.add(dealer.deals(1).get(0));
        }
        m_hasSpoon = false;
    }

    public Card takeTurn(Card cardPassed) {
        m_hand.add(cardPassed);
        // Choose a card to pass to the left (arbitrary choice for now)
        Card cardToPass = m_hand.get(0);
        m_hand.remove(0);

        // Check if 4 of a kind has been achieved
        int numMatches = 0;
        int matchValue = -1;
        for (Card card : m_hand) {
            int value = card.getValue();
            if (value == matchValue) {
                numMatches++;
            } else if (numMatches == 0) {
                matchValue = value;
                numMatches++;
            } else {
                numMatches = 0;
                matchValue = -1;
            }
            if (numMatches == 4) {
                m_hasSpoon = true;
                m_numSpoonsAvailable--;
                break;
            }
        }

        // Check if a spoon has been stolen
        if (m_hasSpoon && Math.random() < 0.5) {
            m_hasSpoon = false;
            m_numSpoonsAvailable--;
        }

        return cardToPass;
    }

    public void stealSpoon() {
        m_hasSpoon = true;
        m_numSpoonsAvailable--;
    }

    public boolean hasSpoon() {
        return m_hasSpoon;
    }

    public int getPlayerNum() {
        return m_playerNum;
    }

    public LinkedList<Card> getHand() {
        return m_hand;
    }
}
