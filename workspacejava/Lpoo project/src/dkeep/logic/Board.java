package dkeep.logic;

/**
 * Board.java - The Board class
 * @author Eu
 *
 */

public abstract class Board {

	protected Hero hero;
	protected char[][] board;
	
	
	/**  
	 * Board constructor
	 * 
	 * @param board the board of the game
	 */
	public Board(char[][] board) {
		
		this.board = board;
	}
	
	/**  
	 * Gets the character symbol
	 * 
	 * @param coor the coordinates of the character
	 * @return the character icon
	 */
	public char getIcon(Coordinates coor) {

		char c;
		c = board[coor.getX()][coor.getY()];

		return c;
	}
	
	/**  
	 * Prints the board
	 *
	 * @return the board printed
	 */
	public void printBoard() {
		

			for (int i = 0; i < board.length; i++) {

				for (int j = 0; j < board[0].length; j++) {
					 System.out.print(board[i][j]);
				}
				System.out.println();
			}	
	}
	
	/**  
	 * Draws a Character in his coordinates
	 *
	 * @param c the Character that is being printed
	 */
	public void drawCharacter(Character c) {
		
		if(c != null){
			char i = c.getIcon();
			this.board[c.coordinates.getX()][c.coordinates.getY()] = i;
		}
	}
	
	/**  
	 * Cleans a Character in his coordinates
	 *
	 * @param c the Character that is being cleaned
	 */
	public  void cleanCharacter(Character c) {
		
		if(c != null){
			board[c.coordinates.getX()][c.coordinates.getY()] = ' ';
		}
	}
	
	/**  
	 * Opens the doors of the maze
	 *
	 */
	public  void openDoors() {

		for (int i = 0; i < board.length; i++) {
			for (int j = 0; j < board[0].length; j++) {
				if (board[i][j] == 'I' && (j == 0 || i == 0))
					board[i][j] = 'S';
			}
		}
	}
	
	/**  
	 * Searches a character in a certain board
	 *
	 * @param c the icon of the character
	 * @return the position of the character c
	 */
	public Coordinates searchIcon(char c){
		for (int i = 0; i < board.length; i++) {
			for (int j = 0; j < board[0].length; j++) {
				if (board[i][j] == c)
					return new Coordinates(i,j);
			}
		}
		
		return new Coordinates(-1,-1);
}
	
	/**  
	 * Verifies if the victim is captured or not
	 *
	 * @param victim the victim
	 * @param captor the captor
	 * @return true if the victim is captured, false otherwise
	 */
	public boolean isCaptured(Character victim, Character captor) {

		if(victim != null && captor != null){
		if (captor.getIcon() == 'g')
			return false;

		if (victim.coordinates.getX() == (captor.coordinates.getX() + 1) && victim.coordinates.getY() == captor.coordinates.getY() ||
				victim.coordinates.getX() == (captor.coordinates.getX() - 1) && victim.coordinates.getY() == captor.coordinates.getY() ||
				victim.coordinates.getX() == captor.coordinates.getX() && victim.coordinates.getY() == (captor.coordinates.getY() + 1) ||
				victim.coordinates.getX() == captor.coordinates.getX() && victim.coordinates.getY() == (captor.coordinates.getY() - 1) ||
				victim.coordinates.getX() == captor.coordinates.getX() && victim.coordinates.getY() == captor.coordinates.getY())
			return true;
		}
		return false;
	}
	
	/**  
	 * Updates the game state
	 */
	public abstract void update(char str);
	
	/**  
	 * Cleans the screen
	 */
	public abstract void clean();
	
	/**  
	 * Draws the game board
	 */
	public abstract void draw();
	
	/**  
	 * Checks if the game is over
	 * 
	 * @return true if the game is over
	 */
	public abstract boolean isOver();
	
	/**  
	 * Checks if you should go to next level
	 * 
	 * @return true if you should, false otherwise
	 */
	public abstract boolean next();
	
	/**  
	 * Gets hero
	 * 
	 * @return hero
	 */
	public Hero getHero() {
		return hero;
	}
	
	/**  
	 * Gets the coordinates of the key
	 * 
	 * @return position of the key
	 */
	public abstract Coordinates getKPos();
	
	/**  
	 * Gets the rows
	 * 
	 * @return rows
	 */
	public int getRows() {
		return board.length;		
	}
	
	/**  
	 * Gets the cols
	 * 
	 * @return cols
	 */
	public int getCols() {
		return board[0].length;		
	}
	
	/**  
	 * Gets the map
	 * 
	 * @return map
	 */
	public char[][] getBoard() {
		return board;
	}
	
}
