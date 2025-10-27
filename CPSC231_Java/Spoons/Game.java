import java.util.LinkedList;

public class Game {
    private Player[] m_players;
    private Dealer m_dealer;
    private int m_currentPlayerIndex;
    
    public Game(int numPlayers) {
        m_players = new Player[numPlayers];
        for (int i = 0; i < numPlayers; i++) {
            m_players[i] = new Player();
        }
        m_dealer = new Dealer();
        m_currentPlayerIndex = 0;
    }
    
    public void play() {
        LinkedList<Card> cardsDealt = m_dealer.deals(m_players.length + 1);
        for (int i = 0; i < m_players.length; i++) {
            m_players[i].addToHand(cardsDealt.removeFirst());
        }
        Card spoonCard = cardsDealt.removeFirst();
        int currentPlayerIndex = m_currentPlayerIndex;
        while (true) {
            Player currentPlayer = m_players[currentPlayerIndex];
            Card card = currentPlayer.playCard(0);
            System.out.println("Player " + (currentPlayerIndex + 1) + " played " + card);
            if (card.equals(spoonCard)) {
                System.out.println("Player " + (currentPlayerIndex + 1) + " got a spoon!");
                currentPlayer.setHasSpoon(true);
                if (checkForWin()) {
                    return;
                }
            }
            currentPlayerIndex = (currentPlayerIndex + 1) % m_players.length;
        }
    }
    
    
    public boolean checkForWin() {
        for (Player player : m_players) {
            if (player.hasSpoon()) {
                int count = 0;
                for (Player otherPlayer : m_players) {
                    if (player != otherPlayer && !otherPlayer.hasSpoon()) {
                        count++;
                    }
                }
                if (count == m_players.length - 1) {
                    System.out.println("Player " + (getPlayerIndex(player) + 1) + " wins!");
                    return true;
                }
            }
        }
        return false;
    }
    
    private int getPlayerIndex(Player player) {
        for (int i = 0; i < m_players.length; i++) {
            if (m_players[i] == player) {
                return i;
            }
        }
        return -1;
    }
}
