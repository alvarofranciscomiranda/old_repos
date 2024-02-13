package dkeep.logic;

/**
 * Character.java - it's all the carathers that are involved in the game
 * @author Eu
 *
 */
public class Character extends Coordinates{
	
	protected  Coordinates coordinates;
	protected char icon;
	
	/**  
	 * Character default constructor  
	 *  
	 */ 
	public Character(){
		this.coordinates.setX(0);
		this.coordinates.setY(0);
		icon = 'c';
	};
	
	/**  
	 * Character constructor  
	 * 
	 * @param x  initial character coordinates x
	 * @param y  initial character coordinates y
	 *  
	 */
	public Character(int x, int y)
	{
		this.coordinates.setX(x);
		this.coordinates.setY(y);
		icon = 'c';
	}
	
	/**  
	 * Character constructor  
	 * 
	 * @param x  initial character coordinates x
	 * @param y  initial character coordinates y
	 * @param c icon that represents the Character
	 *  
	 */
	public Character(int x, int y, char i)
	{
		Coordinates h = new Coordinates();
		h.setX(x);
		h.setY(y);
		this.setCoordinates(h);
		icon = i;
	}
	
	
	/**  
	 * Character constructor  
	 * 
	 * @param coor  initial character coordinates
	 * @param c icon that represents the Character
	 *  
	 */
	public Character(Coordinates coor, char i)
	{
		this.coordinates = coor;
		icon = i;
	}
	
	/**  
	 * Gets x coordinates  
	 * 
	 * @return x coordinates
	 *  
	 */
	public Coordinates getCoordinates(){
		return this.coordinates;
	}
	
	/**  
	 * Gets character icon  
	 * 
	 * @return icon
	 *  
	 */
	public char getIcon() {
		return icon;
	}
	
	
	/**  
	 * Sets coordinates with x and y
	 * 
	 * @param  x coordinate x
	 * @param  y coordinate y
	 */
	public void setCoordinates(int x, int y)
	{
		this.coordinates.setX(x);
		this.coordinates.setY(y);
	}
	
	/**  
	 * Sets coordinates with Coordinate class
	 * 
	 * @param  co coordinate
	 */
	public void setCoordinates(Coordinates co)
	{
		this.coordinates = co;
	}

	/**  
	 * Sets character icon  
	 * 
	 * @param c character icon
	 */
	public void setIcon(char c){
		icon = c;
	}
	
	/**  
	 * Gets a new Character position 
	 * 
	 * @param coordinates  the actual coordinates
	 * @param str - imput of the keyboard that decides in witch direction character moves
	 * @return  new coordinates
	 */
	public Coordinates newCoordinates(Coordinates coordinates , char str) {
		
		Coordinates coor = new Coordinates();
		
		switch (str) {

		case 'w':
			coor.setX(coordinates.getX() - 1);
			coor.setY(coordinates.getY());
			if(coor.getX()<0)
				coor.setX(0);
			break;

		case 'd':
			coor.setY(coordinates.getY() + 1);
			coor.setX(coordinates.getX());
			if(coor.getY() > 10)
				coor.setY(10);
			break;

		case 's':
			coor.setX(coordinates.getX() + 1);
			coor.setY(coordinates.getY());
			if(coor.getX() > 10)
				coor.setX(10);
			break;

		case 'a':
			coor.setY(coordinates.getY() - 1);
			coor.setX(coordinates.getX());
			if(coor.getY() < 0)
				coor.setY(0); 
			break;
			
		default:
			break;
		}
		
		return coor;
	}
	
	
}
