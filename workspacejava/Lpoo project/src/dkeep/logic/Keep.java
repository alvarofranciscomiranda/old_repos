package dkeep.logic;

import java.util.ArrayList;
import dkeep.logic.Hero.HeroState;
import java.util.Random;


/**  
* Dungeon.java - Second Level implementation
* @author  Eu 
* 
*/ 
public class Keep extends Board {
	
	protected Character key;
	protected Character club;
	protected ArrayList<Ogre> ogres = new ArrayList<Ogre>();

	boolean won = false;

	/**  
	 * Level 2 constructor - Keep 
	 * 
	 * @param board  level board
	 * @param num_ogres number of ogres
	 */
	public Keep(char[][] board, int num_ogres) {
		super(board);

		Coordinates hero_pos = super.searchIcon('H');
		Coordinates club_pos = super.searchIcon('*');
		Coordinates key_pos = super.searchIcon('k');
	

		hero = new Hero(hero_pos);
		key = new Character(key_pos, 'k');
		club = new Character(club_pos, '*');

		
		Random rand = new Random();
		int OgreX = 0;
		int OgreY = 0;
		
		for (int i = 0; i < num_ogres; i++)
			OgreX = (rand.nextInt(7) + 1);
			OgreY = (rand.nextInt(8) + 1);
			ogres.add(new Ogre(new Coordinates(OgreX, OgreY)));

	}
		
	@Override
	public void update(char str) {

		hero.moveHero(str, this);

		if (hero.hasKey())
			hero.setIcon('K');

		for (Ogre ogre : ogres) {
			ogre.moveOgre(this);
			ogre.moveClub(this);
		}

		if (hero.getState() == HeroState.DOOR && hero.hasKey()){
			openDoors();
		}

		if (hero.getState() == HeroState.STAIR)
			won = true;
	}
	
	@Override
	public void clean() {
		cleanCharacter(hero);

		for (Ogre ogre : ogres) {
			cleanCharacter(ogre);
			cleanCharacter(ogre.getClub());
		}

	}
	
	@Override
	public void draw() {
		drawCharacter(hero);

		if (!hero.hasKey())
			drawCharacter(key);

		if (!hero.hasClub())
			drawCharacter(club);

		for (Ogre ogre : ogres) {
			drawCharacter(ogre);
			drawCharacter(ogre.getClub());
		}

	}
	
	@Override
	public boolean isOver() {
		for (Ogre ogre : ogres) {

			if (isCaptured(ogre, hero) && hero.hasClub())
				ogre.getHit();

			if (isCaptured(hero, ogre) && !hero.hasClub()) {
				return true;
				
			}

			if (isCaptured(hero, ogre.getClub())) {
				return true;
			}
		}

		return false;
	}
	
	@Override
	public boolean next() {
		return won;
	}
	
	/**
	 * 
	 * @return arrayList of ogres
	 */
	public ArrayList<Ogre> getOgres(){
		return ogres;
	}
	
	@Override
	public Coordinates getKPos() {
		return new Coordinates(8,1);
	}

	
}
