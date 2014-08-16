public class Date implements Comparable{
	private int day;
	private int month;
	private int year;
	private int dayOfWeek;

	private static final int[] MONTH_LENGTH = {31,28,31,30,31,30,31,31,30,31,30,31};

	public Date(int day, int month, int year){
		this.day = day;
		this.month = month;
		this.year = year;
	}

	public int getDay(){
		return this.day;
	}

	public int getMonth(){
		return this.month;
	}

	public int getYear(){
		return this.year;
	}

	private int getCurrMonthLength(){
		return getMonthLength(this.getMonth(), this.getYear());
	}

	private boolean isLeapYear(){
		return isLeapYear(this.getYear());
	}

	private static boolean isLeapYear(int year){
		boolean ret = false;
		if(year % 4 == 0){
			ret = true;
			if(year % 100 == 0 && year % 400 != 0){
				ret = false;
			}
		}
		return ret;
	}

	/* Only works with a positive input. */
	public void incDays(int increaseBy){

		while(increaseBy >= 365){
			if(!this.isLeapYear()){
				this.year += 1;
				increaseBy -= 365;
			}else if(this.isLeapYear() && increaseBy >= 366){
				this.year += 1;
				increaseBy -= 366;
			}else{
				break;
			}
		}

		int monthLength = this.getCurrMonthLength();
		while(increaseBy >= monthLength){
			if(this.getMonth() == 12){
				this.month = 1;
				this.year += 1;
			}else{
				this.month +=1;
			}

			increaseBy -= monthLength;
			monthLength = this.getCurrMonthLength();
		}

		this.day += increaseBy;

		if(this.getDay() > monthLength){
			this.day -= monthLength;
			if(month == 12){
				this.month = 1;
				this.year += 1;
			}else{
				this.month += 1;
			}
		}
	}

	@Override
	public int compareTo(Object obj){
		Date d = (Date)obj;

		if(d.getYear() != this.getYear()){
			if(d.getYear() > this.getYear()){
				return 1;
			}else{
				return -1;
			}
		}

		if(d.getMonth() != this.getMonth()){
			if(d.getMonth() > this.getMonth()){
				return 1;
			}else{
				return -1;
			}
		}

		return (d.getDay() == this.getDay())?0:((d.getDay() > this.getDay())?1:-1);
	}

	private static boolean isLongMonth(int month){
		return (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12);
	}

	private static int getMonthLength (int month, int year){
		int ret = -1;
		if (month == 2){
			if(isLeapYear(year)){
				ret = 29;
			}else{
				ret = 28;
			}
		}else if(isLongMonth(month)){
			ret = 31;
		}else{
			ret = 30;
		}

		return ret;
	}

}