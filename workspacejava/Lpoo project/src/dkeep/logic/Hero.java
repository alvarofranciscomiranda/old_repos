package dkeep.logic;

import dkeep.logic.Character;


/**  
* Hero.java - This is the heros of the game.
* @author  Eu 
* 
*/ 
public class Hero extends Character {
	
	public enum HeroState{
		MOVE, STAIR, DOOR 
	};

	protected boolean key = false;
	protected boolean club = false;
	protected HeroState state;
	
	/**  
	 * Hero constructor  
	 * 
	 * @param x  initial character coodinates x
	 * @param y  initial character coodinates y
	 *  
	 */
	public Hero(int x, int y) {
		super(x,y,'H');
		key = false;
		club = false;
		state = HeroState.MOVE;
	}
	
	/**  
	 * Hero constructor  
	 * 
	 * @param position  initial character coordinates
	 *  
	 */
	public Hero(Coordinates coor) {
		super(coor.getX(), coor.getY(), 'H');
		key = false;
		club = false;
		state = HeroState.MOVE;
	}

	/**  
	 * Update hero coordinates and state
	 * 
	 * @param c icon
	 * @param new_pos  coordinates of the hero
	 */
	public void updateHero(char c, Coordinates new_pos){
		
		switch (c) {
			case 'X':
				break;
				
			case 'I':
				state = HeroState.DOOR;
				break;
				
			case ' ':
				coordinates = new_pos;
				state = HeroState.MOVE;
				break;
				
			case 'S':
				coordinates = new_pos;
				state = HeroState.STAIR;
				break;
				
			case 'k':
				coordinates = new_pos;
				key = true;
				break;

			case '*':
				coordinates = new_pos;
				club = true;
				setIcon('A');
			
			default:
				break;
		}
		
	}

	/**  
	 * Moves the hero
	 * 
	 * @param str char that is read from the keyboard
	 * @param board  game board
	 */
	public void moveHero(char str, Board board) {

		Coordinates new_pos = new Coordinates(this.coordinates.getX(),this.coordinates.getY() );
		char c;
		
		new_pos = super.newCoordinates(this.coordinates, str);
	
		c = board.getIcon(new_pos);
	
		updateHero(c, new_pos);

	}

	/**  
	 * Gets hero state
	 * 
	 * @return state of the hero
	 */
	public HeroState getState() {
		return state;
	}
	
	/**  
	 * Checks if the hero has the key
	 * 
	 * @return true if the hero has the key, false otherwise
	 */
		public boolean hasKey() {
			return key;
	}
	
	/**  
	 * Checks if the hero has the club
	 * 
	 * @return true if the hero has the club, false otherwise
	 */
		public boolean hasClub(){
			return club;
	}
	
		/**  
		 * Sets if the hero got the key
		 * 
		 * @param key  boolean that represents the key variable		 */
		public void setKey(boolean key){
			this.key = key;
	}

}