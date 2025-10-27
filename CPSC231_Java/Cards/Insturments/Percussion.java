/*
 * Percussion will be absteacft
 * it does not make any sense to have a percussion object, you have to have more details
 * Heiarchy --> Instrument ---> Percussion --> Drum
 */

public abstract class Percussion extends Instrument{

    public Percussion(){
        super();
    }
    public Percussion(String n, String o, double p){
        super(n,o,p);
    }

    Public String toString(){
    String s = "";
    s += "Part of the percussion family!\n";
    s += super.toString();
    return s;
    }
    
}