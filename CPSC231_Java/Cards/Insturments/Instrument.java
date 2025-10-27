public abstract class Instrument{
    // protected means that all future children of this class will inherit thse member variables
    protected String m_name;
    protected String m_origin;
    protected double m_price;

public Instrument(){
m_name = null;
m_origin = null;
m_price = -1.0;

}

public Instrument(String name, String origin, double price){
m_name = name;
m_origin = origin;
m_price = price;
}

public String toString(){
    String s = "";
    s += "Name: " + m_name + "\n";
    s += "Origin; " + m_origin + "\n";
    s += "Price: " + m_price + "\n";
}

public boolean equals(object o){
    if(this == o){
        return true;
    }
    if(!(o instanceof Instrument)){
        return false;

    }
    Instrument i = (Instrument) o;
    return m_name.equals(i.m_name);
    }

    public void play(){
        System.out.println("This is a beautifil Instrument playing beautiful music");
    }

    public abstract void play(); //declaration of an abstract method, play
    /* because we declared this abstract play method:
     * 
     * if any class wants to be an instrument (extend instrument)
     * they must give an implementation for a play method with the same signature (same return type and same parameter list)
     * (e.g. public void play())
     * 
     * EXCEPTION:  if the child is also abstract then they do not have to give an implementation to the parents abstract methods
     * 
     * 
     * note: only abstract classes may contain abstract methods but not every abstract class will have abstract methods
     */
}
