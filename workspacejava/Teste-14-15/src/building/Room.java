package building;

import java.util.ArrayList;

public class Room implements Facility{
	protected Building building;
	protected String name;
	protected int floor;
	protected String number;
	protected int capacity;
	
	protected ArrayList<User> users = new ArrayList<User>(); 
	
	public Room(Building edificio, String numero, int andar){
		building = edificio;
		number = numero;
		floor = andar;
		name = edificio.getName() + numero;
		
		if(edificio.getMaxFloor() < floor){
			throw new IllegalArgumentException();
		}
	}
	
	public Room(Building edificio, String numero, int andar, int capacidade) throws DuplicateRoomException{
		building = edificio;
		number = numero;
		floor = andar;
		name = edificio.getName() + numero;
		capacity = capacidade;
		
		building.addCapacity(capacidade);
		
		if(edificio.getMaxFloor() < floor){
			throw new IllegalArgumentException();
		}
		
		
		ArrayList<Room> rooms = edificio.getRooms();
		for(Room elem : rooms){
			if(this.equals(elem))
				throw new DuplicateRoomException();
		}
	}
	
	public Building getBuilding(){
		return building;
	}
	
	public String getNumber(){
		return number;
	}
	
	public String getName(){
		return name;
	}
	
	public int getFloor(){
		return floor;
	}
	
	public String toString(){
		return "Room(" + building.getName() + "," + number + ")";
	}
	 
	public int getCapacity(){
		return capacity;
	}
	
	public ArrayList<User> getUsers(){
		return users;
	}
	
	public void addUsers(User u){
		users.add(u);
	}
	
	public boolean equals(Room r){
		if(building ==r.getBuilding() && name == r.getName() && number == r.getNumber() && r.getFloor() == floor)
			return true;
		return false;
	}
}

