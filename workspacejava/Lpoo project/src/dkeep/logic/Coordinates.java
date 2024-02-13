package dkeep.logic;

/**
 * Coordinates.java - Class coordinates that is the x and y
 * @author Eu
 *
 */
public class Coordinates {
	private int x;
	private int y;
	
	/**
	 * Coordinates default constructor
	 */
	public Coordinates(){
		this.x = 0;
		this.y = 0;
}
	/**
	 * Coordinates constructor
	 * @param x is the coordinatas x
	 * @param y is the coordinatas y
	 */
	public Coordinates(int x, int y){
		this.x = x;
		this.y = y;
	}
	
	/**  
	 * Gets x position  
	 * 
	 * @return x of the coordinate
	 *  
	 */
	public int getX() {
		return x;
	}
	
	/**  
	 * Gets y position  
	 * 
	 * @return y of the coordinate
	 *  
	 */
	public int getY() {
		return y;
	}

	/**  
	 * Sets x of the coordinate  
	 * 
	 * @param x position
	 *  
	 */
	public void setX(int x) {
		this.x = x;
	}	
	
	/**  
	 * Sets y of the coordinate  
	 * 
	 * @param y position
	 *  
	 */
	public void setY(int y) {
		this.y = y;
	}
	
}
