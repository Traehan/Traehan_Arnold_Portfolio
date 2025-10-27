import java.util.ArrayList;
import java.util.List;

class Listener extends Account {
    private List<Content> favorites;

    public Listener(String name) {
        super(name);
        favorites = new ArrayList<>();
    }

    public void favorite(Content content) {
        favorites.add(content);
    }

    public List<Content> getFavorites() {
        return favorites;
    }
}