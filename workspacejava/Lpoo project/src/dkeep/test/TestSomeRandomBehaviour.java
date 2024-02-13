package dkeep.test;

import static org.junit.Assert.*;
import org.junit.Test;

import dkeep.logic.*;

public class TestSomeRandomBehaviour {
	

	private char[][] map = { 
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
			{ 'I', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'O', 'X' }, 
			{ 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', 'X' },
			{ 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X' }, 
			{ 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'k', 'X' },
			{ 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X' }, 
			{ 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X' },
			{ 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X' }, 
			{ 'X', 'H', ' ', '*', ' ', ' ', ' ', ' ', ' ', 'X' },
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' }};
	


	private boolean isLeft(Coordinates new_pos, Coordinates old_pos) {

		if (new_pos.getX() == old_pos.getX() - 1 && new_pos.getY() == old_pos.getY())
			return true;
		else
			return false;
	}
	
	private boolean isRight(Coordinates new_pos, Coordinates old_pos) {

		if (new_pos.getX() == old_pos.getX() + 1 && new_pos.getY() == old_pos.getY())
			return true;
		else
			return false;
	}
	
	private boolean isUp(Coordinates new_pos, Coordinates old_pos) {

		if (new_pos.getX() == old_pos.getX()  && new_pos.getY() == old_pos.getY()-1)
			return true;
		else
			return false;
		
	}
	
	private boolean isDown(Coordinates new_pos, Coordinates old_pos) {

		if (new_pos.getX() == old_pos.getX()  && new_pos.getY() == old_pos.getY()+1)
			return true;
		else
			return false;
		
	}
	
	@Test(timeout =1000)
	public void testClubRandomPositions() {
		Game game = new Game(1,"Rookie");
		game.setBoard(new Keep(map,1));
		
		boolean left= false;
		boolean right= false;
		boolean up = false;
		boolean down = false;
		boolean key = false;
		
		Coordinates ogre_pos;
		Coordinates club_pos;
		
		while(!left || !right || !up || !down){
			
			((Keep) game.getBoard()).getOgres().get(0).moveOgre(game.getBoard());
			((Keep) game.getBoard()).getOgres().get(0).moveClub(game.getBoard());
			
			ogre_pos = ((Keep) game.getBoard()).getOgres().get(0).getCoordinates();
			club_pos = ((Keep) game.getBoard()).getOgres().get(0).getClub().getCoordinates();
			
			if(isLeft(ogre_pos, club_pos))
				left = true;
			
			if(isRight(ogre_pos, club_pos))
				right = true;
			
			if( isUp(ogre_pos, club_pos))
				up = true;
			
			if( isDown(ogre_pos, club_pos))
				down = true;
			
			if(((Keep) game.getBoard()).getOgres().get(0).getClub().getIcon() == '$'){
				
				assertEquals(((Keep) game.getBoard()).getOgres().get(0).getClub().getCoordinates(), new Coordinates(8,1));
				key = true;
				
			}
			
	
		}
	}

}


