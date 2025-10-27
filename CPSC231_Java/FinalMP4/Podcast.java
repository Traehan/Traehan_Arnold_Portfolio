class Podcast implements Content {
    private String title;
    private String artist;
    private int episodeNumber;
    private int timesStreamed;

    public Podcast(String title, String artist, int episodeNumber) {
        this.title = title;
        this.artist = artist;
        this.episodeNumber = episodeNumber;
        this.timesStreamed = 0;
    }

    @Override
    public String getTitle() {
        return title;
    }

    @Override
    public String getArtist() {
        return artist;
    }

    @Override
    public int getTimesStreamed() {
        return timesStreamed;
    }

    @Override
    public void play() {
        timesStreamed++;
        System.out.println("Now playing: " + title + " by " + artist + " (Episode " + episodeNumber + ")");
    }

    @Override
    public int compareTo(Content other) {
        return Integer.compare(timesStreamed, other.getTimesStreamed());
    }

    @Override
    public String toString() {
        return title + " by " + artist + " (Episode " + episodeNumber + ", Times Streamed: " + timesStreamed + ")";
    }
}