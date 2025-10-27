class Song implements Content {
    private String title;
    private String artist;
    private int timesStreamed;

    public Song(String title, String artist) {
        this.title = title;
        this.artist = artist;
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
        System.out.println("Now playing: " + title + " by " + artist);
    }

    @Override
    public int compareTo(Content other) {
        return Integer.compare(timesStreamed, other.getTimesStreamed());
    }

    @Override
    public String toString() {
        return title + " by " + artist + " (Times Streamed: " + timesStreamed + ")";
    }
}