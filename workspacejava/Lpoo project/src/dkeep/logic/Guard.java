package dkeep.logic;

import java.util.Random;
import dkeep.logic.Character;

/**  
* Guard.java - This is the guard of the game
* @author  Eu
* 
*/ 
public class Guard extends Character{

	protected boolean asleep = false;
	protected boolean front = true;
	protected int counter = 0; // movimento do guarda
	protected char guardkeys[] = {'a', 's', 's', 's', 's', 'a', 'a', 'a',
			'a', 'a', 'a', 's', 'd', 'd', 'd', 'd', 'd', 'd', 'd', 'w', 'w',
			'w', 'w', 'w'};
	
	/**  
	 * Guard constructor  
	 * 
	 * @param x initial guard coordinates x
	 * @param y initial guard coordinates y
	 */
	public Guard(int x, int y) {
		super(x, y, 'G');
	}
	
	/**  
	 * Guard constructor  
	 * 
	 * @param coor initial guard coordinates
	 */
	public Guard(Coordinates coor) {
		super(coor.getX(), coor.getY(), 'G');
	}
	
	/**
	 * 
	 * @param c char that is readed from the keyboard
	 * @return the oppsoite char of c, example if c is w return s
	 */
	protected char reverseMotion(char c) {
		switch(c) {
		case 'w':
			return 's';
		case 's':
			return 'w';
		case 'a':
			return 'd';
		case 'd':
			return 'a';
		default:
			return ' ';
		}	
	}
	
	/**  
	 * Sets guard new coordinates  
	 *
	 */
	public void updateGuard(Coordinates new_pos){
		coordinates = new_pos;
	}
	
	/**  
	 * Sets guard new coordinates depending if the guard is asleep or not  
	 *
	 */
	public void updateGuard(Coordinates new_pos, boolean alseep){
		coordinates = new_pos;
		
		if(asleep)
			this.setIcon('g');
		else
			this.setIcon('G');
	}
	
	/**  
	 * Change the guard coordinates in the board for his actual cordinates 
	 *
	 */
	public void moveGuard(){};
	
	/**  
	 * Checks whereas the guard is front turned 
	 *
	 * @return true if the guard is front turned , false otherwise
	 */
	public boolean isFront() {
		return front;
	}
	
	/**  
	 * Sets guard front state
	 *
	 * @param true if the guard is front turned, false otherwise
	 */
	public void setFront(boolean front) {
		this.front = front;
	}
	
	/**  
	 * Sets guard Asleep state true and change his icon to 'g'
	 *
	 */
	public void setAsleep() {
		this.asleep = true;
		this.icon = 'g';
	}
	
	
	/**  
	 * Increments guard counter
	 *
	 */
	public void plusCounter(){
		counter++;
		if (counter == 24)
			counter = 0;
	}
	
	/**  
	 * Decrement guard counter
	 *
	 */
	public void minusCounter()
	{
		counter--;
		if(counter == -1)
			counter = 23;
	}
	
	/**  
	 * Generate random number between 0 and limit
	 *@param limit the limit of the random number
	 *@return the random number
	 */
	public int randomNumber(int limit){
		Random rand = new Random();		
		int random = rand.nextInt(limit);
		return random;
	}
	
	
}
