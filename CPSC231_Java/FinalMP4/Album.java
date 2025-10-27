class Album extends Playlist<Song> {
    public Album(String title) {
        super(title);
    }

    @Override
    public void play() {
        System.out.println("Album: " + getTitle());
        for (Song song : getContents()) {
            song.play();
        }
        System.out.println();
    }
}