public class Card {
    // Constants for suits
    public static final int HEARTS = 0;
    public static final int SPADES = 1;
    public static final int CLUBS = 2;
    public static final int DIAMONDS = 3;

    // Constants for values/ranks
    public static final int JACK = 11;
    public static final int QUEEN = 12;
    public static final int KING = 13;
    public static final int ACE = 14;

    // Member variables
    private int value;
    private int suit;

    // Default constructor creates an Ace of Spades
    public Card() {
        this.value = ACE;
        this.suit = SPADES;
    }

    // Overloaded constructor
    public Card(int value, int suit) {
        this.value = value;
        this.suit = suit;
    }

    // Copy constructor
    public Card(Card other) {
        this.value = other.getValue();
        this.suit = other.getSuit();
    }

    // toString method
    public String toString() {
        String valueString;
        switch (this.value) {
            case JACK:
                valueString = "Jack";
                break;
            case QUEEN:
                valueString = "Queen";
                break;
            case KING:
                valueString = "King";
                break;
            case ACE:
                valueString = "Ace";
                break;
            default:
                valueString = Integer.toString(this.value);
                break;
        }
        String suitString;
        switch (this.suit) {
            case HEARTS:
                suitString = "Hearts";
                break;
            case SPADES:
                suitString = "Spades";
                break;
            case CLUBS:
                suitString = "Clubs";
                break;
            case DIAMONDS:
                suitString = "Diamonds";
                break;
            default:
                suitString = "Unknown suit";
                break;
        }
        return valueString + " of " + suitString;
    }

    // equals method
    public boolean equals(Card other) {
        return this.value == other.getValue();
    }

    // Mutators and accessors for value and suit
    public int getValue() {
        return this.value;
    }

    public void setValue(int value) {
        this.value = value;
    }

    public int getSuit() {
        return this.suit;
    }

    public void setSuit(int suit) {
        this.suit = suit;
    }
}
