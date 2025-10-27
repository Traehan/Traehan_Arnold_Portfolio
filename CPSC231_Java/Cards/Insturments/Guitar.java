// Guitar is a derived class from base class Instrument
// aka child class from parent child Instrument

public class Guitar extends Instrument { //ACTUALLY defining the parent-child relationship
    protected int m_strings; // number of strings 
  
    public Guitar(){
        super(); //**FIRST THING YOU DO**calling the parents (Instrument's) default constuctor
      m_strings = 6;
    }
  
    public Guitar(String n, String o, double p, int s){
      super(n, o, p)
        m_strings = s;
    }
  
  
    public int getStrings(){
      return m_strings;
    }
  
  
    public String toString(){
      String s = ""
      s += "\nThe number of strings is:" + m_strings;
      return s;
    }
  
    }
  