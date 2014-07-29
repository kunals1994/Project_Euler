public class Nineteen{
	public static void main (String[] args){
		//Start Date
		Date x = new Date (1, 1 , 1900);

		Date end = new Date (31, 12 ,2000);

		x.incDays(6);

		int solution = 0;
		while(x.compareTo(end) > 0){
			if(x.getDay() == 1){
				solution +=1;
				System.out.println("Year: "+x.getYear() + " Month: " + x.getMonth() + " Day: " + x.getDay());
	
			}
			x.incDays(7);
		}

		System.out.println("Solution: "+solution);
	}
}