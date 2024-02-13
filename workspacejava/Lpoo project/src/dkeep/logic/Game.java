package dkeep.logic;

import java.util.Scanner;

import dkeep.logic.Board;
import dkeep.logic.Guard;
import dkeep.logic.Hero;
import dkeep.logic.Ogre;

import java.util.ArrayList;
import java.util.Random;


/**  
* Game.java - The Game Class
* @author  Eu
* 
*/ 
public class Game {

	public enum GameState {
	 PLAYING, WIN, LOSE
	};
	
	protected GameState state;
	protected char str;
	protected Board board; 
	protected int num_ogres;
	
	protected char[][] board_1 = { 
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
			{ 'X', 'H', ' ', ' ', 'I', ' ', 'X', ' ', 'G', 'X' },
			{ 'X', 'X', 'X', ' ', 'X', 'X', 'X', ' ', ' ', 'X' },
			{ 'X', ' ', 'I', ' ', 'I', ' ', 'X', ' ', ' ', 'X' }, 
			{ 'X', 'X', 'X', ' ', 'X', 'X', 'X', ' ', ' ', 'X' },
			{ 'I', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X' }, 
			{ 'I', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X' },
			{ 'X', 'X', 'X', ' ', 'X', 'X', 'X', 'X', ' ', 'X' }, 
			{ 'X', ' ', 'I', ' ', 'I', ' ', 'X', 'k', ' ', 'X' },
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' } };
	
	protected char[][] board_2 = {
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
			{ 'I', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'k', 'X' }, 
			{ 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X' },
			{ 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X' }, 
			{ 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X' },
			{ 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X' }, 
			{ 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X' },
			{ 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X' }, 
			{ 'X', 'H', ' ', '*', ' ', ' ', ' ', ' ', ' ', 'X' },
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' } };
	

	/**  
	 * Game constructor
	 * 
	 * @param num_ogres  number of ogres
	 * @param guard2 type of guard
	 */
	public Game(int num_ogres, String guard2) {
		
		state = GameState.PLAYING;

		board = new Dungeon(board_1, guard2);
		this.num_ogres = num_ogres;
		
	}
	
	/**  
	 * Gets the Str
	 * 
	 * @return str of the game
	 */
	public char getStr(){
		return this.str;
	}
	
	/**  
	 * Gets the board
	 * 
	 * @return board of the game
	 */
	public Board getBoard() {
		return board;
	}
	
	/**  
	 * Sets the board
	 * 
	 * @param board the board of the game
	 */
	public void setBoard(Board board) {
		this.board = board;
	}
	
	/**  
	 * Sets the str 
	 * 
	 * @param imput off the keyboard 
	 */
	public void setStr(char x){
		this.str = x;
	}
	
	/**  
	 * Prints the board on the console
	 * 
	 * @return the board printed on the console
	 */
	public void printBoard() {

		 board.printBoard();
	}
	
	/**  
	 * Cleans the screen
	 */
	public void clean() {
		board.clean();	
	}
	
	/**  
	 * Draws the board
	 */
	public void updateBoard() {
		
		board.draw();	
	}
	
	
	public void updateGame() {
		
		board.update(str);
		
		if (board instanceof Dungeon && board.next()){
			board = new Keep(board_2,num_ogres);
		}
		
		if (board instanceof Keep && board.next()){
			state = GameState.WIN;
		}		 
	}
	
	/**  
	 * Updates the game state
	 */
	public boolean isOver() {
		
		if(board.isOver()){
			state = GameState.LOSE;
			return true;
		}
	
		if( state == GameState.WIN) 
			return true;
	
		return false;
	}
	

	/**  
	 * Prints the End of the Game
	 */
	public void printEnd() {
		System.out.println();
		System.out.println();

		switch (state) {
		case LOSE:
			System.out.print("---------");
			System.out.print(" YOU LOST ");
			System.out.print("---------");
			break;
		case WIN:
			System.out.print("----------");
			System.out.print(" VICTORY ");
			System.out.print("----------");
			break;
		default:
			break;
		}
	}
	
	/**  
	 * Gets the hero
	 * 
	 * @return hero
	 */
	public Hero getHero() {
		return board.getHero();
	}
	
	/**  
	 * Updates the game with clean, updateGame and updateBoard functions
	 * 
	 * @return hero
	 */
	public void update(){
		
		clean();
		updateGame();
		updateBoard();
	}
	
	/**  
	 * Gets the game state
	 * 
	 * @return state of the game
	 */
	public GameState getState(){
		return state;
	}
	
	
}
