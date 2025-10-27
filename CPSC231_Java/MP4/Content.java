import java.util.*;

class Content implements Comparable<Content> {
    private String title;
    private String artist;
    private int timesStreamed;

    public Content(String title, String artist) {
        this.title = title;
        this.artist = artist;
        this.timesStreamed = 0;
    }

    public String getTitle() {
        return title;
    }

    public String getArtist() {
        return artist;
    }

    public int getTimesStreamed() {
        return timesStreamed;
    }

    public void play() {
        timesStreamed++;
        System.out.println("Now playing: " + title + " by " + artist);
    }

    @Override
    public int compareTo(Content other) {
        return Integer.compare(other.timesStreamed, this.timesStreamed);
    }
}