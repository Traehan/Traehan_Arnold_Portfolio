import java.util.LinkedList;
import java.util.Scanner;

public class SpoonsDriver {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Get number of players from user input
        System.out.print("Enter the number of players: ");
        int numPlayers = scanner.nextInt();

        // Initialize game
        Game game = new Game(numPlayers);

        // Play rounds until there is a winner
        while (!game.checkForWin()) {
            game.play();
        }
    }
}
