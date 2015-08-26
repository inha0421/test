//Search Calendar

#include <iostream>
#include <stdlib.h> 

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

	int date (int year, int month, int date){

	//numOfLeapYear a,b,c

		int a = (year - standardYear)/4; 
		int b = 0;
		int c = 0;

		if (abs(year-standardYear) >= 100){  
			b = (year - standardYear)/100;
			c = (year - standardYear)/400;
		} 	
		
		int numOfMonth = 0;

		for(int i=1 ; i < month ; i++){ 
			numOfMonth += numberOfDays(year,i);
		}

		return (year - standardYear) * 365 + a - b + c + numOfMonth  + date ; 

	}


	bool leapYear( int year ){
		if( year % 4 == 0 && year % 100 != 0 || year % 400 ==0)
			return true; //leap year
		else
			return false; //common year
	}

	int numberOfDays( int year, int month){
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
				case 7:
				case 8:
				case 10:
				case 12:
					return 31;
					break;

				case 4:
				case 6:
				case 9:
				case 11:
					return 30;
					break;

				default :
					break;
			}
		}

	}

	void printCalendar( int year, int month ){

		std::string monthName[12] = {"January","Febuary","March","April","May","June","July","August","September","October","November","December"};
		std::string day[7]={"sun","mon","tue","wed","thu","fri","sat"};
	
		int firstDays = (this->date(year, month, 1) - this->standardDays) % 7;

		std::cout << "\t\t"  << year << "\t"  << month << "(" << monthName[month-1] << ")" << std::endl;

		for(int d=0; d<7; d++){
			std::cout << day[d] << "\t";
		}

		std::cout << std::endl;	

/* 
		for(int i = 1 ; i <= this->numberOfDays(year,month) ; i++){
			if(i <= firstDays){
				std::cout << " " << "\t" ;
			}
			else if(i > firstDays){	
				std::cout << i << "\t" ;
				
				if ( i % 7 == 0)
					std::cout << std::endl;
			}
		}
*/

		int i = 1;
		int j = 0;
		while ( i <= this->numberOfDays(year, month) )
		{
			if ( j < firstDays)
			{
				std::cout<<"\t";
			}
			else
			{
				std::cout << i << "\t";
				i++;
			}

			j++;

			if ( j % 7  == 0)
				std::cout<<std::endl;
		
		}

		std::cout<<std::endl;
	}
};
 

int main(void){
	Calendar cal;
/*	
	//check num of days

	if ( cal.leapYear(2004) )
		std::cout << true << std::endl;
	else
		std::cout << false << std::endl;
	
	for(int  i =1; i < 13; i++){
		std::cout << cal.numberOfdays(2004,i) << std::endl;
	}
*/	

//  std::cout << cal.date(2000, 3, 6) << std::endl;
//	std::cout << cal.numberOfDays(2015,8) << std::endl;
	int year, month;
	std::cout << "Input Year and Month that you want to know " << std::endl;
	std::cin >> year >> month;
	cal.printCalendar(year, month);
	return 0;

}
