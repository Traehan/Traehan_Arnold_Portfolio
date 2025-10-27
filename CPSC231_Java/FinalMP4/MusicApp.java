import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class MusicApp {
    private static List<Listener> listeners = new ArrayList<>();
    private static List<Content> contents = new ArrayList<>();
    private static List<Playlist> playlists = new ArrayList<>();
    private static List<Album> albums = new ArrayList<>();

    public static void main(String[] args) {
        initializeApp();
        runMusicApp();
    }

    private static void initializeApp() {
        // Initialize the app with some sample content
        Song song1 = new Song("Song 1", "Artist 1");
        Song song2 = new Song("Song 2", "Artist 2");
        Podcast podcast1 = new Podcast("Podcast 1", "Host 1", 1);
        Podcast podcast2 = new Podcast("Podcast 2", "Host 2", 2);

        contents.add(song1);
        contents.add(song2);
        contents.add(podcast1);
        contents.add(podcast2);

        Playlist playlist = new Playlist("My Playlist");
        playlist.addContent(song1);
        playlist.addContent(podcast1);

        Album album = new Album("My Album");
        album.addContent(song2);

        playlists.add(playlist);
        albums.add(album);
    }

    private static void runMusicApp() {
        Scanner scanner = new Scanner(System.in);

        while (true) {
            printMenu();
            int choice = scanner.nextInt();
            scanner.nextLine(); // Consume the newline character

            switch (choice) {
                case 1:
                    createListenerAccount(scanner);
                    break;
                case 2:
                    listCollections();
                    break;
                case 3:
                    addSongToPlaylist(scanner);
                    break;
                case 4:
                    shufflePlaylistOrListenToAlbum(scanner);
                    break;
                case 5:
                    addContentToFavorites(scanner);
                    break;
                case 6:
                    exportFavoritesToFile(scanner);
                    break;
                case 7:
                    System.out.println("Exiting the Music App...");
                    return;
                default:
                    System.out.println("Invalid choice. Please try again.");
                    break;
            }
        }
    }

    private static void printMenu() {
        System.out.println("------ Music App Menu ------");
        System.out.println("1. Create a listener account");
        System.out.println("2. List all Playlists and Albums and their contents");
        System.out.println("3. Add songs to an existing playlist");
        System.out.println("4. Shuffle an existing Playlist or listen to an Album");
        System.out.println("5. Add a song or podcast to favorites");
        System.out.println("6. Export all of a listener’s favorites out to a file in ascending order by times streamed");
        System.out.println("7. Exit");
        System.out.print("Enter your choice: ");
    }

    private static void createListenerAccount(Scanner scanner) {
        System.out.print("Enter listener name: ");
        String name = scanner.nextLine();
        Listener listener = new Listener(name);
        listeners.add(listener);
        System.out.println("Listener account created successfully.");
        System.out.println();
    }

    private static void listCollections() {
        System.out.println("All Collections:");
        for (Playlist playlist : playlists) {
            System.out.println(playlist);
            List<Content> playlistContents = playlist.getContents();
            for (Content content : playlistContents) {
                System.out.println(content);
            }
            System.out.println();
        }
        for (Album album : albums) {
            System.out.println(album);
            List<Content> albumContents = album.getContents();
            for (Content content : albumContents) {
                System.out.println(content);
            }
            System.out.println();
        }
    }

    private static void addSongToPlaylist(Scanner scanner) {
        System.out.print("Enter playlist title: ");
        String playlistTitle = scanner.nextLine();
        Playlist playlist = findPlaylistByTitle(playlistTitle);
        if (playlist == null) {
            System.out.println("Playlist not found.");
            System.out.println();
            return;
        }

        System.out.print("Enter song title: ");
        String songTitle = scanner.nextLine();
        Song song = findSongByTitle(songTitle);
        if (song == null) {
            System.out.println("Song not found.");
            System.out.println();
            return;
        }

        playlist.addContent(song);
        System.out.println("Song added to the playlist.");
        System.out.println();
    }

    private static void shufflePlaylistOrListenToAlbum(Scanner scanner) {
        System.out.print("Enter collection title: ");
        String collectionTitle = scanner.nextLine();
        Collection<Content> collection = findCollectionByTitle(collectionTitle);
        if (collection == null) {
            System.out.println("Collection not found.");
            System.out.println();
            return;
        }

        if (collection instanceof Playlist) {
            Playlist playlist = (Playlist) collection;
            playlist.shuffle();
        } else if (collection instanceof Album) {
            Album album = (Album) collection;
            album.play();
        }

        System.out.println();
    }

    private static void addContentToFavorites(Scanner scanner) {
        System.out.print("Enter listener name: ");
        String listenerName = scanner.nextLine();
        Listener listener = findListenerByName(listenerName);
        if (listener == null) {
            System.out.println("Listener not found.");
            System.out.println();
            return;
        }

        System.out.print("Enter content title: ");
        String contentTitle = scanner.nextLine();
        Content content = findContentByTitle(contentTitle);
        if (content == null) {
            System.out.println("Content not found.");
            System.out.println();
            return;
        }

        listener.favorite(content);
        System.out.println("Content added to favorites.");
        System.out.println();
    }

    private static void exportFavoritesToFile(Scanner scanner) {
        System.out.print("Enter listener name: ");
        String listenerName = scanner.nextLine();
        Listener listener = findListenerByName(listenerName);
        if (listener == null) {
            System.out.println("Listener not found.");
            System.out.println();
            return;
        }

        System.out.print("Enter output file name: ");
        String fileName = scanner.nextLine();

        try (BufferedWriter writer = new BufferedWriter(new FileWriter(fileName))) {
            List<Content> favorites = listener.getFavorites();
            Collections.sort(favorites);

            for (Content content : favorites) {
                writer.write(content.toString());
                writer.newLine();
            }

            System.out.println("Favorites exported to file: " + fileName);
        } catch (IOException e) {
            System.out.println("Error exporting favorites to file: " + e.getMessage());
        }
    }

    private static Playlist findPlaylistByTitle(String title) {
        for (Playlist playlist : playlists) {
            if (playlist.getTitle().equals(title)) {
                return playlist;
            }
        }
        return null;
    }

    private static Song findSongByTitle(String title) {
        for (Content content : contents) {
            if (content instanceof Song && content.getTitle().equals(title)) {
                return (Song) content;
            }
        }
        return null;
    }

    private static Content findContentByTitle(String title) {
        for (Content content : contents) {
            if (content.getTitle().equals(title)) {
                return content;
            }
        }
        return null;
    }

    private static Listener findListenerByName(String name) {
        for (Listener listener : listeners) {
            if (listener.getName().equals(name)) {
                return listener;
            }
        }
        return null;
    }

    private static Collection<Content> findCollectionByTitle(String title) {
        for (Playlist playlist : playlists) {
            if (playlist.getTitle().equals(title)) {
                return playlist;
            }
        }
        for (Album album : albums) {
            if (album.getTitle().equals(title)) {
                return album;
            }
        }
        return null;
    }
}
