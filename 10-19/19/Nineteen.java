public class Nineteen{
	public static void main (String[] args){
		//Start Date
		Date x = new Date (1, 1 , 1901);

		Date end = new Date (31, 12 ,2000);

		//Jump to the next Sunday; Jan 1 1901 is a Tuesday; . 
		x.incDays(5);

		int solution = 0;
		while(x.compareTo(end) > 0){
			if(x.getDay() == 1){
				solution +=1;	
			}
			x.incDays(7);
		}

		System.out.println("Solution: "+solution);
	}
}