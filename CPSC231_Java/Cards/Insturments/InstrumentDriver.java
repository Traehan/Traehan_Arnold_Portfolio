/**
INHERITANCE AND POLYMORPHISM

AGENDA:
We will build the following classes:
	- Instrument: which has a name, an origin, and price.
	- Guitar: which extends from Instrument and has a number of strings.
	- Drum: which extends from Instrument and has a number of pieces.

All classes have a default, overloaded, and copy constructor
as well as accessors, mutators, a toString() method,
and a play() method that prints an appropriate message
for the instrument to standard output.
*/

import java.util.LinkedList;

public class InstrumentDriver{
  public static void main(String[] args) {

		Instrument i = new Instrument("Piano", "Italy", 12534.99);
    Guitar g = new Guitar("Madrid", 4500.99, 6);
    Drum d = new Drum("China", 2500.32, 5);

    System.out.println(i);
    System.out.println("\n"+g);
    System.out.println("\n"+d);

    System.out.println("\n");

    i.play();
    g.play();
    d.play();

    // System.out.println("\n" + g.isExpensive());

    Instrument i2 = d;
    i2.play(); // POLYMORPHISM -- at runtime the JVM searches and executes the most specific implementation
              // late binding

		
		// in a collection 

    ArrayList<Instrument> al = new ArrayList<Instrument>();
    al.add(i);
    al.add(g);
    al.add(d);

    for (Instrument x: al){
      x.play();
    }


	}
}