//Maximillian Yang
//Mutasem Alsari
//Waseem Alawamleh 



#include <iostream>
#include <string>
class ClockTime
{
	public:
		std::string expected;
		std::string display()
		{
			return expected;
		}
		ClockTime(int hours, int min)
		{
			//user input to check for AM, PM;
			//can change to bool fo rbetter data validation
			std::string t = "PM";
			std::string o = "";
			
			std::cout << hours <<":"<< min <<": is it Am or PM?\n";
			std::cin >> t;
			
			// beacuse the imput we are looking for is made of number we cant get ##:05 out of min = 5 so we need to have a conditinal that manually adds zeros to keep double digits
			if (min < 10)
			{
				o = "0";
			}
			
			//if over 12 reduce 12 from hours to get standard time
			if(hours > 12)
			{
					expected = std::to_string(hours-12) + ":" + o + std::to_string(min) + " "+ t;
			}
			
			//if not needed just follow through
			else
			{
			
				expected = std::to_string(hours) + ":" + o + std::to_string(min) + " "+ t;
			}
			
			
		}
		
		ClockTime(int hours, int min, int addMin)
		{
			//user input to check for AM, PM;
			//can change to bool fo rbetter data validation
			std::string t = "PM";
			std::string o = "";
			
			std::cout << hours <<":"<< min <<": is it Am or PM?\n";
			std::cin >> t;
			
			min += addMin;
			
			if(hours == 00)
			{
				hours = 12;
			}
			
			
			
			if(min >= 60)
			{
//				min -= 60;
				hours += (min/60);
				
				min = min % 60;
				
			}
			
			// beacuse the imput we are looking for is made of number we cant get ##:05 out of min = 5 so we need to have a conditinal that manually adds zeros to keep double digits
			if (min < 10)
			{
				o = "0";
			}
			
			//if over 12 reduce 12 from hours to get standard time
			if(hours > 12)
			{
					expected = std::to_string(hours-12) + ":" + o + std::to_string(min) + " "+ t;
			}
			
			//if not needed just follow through
			else
			{
			
				expected = std::to_string(hours) + ":" + o + std::to_string(min) + " "+ t;
			}
			
			
		}
	
	
	
	
	
	
};


void assertThat(ClockTime t, std::string expected);
int main()
{
	assertThat(ClockTime(11,15),"11:15 AM");
	assertThat(ClockTime(11,45),"11:45 AM");
	assertThat(ClockTime(13,30),"1:30 PM");
	assertThat(ClockTime(22,22),"10:22 PM");
	assertThat(ClockTime(9,00),"9:00 PM");
	assertThat(ClockTime(19,05),"7:05 PM");
	assertThat(ClockTime(23,59),"11:59 PM");
	assertThat(ClockTime(11,15,10),"11:25 AM");
	assertThat(ClockTime(11,45,30),"12:15 PM");
	assertThat(ClockTime(13,10,60),"2:10 PM");//
	assertThat(ClockTime(00,18,10),"12:28 AM");
	assertThat(ClockTime(11,59,1),"12:00 PM");//
	assertThat(ClockTime(23,59,1),"12:00 AM");
	assertThat(ClockTime(12,00,722),"12:02 AM");
	
	return 0;
}

void assertThat(ClockTime t, std::string expected)
{
	if(t.display() == expected)
		std::cout<<"\nTest Passed!";
		
	else
		std::cout<<"\nTest failed!";
}
