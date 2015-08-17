#include <iostream>
#include <string>

class Calendar{
public:
	Calendar(){}
	~Calendar(){}

	void getDays(int year, int month, int days){}
	void showCalendar(){
		int firstDay=0;
		for(int month=1; month<13; month++){
			std::string monthName[12] = {"January","Febuary","March","April","May","June","July","August","September","October","November","December"};
			std::string day[7]={"sun","mon","tue","wed","thu","fri","sat"};

			std::cout << "\t\t\t"  <<  month << "(" << monthName[month-1] << ")" << std::endl;
			for(int k=0; k<7; k++){
				std::cout << day[k] << "\t";
			}
			std::cout << std::endl;
			int date=1;
			int endDate;


			switch (month){	
			case 1:
			case 3:
			case 5: 
			case 7: 
			case 8: 
			case 10: 
			case 12:
				endDate = 31;
				break;

			case 4:
			case 6:
			case 9:
			case 11:
				endDate = 30;
				break;

			case 2:
				endDate = 28;
				break;
			default:
				break;

			}
			for(int i=0; i<5; i++){
				if (i > 0)
					firstDay = 0;
					
					for(int j=0; j<7; j++){
					if (j < firstDay)
					{
						std::cout << " " << "\t";
						continue;
					}
					else
						std::cout << date << "\t";
					date++;
					if (date > endDate){
						firstDay = j+1;
						break;
					}

				}
				std::cout << std::endl;
				if (date > endDate)
					break;
					
			}
			std::cout << std::endl;
		}
	}
};

int main (){
	Calendar calendar;
	calendar.showCalendar();
	return 0;
}

