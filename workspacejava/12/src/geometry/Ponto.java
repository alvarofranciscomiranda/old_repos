package geometry;

public class Ponto implements Comparable<Ponto>{
	protected int x;
	protected int y;
	
	public Ponto(int x, int y){
		this.x=x;
		this.y=y;
	}
	
	public int getX(){
		return this.x;
	}
	
	public int getY(){
		return this.y;
	}
	
	public String toString(){
		return "(" + this.x + ", " + this.y + ")"; 
	}
	
	public boolean equals(Ponto p){
		if(this.x == p.x && this.y == p.y)
			return true;
		return false;
	}

	public int compareTo(Ponto arg0) {
		if(this.x == arg0.x)
			return this.y - arg0.y;
		return this.x - arg0.x
	}
}
