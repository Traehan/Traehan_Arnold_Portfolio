import java.util.ArrayList;
import java.util.Collections;
import java.util.List;


class Playlist<T extends Content> implements Collection<T> {
    private String title;
    private List<T> contents;

    public Playlist(String title) {
        this.title = title;
        this.contents = new ArrayList<>();
    }

    @Override
    public String getTitle() {
        return title;
    }

    @Override
    public List<T> getContents() {
        return contents;
    }

    @Override
    public void shuffle() {
        Collections.shuffle(contents);
        play();
    }

    @Override
    public void addContent(T content) {
        contents.add(content);
    }

    @Override
    public void removeContent(T content) {
        contents.remove(content);
    }

    @Override
    public void play() {
        System.out.println("Playlist: " + title);
        for (T content : contents) {
            content.play();
        }
        System.out.println();
    }

    @Override
    public int compareTo(Collection<T> other) {
        return Integer.compare(contents.size(), other.getContents().size());
    }

    @Override
    public String toString() {
        return title + " (" + contents.size() + " items)";
    }
}