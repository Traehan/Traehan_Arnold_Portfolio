import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.InputMismatchException;
import java.util.List;
import java.util.Scanner;



public class Driver {
    private static List<Song> songs;
    private static List<ArtistAccount> artists;
    private static List<Podcast> podcasts;
    private static List<ListenerAccount> listeners;

    public static void main(String[] args) {
        initializeApp();
        showMenu();
    }

    private static void initializeApp() {
        songs = new ArrayList<>();
        artists = new ArrayList<>();
        podcasts = new ArrayList<>();
        listeners = new ArrayList<>();

        // Populate the app with some default songs, artists, and podcasts
        Song song1 = new Song("Song 1", "Artist 1");
        Song song2 = new Song("Song 2", "Artist 2");
        songs.add(song1);
        songs.add(song2);

        ArtistAccount artist1 = new ArtistAccount("Artist 1");
        ArtistAccount artist2 = new ArtistAccount("Artist 2");
        artists.add(artist1);
        artists.add(artist2);

        Podcast podcast1 = new Podcast("Podcast 1", "Host 1", 1);
        Podcast podcast2 = new Podcast("Podcast 2", "Host 2", 2);
        podcasts.add(podcast1);
        podcasts.add(podcast2);
    }

    private static void showMenu() {
        Scanner scanner = new Scanner(System.in);
        boolean exit = false;

        while (!exit) {
            System.out.println("\n*** Music App Menu ***");
            System.out.println("1. Create a listener account");
            System.out.println("2. List all Playlists and Albums and their contents");
            System.out.println("3. Add songs to an existing playlist");
            System.out.println("4. Shuffle an existing Playlist or listen to an Album");
            System.out.println("5. Add a song or podcast to favorites");
            System.out.println("6. Export all of a listener’s favorites");
            System.out.println("7. Exit");
            System.out.print("Enter your choice: ");

            int choice;
            try {
                choice = scanner.nextInt();
                scanner.nextLine(); // Consume the newline character
            } catch (InputMismatchException e) {
                scanner.nextLine(); // Consume the invalid input
                System.out.println("Invalid input. Please enter a number from the menu.");
                continue;
            }

            switch (choice) {
                case 1:
                    createListenerAccount(scanner);
                    break;
                case 2:
                    listAllCollections();
                    break;
                case 3:
                    addSongsToPlaylist(scanner);
                    break;
                case 4:
                    shufflePlaylistOrListenToAlbum(scanner);
                    break;
                case 5:
                    addToFavorites(scanner);
                    break;
                case 6:
                    exportFavorites(scanner);
                    break;
                case 7:
                    exit = true;
                    break;
                default:
                    System.out.println("Invalid choice. Please enter a number from the menu.");
            }
        }
    }

    private static void createListenerAccount(Scanner scanner) {
        System.out.print("Enter the listener's name: ");
        String name = scanner.nextLine();

        ListenerAccount listener = new ListenerAccount(name);
        listeners.add(listener);
        System.out.println("Listener account created successfully.");
    }

    private static void listAllCollections() {
        System.out.println("\n*** Playlists ***");
        for (ListenerAccount listener : listeners) {
            System.out.println("Listener: " + listener.getName());
            List<Playlist> playlists = listener.getPlaylists();
            for (Playlist playlist : playlists) {
                System.out.println("- " + playlist.getTitle());
                List<Content> contents = playlist.getContentList();
                for (Content content : contents) {
                    System.out.println("  * " + content.getTitle() + " by " + content.getArtist());
                }
            }
        }

        System.out.println("\n*** Albums ***");
        for (ArtistAccount artist : artists) {
            System.out.println("Artist: " + artist.getName());
            List<Album> albums = artist.getAlbums();
            for (Album album : albums) {
                System.out.println("- " + album.getTitle());
                List<Song> songs = album.getContentList();
                for (Song song : songs) {
                    System.out.println("  * " + song.getTitle() + " by " + song.getArtist());
                }
            }
        }
    }

    private static void addSongsToPlaylist(Scanner scanner) {
        if (listeners.isEmpty()) {
            System.out.println("No listener accounts exist. Please create a listener account first.");
            return;
        }

        System.out.println("Available playlists:");
        int listenerIndex = selectListenerAccount(scanner);
        ListenerAccount listener = listeners.get(listenerIndex);

        List<Playlist> playlists = listener.getPlaylists();
        if (playlists.isEmpty()) {
            System.out.println("No playlists exist for this listener. Please create a playlist first.");
            return;
        }

        int playlistIndex = selectPlaylist(scanner, playlists);
        Playlist playlist = playlists.get(playlistIndex);

        System.out.println("Available songs:");
        int songIndex = selectSong(scanner);
        Song song = songs.get(songIndex);

        playlist.addContent(song);
        System.out.println("Song added to the playlist successfully.");
    }

    private static void shufflePlaylistOrListenToAlbum(Scanner scanner) {
        if (listeners.isEmpty()) {
            System.out.println("No listener accounts exist. Please create a listener account first.");
            return;
        }

        System.out.println("Available playlists:");
        int listenerIndex = selectListenerAccount(scanner);
        ListenerAccount listener = listeners.get(listenerIndex);

        List<Playlist> playlists = listener.getPlaylists();
        if (playlists.isEmpty()) {
            System.out.println("No playlists exist for this listener. Please create a playlist first.");
            return;
        }

        int playlistIndex = selectPlaylist(scanner, playlists);
        Playlist playlist = playlists.get(playlistIndex);

        System.out.println("Shuffling playlist: " + playlist.getTitle());
        while (!playlist.getContentList().isEmpty()) {
            playlist.shuffle();
            playlist.getContentList().remove(0);
        }

        System.out.println("Playlist has been played.");
    }

    private static void addToFavorites(Scanner scanner) {
        if (listeners.isEmpty()) {
            System.out.println("No listener accounts exist. Please create a listener account first.");
            return;
        }

        System.out.println("Available listener accounts:");
        int listenerIndex = selectListenerAccount(scanner);
        ListenerAccount listener = listeners.get(listenerIndex);

        System.out.println("Available songs and podcasts:");
        int contentIndex = selectContent(scanner);
        Content content = getContentByIndex(contentIndex);

        listener.favorite(content);
        System.out.println("Content added to favorites successfully.");
    }

    private static void exportFavorites(Scanner scanner) {
        if (listeners.isEmpty()) {
            System.out.println("No listener accounts exist. Please create a listener account first.");
            return;
        }

        System.out.println("Available listener accounts:");
        int listenerIndex = selectListenerAccount(scanner);
        ListenerAccount listener = listeners.get(listenerIndex);

        System.out.print("Enter the file path to export favorites: ");
        String filePath = scanner.nextLine();

        try (PrintWriter writer = new PrintWriter(filePath)) {
            List<Content> favorites = listener.getFavorites();
            Collections.sort(favorites);
            for (Content content : favorites) {
                writer.println(content.getTitle() + " by " + content.getArtist() + ", Times Streamed: " + content.getTimesStreamed());
            }
            System.out.println("Favorites exported successfully.");
        } catch (IOException e) {
            System.out.println("Error exporting favorites: " + e.getMessage());
        }
    }

    private static int selectListenerAccount(Scanner scanner) {
        System.out.print("Enter the index of the listener account: ");
        int index = scanner.nextInt();
        scanner.nextLine(); // Consume the newline character
        return index;
    }

    private static int selectPlaylist(Scanner scanner, List<Playlist> playlists) {
        for (int i = 0; i < playlists.size(); i++) {
            System.out.println(i + ". " + playlists.get(i).getTitle());
        }

        System.out.print("Enter the index of the playlist: ");
        int index = scanner.nextInt();
        scanner.nextLine(); // Consume the newline character
        return index;
    }

    private static int selectSong(Scanner scanner) {
        for (int i = 0; i < songs.size(); i++) {
            System.out.println(i + ". " + songs.get(i).getTitle());
        }

        System.out.print("Enter the index of the song: ");
        int index = scanner.nextInt();
        scanner.nextLine(); // Consume the newline character
        return index;
    }

    private static int selectContent(Scanner scanner) {
        for (int i = 0; i < songs.size(); i++) {
            System.out.println(i + ". " + songs.get(i).getTitle() + " by " + songs.get(i).getArtist());
        }

        for (int i = 0; i < podcasts.size(); i++) {
            System.out.println(i + songs.size() + ". " + podcasts.get(i).getTitle() + " by " + podcasts.get(i).getArtist());
        }

        System.out.print("Enter the index of the content: ");
        int index = scanner.nextInt();
        scanner.nextLine(); // Consume the newline character
        return index;
    }

    private static Content getContentByIndex(int index) {
        if (index >= 0 && index < songs.size()) {
            return songs.get(index);
        } else if (index >= songs.size() && index < songs.size() + podcasts.size()) {
            return podcasts.get(index - songs.size());
        } else {
            throw new IllegalArgumentException("Invalid content index.");
        }
    }
}
