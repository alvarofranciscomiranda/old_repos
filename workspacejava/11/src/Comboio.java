import java.util.ArrayList;

public class Comboio {
	protected String name;
	protected ArrayList<Carruagem> carruagens = new ArrayList<Carruagem>();
	protected int numPassageiros;
	
	public Comboio(String name){
		this.name = name;
		this.carruagens = null;
	}
	
	public String getNome(){
		return this.name;
	}

	public int getNumLugares() {
		int result = 0;
		for(Carruagem elem : carruagens){
			result += elem.capacidade;
		}
		return result;
	}

	public int getNumCarruagens() {
		return this.carruagens.size();
	}
	
	public void addCarruagem(Carruagem a1) {
		carruagens.add(a1);
	}

	public Carruagem getCarruagemByOrder(int i) {
		return carruagens.get(i);
	}

	public void removeAllCarruagens(int i) {
		ArrayList<Carruagem> temp = new ArrayList<Carruagem>();
		
		for(Carruagem elem : carruagens){
			if(elem.capacidade != i)
				temp.add(elem);
		}
		this.carruagens = temp;
	}

	public int getNumPassageiros() {
		return this.numPassageiros;
	}

	public int getLugaresLivres() {
		return this.getNumLugares() - this.getNumPassageiros();
	}

	public void addPassageiros(int i) throws PassengerCapacityExceeded {
		if(this.numPassageiros + i > this.getNumLugares())
			throw new PassengerCapacityExceeded();
		this.numPassageiros += i;
	}

	public void removePassageiros(int i) {
		this.numPassageiros -= i;
	}
	
	public void removePassageiros() {
		this.numPassageiros = 0;
	}
	
	
	
	
	
}
