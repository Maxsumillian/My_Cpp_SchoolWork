#include <iostream>

#include <cstring>

//comparingCharsStrings.cpp

int main()
{
		char a = 'A', b = 'B';
		
		// a != b, (a == b) = false = 0
		std::cout<<"\n"<<(a == b);
		
		// a = 1, b = 2, (a < b) = true = 1;
		std::cout<<"\n"<<(a < b);
		
		//true or 1 (67 < 97)
		std::cout<<"\n"<<(a < 'a');
		
		
		std::string s1 = "apple", s2 = "banana";
		
		std::cout<<"\n"<<(s1 > s2);// false or 0 because it compares the first letters first 'a' is less than 'b'
		
		std::cout<<"\n"<<(s1 > "apply");// false or 0 
		//			Lexicographically
		//				Alphabetical order!
		
		// you can compare strings but alot of apis wont allow for this
		std::cout<<"\n"<<(s1 == s2);// returns false
		std::cout<<"\n"<<(s1 != s2);// returns true
		
		
		std::string s3 = "max", s4 = "max";
		std::cout<<"\n"<<(s3 == s4);// returns true
		std::cout<<"\n"<<(s3 != s4);// returns false
		
		std::cout<<"\n"<<(s1.compare(s2) == 0);// returns true beacues s1.compare(s2) is false 
		std::cout<<"\n"<<(s1.compare(s2) > 0);// returns false // look into these next two
		std::cout<<"\n"<<(s1.compare(s2) < 0);// returns true // 
		
		
		char cs1[10] = "cherry"; // C-strings
		char cs2[10] = "cherry";
		
		std::cout<<"\n"<<(cs1 == cs2);//returns false because its comparing the address
		std::cout<<"\n"<<(*cs1 == *cs2);//returns true
		
		
		std::cout<<"\n"<<(strcmp(cs1,cs2) == 0);//needs #include <cString> returs true
		
		std::string one = "10";
		std::string two = "2";
		std::cout<<"\n"<<(one < two);// returns true because "10" is less than "2"
		
		std::string s5 = "app";
		
		std::cout<<"\n"<<(s1.substr(0,3) == s2);// retunr false beacuse "[app]le" != "bannana"
		
		std::cout<<"\n"<<(s1.substr(0,3) == s5);// returns true beacuse "[app]le" = "app" || app = app
		
		std::cout<<"\n"<<(s1.compare(0,3,s2) == 0);// compares part of the string returns false
		std::cout<<"\n"<<(s1.compare(0,3,s5) == 0);// compares part of the string returns true
		
		if (24 & 7)//checks if both end with zero prints true
			std::cout<<"\nTrue!"<<( 24 & 7);
		else
			std::cout<<"\nFalse!"<<( 24 & 7);
			
		//checks if both end with zero
		
		if (1 & 3)
			std::cout<<"\nTrue!"<<( 1 & 1);
		else
			std::cout<<"\nFalse!"<<( 3 & 3);
			
			
		if (23 & 3)
			std::cout<<"\nTrue!"<<( 1 & 1);
		else
			std::cout<<"\nFalse!"<<( 3 & 3);
			
			
		std::cout<<"\n"<<(24 & 0);// prints 0
		std::cout<<"\n"<<(24 | 1);// prints 25
		
		std::cout<<"\n"<<(24 & 16);// prints 16
		
		std::cout<<"\n"<<(25 | 25);// prints 25
		
		std::cout<<"\n"<<(24 & 10);// prints 8
		
		
		
		//(16 > 7 || 9 < 10)// ends process after reaching one true
		// 1 or 1 = true 
		
		//(16 > 7 | 9 < 10)//checks all of the statment
		// 1 or 1  =  ture 
		
		// read write execute nullpermission
		
			
			//testing my commits from school
};
