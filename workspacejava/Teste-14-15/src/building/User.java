package building;

public class User  {
	protected String name;
	
	public User(String nome){
		name = nome;
	}
	
	public String getName(){
		return name;
	}
	
	public boolean equals(User user){
		if(name == user.name)
			return true;
		
		return false;
	}
}
