//Search Calender

#include <iostream>

class Calendar{
	int standardYear;
	int standardMonth;
	int standardDate;
	int standardDays;
public:
	Calendar(){
		standardYear = 1970;
		standardMonth = 1;
		standardDate = 1;
		standardDays = 4; //sun=0, ... ,thu=4, ...
	}

	~Calendar(){}

	int days (int year, int month, int day){

	}


	bool leapYear( int year ){
		if( year % 4 == 0 && year % 100 != 0 || year % 400 ==0)
			return true; //leap year
		else
			return false; //common year
	}

	int numberOfdays( int year, int month){
		if(month == 2)
		{
			if(leapYear(year))
				return 29;
			else
				return 28;
		}

		else{
			switch(month){
				case 1:
				case 3:
				case 5:
				case 8:
				case 10:
				case 12:
					return 31;
					break;

				case 4:
				case 6:
				case 7:
				case 9:
				case 11:
					return 30;
					break;

				default :
					break;
			}
		}

	}

};


int main(void)
{
	Calendar cal;
	if ( cal.leapYear(2004) )
		std::cout << true << std::endl;
	else
		std::cout << false << std::endl;
	
	for(int  i =1; i < 13; i++){
		std::cout << cal.numberOfdays(2004,i) << std::endl;
	}
	
	
	
	
	return 0;
}

