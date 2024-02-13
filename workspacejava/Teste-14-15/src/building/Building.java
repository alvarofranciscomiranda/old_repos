package building;

import java.util.ArrayList;

public class Building implements Facility {
	public String name;
	public int minFloor;
	public int maxFloor;
	int capacity;
	
	public ArrayList<Room> rooms = new ArrayList<Room>(); 
	
	public Building(String nome, int min, int max){
		name = nome;
		minFloor = min;
		maxFloor = max;
		
		if(max < min){
			throw new IllegalArgumentException();
		}
	}
	
	public String getName(){
		return name;
	}
	
	public int getMinFloor(){
		return minFloor;
	}
	
	public int getMaxFloor(){
		return maxFloor;
	}	
	
	public String toString(){
		return "Building(" + name + ")";
	}
	
	public int getCapacity(){
		return capacity;
	}
	
	public void addCapacity(int n){
		capacity += n;
	}
	
	public ArrayList<Room> getRooms(){
		return rooms;
	}
	
	public void addRoom(Room r) throws DuplicateRoomException {
		rooms.add(r);
	}
}

