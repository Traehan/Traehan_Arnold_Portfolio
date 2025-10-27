interface Content extends Comparable<Content> {
    String getTitle();

    String getArtist();

    int getTimesStreamed();

    void play();
}