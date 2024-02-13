package dkeep.logic;

/**  
* Suspicious.java - Sometimes this guard inverts his direction.
* @author  Eu 
* 
*/ 
public class Suspicious extends Guard{
	
	/**  
	 * Guard constructor  
	 * 
	 * @param x  initial guard coordinates x
	 * @param y  initial guard coordinates y
	 */
	public Suspicious(int x, int y) {
		super(x, y);
	}
	
	/**  
	 * Guard constructor  
	 * 
	 * @param coor  initial guard coordinates
	 */
	public Suspicious(Coordinates coor) {
		super(coor);
	}
	
	@Override
	public void moveGuard(){
		
		Coordinates new_pos = new Coordinates(this.coordinates.getX(), coordinates.getY());
		
		if(randomNumber(2) == 0)
			this.front = true;
		else
			this.front = false;
		
		
		if(this.front){
			new_pos = super.newCoordinates(this.coordinates, this.guardkeys[this.counter]);
			
			this.plusCounter();
		}
		else{
			this.minusCounter();
			
			new_pos = super.newCoordinates(this.coordinates, reverseMotion(this.guardkeys[this.counter]));
			
		}
		
		updateGuard(new_pos);
	}	
}
