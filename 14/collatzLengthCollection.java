import java.util.HashMap;

public class collatzLengthCollection{
	HashMap <Integer, Integer> lengths;

	public collatzLengthCollection(){
		lengths = new HashMap <Integer, Integer>();
		lengths.put(1, 1);
	}

	public Integer getLength(Integer n){
		Integer potential = lengths.get(n);


		if(potential == null){
			if(n%2 == 0){
				lengths.put(n, 1+this.getLength(n/2));
			}else{
				lengths.put(n, 1+this.getLength(3*n + 1));
			}
		}


		potential = lengths.get(n); 
		return potential;
	}
}
