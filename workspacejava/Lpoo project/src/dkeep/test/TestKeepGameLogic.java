package dkeep.test;

import static org.junit.Assert.*;
import org.junit.Test;

import dkeep.logic.*;

public class TestKeepGameLogic {
	char[][] map = {
			
			{ 'X', 'I', 'X', 'X', 'X' },
			{ 'X', 'H', ' ', 'O', 'X' }, 
			{ 'X', '*', ' ', '*', 'X' },
			{ 'X', 'k', ' ', ' ', 'X' }, 
			{ 'X', 'X', 'X', 'X', 'X' } 
	};
	
	void updateCoordinates(Game game){
		((Keep) game.getBoard()).getOgres().get(0).setCoordinates(1,3);
		((Keep) game.getBoard()).getOgres().get(0).getClub().setCoordinates(2,3);
	}
	
	@Test
	public void heroIsCapturedByOgre() {
		Game game = new Game(1,"Rookie");
		game.setBoard(new Keep(map,1));
		updateCoordinates(game);
		
		assertFalse(game.isOver());
	
		game.setStr('d');
		game.updateGame();
		updateCoordinates(game);

		assertTrue(game.isOver());

	}
	
	@Test
	public void heroIsCapturedByClub() {
		Game game = new Game(1,"Rookie");
		game.setBoard(new Keep(map,1));
		updateCoordinates(game);
		
		assertFalse(game.isOver());
	
		game.setStr('s');
		game.updateGame();

		game.setStr('d');
		game.updateGame();
		updateCoordinates(game);
		

		assertTrue(game.isOver());

	}
	
	@Test
	public void heroHasKey(){
		Game game = new Game(1,"Rookie");
		game.setBoard(new Keep(map,1));
		updateCoordinates(game);
		 
		game.setStr('s');
		game.updateGame();
		game.setStr('s');
		game.updateGame();
		 
		 assertTrue(game.getHero().hasKey());
		 
	}
	
	@Test
	public void heroMovesIntoClosedDoor() {
		Game game = new Game(1,"Rookie");
		game.setBoard(new Keep(map,1));
		updateCoordinates(game);
		
		assertEquals('I',game.getBoard().getIcon(new Coordinates(0,1)));
		
		game.setStr('s');;
		game.updateGame();
		
		assertEquals('I',game.getBoard().getIcon(new Coordinates(0,1)));
	}
	
	@Test
	public void heroMovesIntoDoor() {
		Game game = new Game(1,"Rookie");
		game.setBoard(new Keep(map,1));
		updateCoordinates(game);
		
		assertEquals('I',game.getBoard().getIcon(new Coordinates(0,1)));
		
		 game.clean();
		 game.setStr('s');
		 game.updateGame();

		 
		 game.setStr('s');
		 game.updateGame();
		 
		 assertTrue(game.getHero().hasKey());
		 
		 game.setStr('w');
		 game.updateGame();
		
		 
		 game.setStr('w');
		 game.updateGame();
		 
		 game.setStr('w');
		 game.updateGame();
	
		assertEquals('S',game.getBoard().getIcon(new Coordinates(0,1)));

	}
	
	@Test
	public void heroWins() {
		Game game = new Game(1,"Rookie");
		game.setBoard(new Keep(map,1));
		updateCoordinates(game);
		
		assertEquals('I',game.getBoard().getIcon(new Coordinates(0,1)));
		
		
		 game.clean();
		 game.setStr('s');
		 game.updateGame();

		 
		 game.setStr('s');
		 game.updateGame();
		 
		 assertTrue(game.getHero().hasKey());
		 
		 game.setStr('w');
		 game.updateGame();
		
		 
		 game.setStr('w');
		 game.updateGame();
		 
		 game.setStr('w');
		 game.updateGame();
	
		assertEquals('S',game.getBoard().getIcon(new Coordinates(0,1)));
		
		game.setStr('w');
		game.updateGame();
		
		assertTrue(game.isOver());

	}
	
	@Test
	public void heroPicksUpClub() {
		Game game = new Game(1,"Rookie");
		game.setBoard(new Keep(map,1));
		updateCoordinates(game);
		
		assertFalse(game.getHero().hasClub());
		
		game.setStr('s');
		game.updateGame();
		updateCoordinates(game);


		game.setStr('w');
		game.updateGame();
		updateCoordinates(game);
		
		assertTrue(game.getHero().hasClub());
		assertEquals(game.getHero().getIcon(), 'A');
		
	
	}
	
	@Test
	public void ogreGetsStuned() {
		
		Game game = new Game(1,"Rookie");
		game.setBoard(new Keep(map,1));
		updateCoordinates(game);
		
		assertFalse(game.getHero().hasClub());
		
		game.clean();
		game.setStr('s');
		game.updateGame();
		updateCoordinates(game);

		game.clean();
		game.setStr('w');
		game.updateGame();
		updateCoordinates(game);
		
		game.clean();
		game.setStr('d');
		game.updateGame();
		updateCoordinates(game);

		assertFalse(game.isOver());
		assertTrue(((Keep) game.getBoard()).getOgres().get(0).isStunned());
		assertEquals(((Keep) game.getBoard()).getOgres().get(0).getIcon(), '8');
		
		
		game.setStr('a');
		game.updateGame();

		assertTrue(((Keep) game.getBoard()).getOgres().get(0).isStunned());
		
		game.setStr('a');
		game.updateGame();
		
		assertFalse(((Keep) game.getBoard()).getOgres().get(0).isStunned());
	

	}
	
	@Test
	public void ogreClub() {
		
		Game game = new Game(1,"Rookie");
		game.setBoard(new Keep(map,1));
		updateCoordinates(game);
		
		assertEquals(((Keep) game.getBoard()).getOgres().get(0).getClub().getIcon(),'*');
		
	}

}
