class Album extends ContentCollection<Song> {
    public Album(String title) {
        super(title);
    }

    @Override
    public void shuffle() {
        super.shuffle();
    }
}