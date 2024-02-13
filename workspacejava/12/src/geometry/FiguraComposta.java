package geometry;

public class FiguraComposta implements Figura, Countable {
	Figura figuras[];
	
	public FiguraComposta(Figura[] figuras2) {
		this.figuras = figuras2;
	}

	public double getArea() {
		double result = 0;
		for(Figura elem : figuras){
			result += elem.getArea();
		}
		return result;
	}

	public double getPerimetro() {
		// TODO Auto-generated method stub
		return 0;
	}
	
	public int count(){
		int result = 0;
		for(Figura elem : figuras){
			result++;
		}
		return result;
	}

}
