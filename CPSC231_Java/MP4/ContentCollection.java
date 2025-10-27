import java.util.List;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Random;

abstract class ContentCollection<T extends Content> implements Comparable<ContentCollection<T>> {
    private String title;
    private List<T> contentList;

    public ContentCollection(String title) {
        this.title = title;
        this.contentList = new ArrayList<>();
    }

    public String getTitle() {
        return title;
    }

    public List<T> getContentList() {
        return contentList;
    }

    public void shuffle() {
        if (contentList.isEmpty()) {
            System.out.println("The collection is empty.");
            return;
        }

        Random random = new Random();
        T randomContent = contentList.get(random.nextInt(contentList.size()));
        randomContent.play();
    }

    public void addContent(T content) {
        contentList.add(content);
    }

    public void removeContent(T content) {
        contentList.remove(content);
    }

    @Override
    public int compareTo(ContentCollection<T> other) {
        return Integer.compare(other.contentList.size(), this.contentList.size());
    }
}