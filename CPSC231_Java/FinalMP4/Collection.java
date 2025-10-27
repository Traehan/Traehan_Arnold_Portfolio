import java.util.Collections;
import java.util.List;


interface Collection<T extends Content> extends Comparable<Collection<T>> {
    String getTitle();

    List<T> getContents();

    void shuffle();

    void addContent(T content);

    void removeContent(T content);

    void play();
}