package dkeep.logic;

/**  
* Rookie.java - This guard follows the path without failure
* @author  Eu 
* 
*/ 
public class Rookie extends Guard{
	
	/**  
	 * Guard constructor  
	 * 
	 * @param x  initial guard coordinates x
	 * @param y  initial guard coordinates y
	 */
	public Rookie(int x, int y) {
		super(x, y);
	}
	
	/**  
	 * Guard constructor  
	 * 
	 * @param coor  initial guard coordinates
	 */
	public Rookie(Coordinates coor) {
		super(coor);
	}
	
	@Override
	public void moveGuard(){
		
		Coordinates new_pos = new Coordinates(this.coordinates.getX(), coordinates.getY());
		
		new_pos = super.newCoordinates(this.coordinates, this.guardkeys[this.counter]);
		
		this.plusCounter();
		
		updateGuard(new_pos);
	}	
}
