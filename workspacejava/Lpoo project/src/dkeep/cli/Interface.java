package dkeep.cli;

import java.util.Scanner;

import dkeep.logic.Game;

public class Interface {
	
	public static void main(String[] args){
		

		Game game = new Game(3,"Rookie");
		Scanner reader = new Scanner(System.in);
	
		while(true){

		game.updateBoard();
		
		System.out.println();
		game.printBoard();
		
		System.out.println("\n Use the w, a, s, d keys to control the Hero.");
		System.out.print(" Insert key : ");
				
		game.clean();
		
		if(game.isOver())
			break;
		
		char x = reader.next().charAt(0);
		
		game.setStr(x);

		game.updateGame();
			
		}
		game.printEnd();
		reader.close();
		
	}

}
