import java.util.LinkedList;

public class Game {
    private Dealer m_dealer;
    private Player[] m_players;
    private int m_numSpoons;
    
    public Game() {
        m_dealer = new Dealer();
        m_numSpoons = 4;
        
        // Initialize the players
        m_players = new Player[3];
        for (int i = 0; i < 3; i++) {
            m_players[i] = new Player(i + 1, m_dealer);
        }
    }
    
    public void play() {
            int numPlayers = m_players.length;
            while (m_numSpoonsLeft > 0) {
                for (int i = 0; i < numPlayers; i++) {
                    Player currentPlayer = m_players[i];
                    Player leftPlayer = m_players[(i + numPlayers - 1) % numPlayers];
                    LinkedList<Card> hand = m_dealer.deals(1);
                    Card passedCard = leftPlayer.getHand().getFirst();
                    leftPlayer.getHand().removeFirst();
                    leftPlayer.getHand().addLast(hand.getFirst());
                    currentPlayer.getHand().addLast(passedCard);
                    Card chosenCard = currentPlayer.takeTurn(passedCard);
                    currentPlayer.getHand().remove(chosenCard);
                    currentPlayer.passCard(chosenCard, m_players[(i + 1) % numPlayers]);
                    if (currentPlayer.hasFourOfAKind()) {
                        currentPlayer.stealSpoon();
                        m_numSpoonsLeft--;
                    }
                }
            }
        }
        
    public int getNumSpoons() {
        return m_numSpoons;
    }
    
    public void setNumSpoons(int numSpoons) {
        m_numSpoons = numSpoons;
    }
    
    public Player[] getPlayers() {
        return m_players;
    }
    
    public void setPlayers(Player[] players) {
        m_players = players;
    }
    
    private Player getLeftPlayer(Player player) {
        int playerIndex = getPlayerIndex(player);
        int leftPlayerIndex = (playerIndex + 2) % 3;
        return m_players[leftPlayerIndex];
    }
    
    private Player getNextPlayer(Player player) {
        int playerIndex = getPlayerIndex(player);
        int nextPlayerIndex = (playerIndex + 1) % 3;
        return m_players[nextPlayerIndex];
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