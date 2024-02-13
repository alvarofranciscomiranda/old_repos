package dkeep.logic;



/**  
* Drunken.java - Guard subclasse, this guard is able to fall asleep
* @author  Eu 
* 
*/ 
public class Drunken extends Guard{
	
	/**  
	 * Guard constructor  
	 * 
	 * @param x  initial guard coordinates x
	 * @param y  initial guard coordinates y
	 */
	public Drunken(int x, int y) {
		super(x, y);
	}
	
	/**  
	 * Guard constructor  
	 * 
	 * @param coor  initial guard coordinates
	 */
	public Drunken(Coordinates coor) {
		super(coor);
	}
	
	@Override
	public void moveGuard(){
		
		if(randomNumber(2) == 0)
			this.asleep = true;
		else
			this.asleep = false;
		
		Coordinates new_pos = new Coordinates(this.coordinates.getX(), coordinates.getY());
		
		if(!this.asleep){
			new_pos = super.newCoordinates(this.coordinates, this.guardkeys[this.counter]);
			
			this.plusCounter();
		}
		
		updateGuard(new_pos, asleep);
	}	
}
