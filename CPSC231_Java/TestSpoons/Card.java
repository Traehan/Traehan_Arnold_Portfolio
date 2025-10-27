public class Card {
    
    // constants for suit values
    public static final int HEARTS = 0;
    public static final int SPADES = 1;
    public static final int CLUBS = 2;
    public static final int DIAMONDS = 3;
    
    // constants for value of face cards
    public static final int JACK = 11;
    public static final int QUEEN = 12;
    public static final int KING = 13;
    public static final int ACE = 14;
    
    private int value;
    private int suit;
    
    // default constructor - creates an Ace of Spades
    public Card() {
        this.value = ACE;
        this.suit = SPADES;
    }
    
    // overloaded constructor
    public Card(int value, int suit) {
        this.value = value;
        this.suit = suit;
    }
    
    // copy constructor
    public Card(Card other) {
        this.value = other.getValue();
        this.suit = other.getSuit();
    }
    
    // getters and setters
    public int getValue() {
        return value;
    }
    
    public void setValue(int value) {
        this.value = value;
    }
    
    public int getSuit() {
        return suit;
    }
    
    public void setSuit(int suit) {
        this.suit = suit;
    }
    
    // toString method
    public String toString() {
        String valueString;
        switch (value) {
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
                valueString = Integer.toString(value);
        }
        
        String suitString;
        switch (suit) {
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
        }
        
        return valueString + " of " + suitString;
    }
    
    // equals method - checks if two cards have the same value
    public boolean equals(Card other) {
        return this.value == other.getValue();
    }
    
}
