import java.util.ArrayList;
import java.util.List;

class ListenerAccount extends Account {
    private List<String> favorites;

    public ListenerAccount(String name) {
        super(name);
        this.favorites = new ArrayList<>();
    }

    public void favorite(String content) {
        favorites.add(content);
        System.out.println(content + " has been added to favorites.");
    }

    public List<String> getFavorites() {
        return favorites;
    }
}