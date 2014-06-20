
public class Main{
	public static void main (String [] args){
		collatzLengthCollection c = new collatzLengthCollection();
		
		int max = 0;
		int maxLen = 0;
		int skip = 0;
		for(int x = 1; x < 1000000; x++){
			int curr = c.getLength(x);
			if (maxLen < curr){
				max = x;
				maxLen = curr;
			}
		}

		System.out.println(max);
	}
}
