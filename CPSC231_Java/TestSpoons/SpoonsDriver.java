import java.util.LinkedList;

public class SpoonsDriver {
    public static void main(String[] args) {
        Dealer dealer = new Dealer();
        Player[] players = new Player[4];
        for (int i = 0; i < players.length; i++) {
            players[i] = new Player(i + 1, dealer);
        }
        Game game = new Game(dealer, players, 4);
        game.play();
    }
}
