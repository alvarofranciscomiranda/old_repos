package dkeep.logic;

//import dkeep.Game.GameState;
import dkeep.logic.Hero.HeroState;


/**  
* DungeonMap.java - First Level implementation
* @author  Eu 
* 
*/ 
public class Dungeon extends Board {

	protected Guard guard;
	protected Character lever;
	
	boolean next_map = false;
	
	/**  
	 * Level 1 constructor - Dungeon 
	 * 
	 * @param board  level board
	 * @param guardtype  type of guard
	 */
	public Dungeon(char[][] board, String guardType) {
		
		super(board);
		
		Coordinates hero_pos = super.searchIcon('H');
		Coordinates guard_pos = super.searchIcon('G');
		Coordinates lever_pos = super.searchIcon('k');

		hero = new Hero(hero_pos);
		lever = new Character(lever_pos, 'k');

		switch (guardType) {
			case "Suspicious":
				guard = new Suspicious(guard_pos);
				break;
			case "Rookie":
				guard = new Rookie(guard_pos);
				break;
			case "Drunken":
				guard = new Drunken(guard_pos);
				break;
		}

	}
	
	@Override
		public void update(char str){

			hero.moveHero(str, this);

			guard.moveGuard();

			if (hero.getState() == HeroState.STAIR) {
				next_map = true;
				hero.setKey(false);

			}

			if (hero.hasKey())
				super.openDoors();

	}
		
		@Override
		public void draw() {
			drawCharacter(lever);
			drawCharacter(hero);
			drawCharacter(guard);
	}
		
		@Override
		public void clean() {
			cleanCharacter(hero);
			cleanCharacter(guard);

	}
		
		@Override
		public boolean isOver() {

			return super.isCaptured(hero, guard);
				
	}
		
		@Override
		public boolean next(){
			return next_map;
	}
		
		/**
		 * sets board guard g
		 * @param g new guard
		 */
		public void setGuard(Guard g){
			guard = g;
	}
		
		/**
		 * 
		 * @return this guard
		 */
		public Guard getGuard(){
			return guard;
			
	}
		
		@Override
		public Coordinates getKPos() {
			return lever.getCoordinates();
	}
	
}
