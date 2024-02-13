package dkeep.logic;

import java.util.Random;
import dkeep.logic.Hero.HeroState;

/**  
 * Ogre.java - The ogre of the keep
 * @author  Eu 
 * 
 */ 
public class Ogre extends Character{

	protected Character club;
	protected boolean stunned = false;
	protected int counter;
	protected char ogreKeys[] = {'s', 'a', 'w', 'd'};
	
	/**  
	 * Ogre constructor  
	 * 
	 * @param x initial Ogre coordinates x
	 * @param y initial Ogre coordinates y
	 */
	public Ogre(int x, int y) {
		super(x, y, 'O');
		stunned = false;
		counter = 0;
	}
	
	/**  
	 * Ogre constructor  
	 * 
	 * @param coor initial Ogre coordinates
	 */
	public Ogre(Coordinates coor) {
		super(coor.getX(), coor.getY(), 'O');
		club = new Character(coor.getX(), coor.getY(), '*');
		stunned = false;
		counter = 0;
	}

	/**
	 * 
	 * @return return Ogre's club as a character
	 */
	public Character getClub(){
		return club;
	}
	
	/**
	 * 
	 * @return return true if ogre is stunned
	 */
	public boolean isStunned(){
		return stunned;
	}
	
	/**
	 * Sets the ogre stun true and changes his icon to '8'
	 */
	public void getHit(){
		stunned = true;
		setIcon('8');
	}
	
	/**
	 * Sets ogre stun to false and changes his icon to '	'
	 */
	public void recovery() {
		stunned = false;
		setIcon('O');
	}
	
	/**
	 * changes Ogres coordinates to new_pos if he is not stunned, if he is stunned update his counter
	 * @param c imput from keyboard
	 * @param new_pos new coordinates fo the ogre
	 */
public void updateOgre(char c, Coordinates new_pos){	
	
	//see if is stunned
	if(stunned){
		counter++;
		
		if(counter == 2){
			stunned = false;
			return;
		}
		return;
	}
	
		switch (c) {
			case 'X':
				break;
				
			case 'I':
				break;
				
			case ' ':
				coordinates = new_pos;
				this.setIcon('O');
				break;
				
			case 'S':
				break;
				
			case 'k':
				coordinates = new_pos;
				this.setIcon('$');
				break;

			case '*':
				break;
			
			default:
				break;
		}
		
	}

	/**
	 * changes the coordinates of the ogre in board
	 * @param board where the ogre coordinates will be changed
	 */
	public void moveOgre(Board board) {

		Random rand = new Random();		
		int random = rand.nextInt(4);
		
		Coordinates new_pos = new Coordinates(this.coordinates.getX(), coordinates.getY());
		char c = 'X' ;
	
		while(c != ' ' && c != 'k'){
			
			random = rand.nextInt(4);
			
			new_pos = super.newCoordinates(this.coordinates, ogreKeys[random]);

			c = board.getIcon(new_pos);
		}
		
		updateOgre(c, new_pos);

	}
	
	/**
	 * changes the coordinates of the ogre club in board
	 * @param board where the ogre club coordinates will be changed
	 */	
public void moveClub(Board board) {
		
		Random rand = new Random();	
		int random;
		Coordinates new_pos = new Coordinates();
		char c;

		do{
			random = rand.nextInt(4);
			new_pos = super.newCoordinates(this.coordinates, ogreKeys[random]);
			c = board.getIcon(new_pos);

			if(new_pos.getX() == board.getKPos().getX() && new_pos.getY() == board.getKPos().getY()){
				club.setCoordinates(new_pos);
				club.setIcon('$');
				return;
			}

		}while(c != ' ' && c != 'k');

		club.setCoordinates(new_pos);
}
	
}
