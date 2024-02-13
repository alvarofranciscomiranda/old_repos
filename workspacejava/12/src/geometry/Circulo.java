package geometry;

public class Circulo implements Figura {
	protected Ponto p;
	protected int r;
	
	public Circulo(Ponto p, int r){
		this.p = p;
		this.r = r;
		
		if(r < 0){
			throw new IllegalArgumentException();
		}
	}

	public int getRaio() {
		return this.r;
	}
	
	public Ponto getCentro() {
		return this.p;
	}
	
	public double getArea(){
		return this.r * this.r * Math.PI;
	}
	
	public double getPerimetro(){
		return this.r * 2 * Math.PI;
	}
	
}
