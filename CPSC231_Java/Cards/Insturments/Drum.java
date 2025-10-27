/*
Drum: which will extend from Instrument
and has a number of pieces.
*/
public class Drum extends Percussion{

    // member vars
    protected int m_pieces;
  
    // default constructor
    public Drum(){
        super();
        
      m_pieces = 1;
    }
  
    // fully specified constructor
    public Drum(String n, String o, double p int pc){
        super(n, o, p);
      m_pieces = pc;
    }
  
    // to string method
    public String toString(){ //overridden
      String s = "";
      s += "The number of pieces is: " + m_pieces;
      return s;
    }
  
  
    // accecssor
    public int getPieces(){
      return m_pieces;
    }
  /*
   * 
   * if we dont implement the play() method in drum there will be an error (has to extend drum)
   */
  
  }
