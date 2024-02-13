package geometry;

public class Rectangulo implements Figura {
	protected int x1;
	protected int x2;
	protected int y1;
	protected int y2;
	
	public Rectangulo(int x1,int x2,int y1,int y2){
		this.x1 = x1;
		this.x2 = x2;
		this.y1 = y1;
		this.y2 = y2;
	}
	
	
	public double getPerimetro(){
		return Math.abs(this.x2 - this.x1) * 2 + Math.abs(this.y2 - this.y1) * 2;
	}
	
	public double getArea() {
		return Math.abs(this.x2 - this.x1) * Math.abs(this.y2 - this.y1);
	}

}
