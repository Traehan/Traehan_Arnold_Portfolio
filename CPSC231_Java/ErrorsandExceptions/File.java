import java.util.PrintWriter;
import java.util.FileWriter;

public class File {
    public static void main(String[] args){
    
/*
 * Command Line Argumentd:
 *          - when we feed in data in the command line when we run our program
 *          ex:
 *          javac myProgram.java
 *          java myProgram hello there are how are you?
 * 
 *          here hello there how are you? will be saved into an array called args
 *          (defined in the main method declation)
 *          so, args = ["hello", "there", "how", "are", "you?"]
 */
System.out.rpintln(args[0]);


    try{
        PrintWriter pw = new PrintWriter(new FileReader("cpsc231_text.txt", true)); //create a connection with your program and file in your disk
                                                                        //the true flag makes this an "append" mode connection
        pw.println("Cool!");

        pw.close();


        //READING FROM FILE CORRECTLY WITH BUFFER READER
    try{
        BufferReader br = new BufferedReader(new FileReader("test.txt"));
        String line = "";
        while ((line = br.readLine()) != null){ //set line to each line in the file until EOF is reached
            System.out.println("CONTENT BUFFERED READER: " + Line)
            fnfe
        }
        br.close();
    }

    
    } catch(IOException ioe){
        System.err.println("something went wrong when writing to file cpsc231_text.txt");
        ioe.printStackTrace();
    } catch (Exception e){
        System.err.println("something else went wrong...");
        e.printStackTrace();
    }
}
}