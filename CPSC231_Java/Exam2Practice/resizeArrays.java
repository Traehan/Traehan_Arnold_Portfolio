import java.util.Scanner;
public static String[] resizeArrays{
    public static void main(String[] args){
        Scanner scnr = new Scanner(System.in);
        String[] originalArray = {"Raven", "Daisy", "Jasmine"};
        int newSize = scnr.nextInt();
        originalArray = resize(originalArray, newSize);
        for(int i = 0; i < originalArray.length; ++i){
            System.out.print(originalArray[i]);
        }
    }
    public static String[] resize(String[] arrayReference, int newSize) {
        String[] resultArray = new String[newSize];
        int index;
        int numToCopy;
     
        // Determine the number of array elements to copy
        numToCopy = Math.min(newSize, arrayReference.length);
     
        // Copy elements from arrayReference to resultArray
        for (index = 0; index < numToCopy; ++index) {
           resultArray[index] = arrayReference[index];
        }
        
        return resultArray;
     }
}