package dkeep.test;

import static org.junit.Assert.*;
import org.junit.Test;

import dkeep.logic.*;
import java.util.ArrayList;

public class TestDungeonGameLogic {
	
	char[][] map_1 ={{'X','X','X','X','X'},
					 {'X','H',' ','G','X'},
					 {'I',' ',' ',' ','X'},
					 {'I','k',' ',' ','X'},
					 {'X','X','X','X','X'} };
	
	protected char[][] map_2 = { 
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
	
	
	@Test
	public void moveHeroIntoFreeCell() {
		Game game = new Game(1,"Rookie");
		game.setBoard(new Dungeon(map_1,"Rookie"));
		((Dungeon) game.getBoard()).setGuard(new Guard(new Coordinates(1, 3)));

		assertEquals(1, game.getBoard().getHero().getCoordinates().getX());
		assertEquals(1, game.getBoard().getHero().getCoordinates().getY());

		game.setStr('s');
		game.updateGame();
		game.updateBoard();

		assertEquals(2, game.getBoard().getHero().getCoordinates().getX());
		assertEquals(1, game.getBoard().getHero().getCoordinates().getY());
		
		assertEquals(game.getBoard().getIcon(new Coordinates(2, 1)), 'H');
	}
	
	@Test
	public void moveHeroIntoWall() {
		Game game = new Game(1,"Rookie");
		game.setBoard(new Dungeon(map_1,"Rookie"));

		game.setStr('a');
		game.updateGame();

		assertEquals(1, game.getBoard().getHero().getCoordinates().getX());
		assertEquals(1, game.getBoard().getHero().getCoordinates().getY());
	}
	
	@Test
	public void testInvalidDirection() {
		Game game = new Game(1,"Rookie");
		game.setBoard(new Dungeon(map_1,"Rookie"));

		game.setStr('q');
		game.updateGame();

		assertEquals(1, game.getBoard().getHero().getCoordinates().getX());
		assertEquals(1, game.getBoard().getHero().getCoordinates().getY());
}
	
	@Test
	public void heroIsCapturedLeft() {
		Game game = new Game(1,"Rookie");
		game.setBoard(new Dungeon(map_1,"Rookie"));
		((Dungeon) game.getBoard()).setGuard(new Guard(new Coordinates(1, 3)));

		assertFalse(game.isOver());
		
		game.setStr('d');
		game.updateGame();
	


		assertTrue(game.isOver());
}
	
	@Test
	public void heroIsCapturedDown() {
		Game game = new Game(1,"Rookie");
		game.setBoard(new Dungeon(map_1,"Rookie"));
		((Dungeon) game.getBoard()).setGuard(new Guard(new Coordinates(1, 3)));

		assertEquals(game.getBoard().getIcon(new Coordinates(1, 3)), 'G');

		assertFalse(game.isOver());
		
		game.setStr('s');
		game.updateGame();
		game.setStr('d');
		game.updateGame();
		game.setStr('d');
		game.updateGame();

		assertTrue(game.isOver());

}
	
	@Test
	public void heroIsCapturedRight() {
		Game game = new Game(1,"Rookie");
		game.setBoard(new Dungeon(map_1,"Rookie"));
		((Dungeon) game.getBoard()).setGuard(new Guard(new Coordinates(3, 2)));

		game.clean();
		game.updateBoard();
		
		assertFalse(game.isOver());
		
		game.setStr('d');
		game.updateGame();
		game.setStr('d');
		game.updateGame();
		game.setStr('s');
		game.updateGame();
		game.setStr('s');
		game.updateGame();

		assertTrue(game.isOver());

	}
	
	@Test
	public void heroIsCapturedUp() {
		Game game = new Game(1,"Rookie");
		game.setBoard(new Dungeon(map_1,"Rookie"));
		((Dungeon) game.getBoard()).setGuard(new Guard(new Coordinates(2, 2)));

		game.clean();
		game.updateBoard();
		
		assertFalse(game.isOver());
		
		game.setStr('d');
		game.updateGame();

		assertTrue(game.isOver());
	}
	
	@Test
	public void moveHeroIntoClosedDoor() {
		Game game = new Game(1,"Rookie");
		game.setBoard(new Dungeon(map_1,"Rookie"));
		((Dungeon) game.getBoard()).setGuard(new Guard(new Coordinates(1, 3)));

		game.setStr('s');
		game.updateGame();
		game.setStr('a');
		game.updateGame();

		assertEquals(2, game.getBoard().getHero().getCoordinates().getX());
		assertEquals(1, game.getBoard().getHero().getCoordinates().getY());

		assertFalse(game.isOver());

	}
	
	@Test
	public void doorsOpenWhenLeverActivated() {
		Game game = new Game(1,"Rookie");
		game.setBoard(new Dungeon(map_1,"Rookie"));
		assertEquals('I', game.getBoard().getIcon(new Coordinates(2,0)));

		game.setStr('s');
		game.updateGame();
		game.setStr('s');
		game.updateGame();

		assertEquals('S', game.getBoard().getIcon(new Coordinates(2,0)));
	}
	
	@Test
	public void testDoors() {
		Game game = new Game(1,"Rookie");
		game.setBoard(new Dungeon(map_1,"Rookie"));
		assertEquals('I', game.getBoard().getIcon(new Coordinates(2,0)));

		game.setStr('s');
		game.updateGame();

		assertEquals('I', game.getBoard().getIcon(new Coordinates(2,0)));
	}
	
	@Test
	public void levelUpUponReachingStairs() {
		Game game = new Game(1,"Rookie");
		game.setBoard(new Dungeon(map_1,"Rookie"));
		((Dungeon) game.getBoard()).setGuard(new Guard(new Coordinates(1, 3)));

		game.clean();
		game.setStr('s');
		game.updateGame();
		
		game.clean();
		game.setStr('s');
		game.updateGame();
		
		game.clean();
		game.setStr('a');
		game.updateGame();
				
		assertTrue(game.getBoard() instanceof Keep);
	}
	
	@Test
	public void heroNotCapuredByDrunken() {
		Game game = new Game(1,"Druken");
		game.setBoard(new Dungeon(map_1,"Druken"));

		((Dungeon) game.getBoard()).setGuard(new Drunken(new Coordinates(1, 3)));

		assertFalse(game.isOver());

		game.clean();
		game.updateBoard();
		
		((Dungeon) game.getBoard()).getGuard().setAsleep();
		
		game.setStr('d');
		game.updateGame();
		((Dungeon) game.getBoard()).getGuard().setAsleep();


		((Dungeon) game.getBoard()).getGuard().setCoordinates(1, 3);

		assertFalse(game.isOver());
		
	}
	
	@Test
	public void testRookieInicialPosition() {
		Game game = new Game(1,"Rookie");
		game.setBoard(new Dungeon(map_2,"Rookie"));
		
		int oldcx = ((Dungeon) game.getBoard()).getGuard().getCoordinates().getX();
		int oldcy = ((Dungeon) game.getBoard()).getGuard().getCoordinates().getY();

		int newcx = ((Dungeon) game.getBoard()).getGuard().getCoordinates().getX();
		int newcy = ((Dungeon) game.getBoard()).getGuard().getCoordinates().getY();
		
		for(int i = 0; i < 48; i++){
			
			((Dungeon) game.getBoard()).getGuard().moveGuard();
			newcx = ((Dungeon) game.getBoard()).getGuard().getCoordinates().getX();
			newcy = ((Dungeon) game.getBoard()).getGuard().getCoordinates().getY();
		}
		
		assertEquals(newcx,oldcx);
		assertEquals(newcy,oldcy);
	}
	
	

	@Test
	public void testSuspiciousOneMove() {
		Game game = new Game(1,"Suspicious");
		game.setBoard(new Dungeon(map_2,"Suspicious"));
		
		Coordinates pos_4 = new Coordinates(2,8);
		Coordinates pos_2 = new Coordinates(1,7);
		
		((Dungeon) game.getBoard()).getGuard().setCoordinates(new Coordinates(7,3));
		
		((Dungeon) game.getBoard()).getGuard().moveGuard();
		Coordinates new_pos = ((Dungeon) game.getBoard()).getGuard().getCoordinates();
			
		
		if( new_pos ==  pos_4)
			assertEquals(pos_4,new_pos);
		if( new_pos == pos_2)
			assertEquals(pos_2,new_pos);		
	}
	
	@Test
	public void testDrunkenSleeping() {
		
		Game game = new Game(1,"Drunken");
		game.setBoard(new Dungeon(map_2,"Drunken"));
		((Dungeon) game.getBoard()).setGuard(new Drunken(new Coordinates(1, 8)));
		
		for(int i = 0; i < 1000; i++){
		
			((Dungeon) game.getBoard()).getGuard().moveGuard();
			
			if(((Dungeon) game.getBoard()).getGuard().getIcon() == 'g')
				assertEquals(((Dungeon) game.getBoard()).getGuard().getIcon(),'g');
			else assertEquals(((Dungeon) game.getBoard()).getGuard().getIcon(),'G');
		
		}
		
	}
	
	
	
	
	

}
