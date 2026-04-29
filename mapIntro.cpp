#include <iostream>
#include <map>

int main(){
	//for a mapwe use a key and value
//	std::map<std::string,int> mapOfSpace;
//	mapOfSpace.insert(std::make_pair("earth",100));
//	mapOfSpace.insert(std::make_pair("moon",200));
//	
//	mapOfSpace["sun"]=300;	
//	mapOfSpace["earth"]=400;
//	
//	if(mapOfSpace.insert(std::make_pair("earth",500)).second == false)
//	{
//		std::cout<<"\nmarth already exist!";
//	}
//	
//	//creates mars if mars doesnt exist
//	if(mapOfSpace.insert(std::make_pair("mars",500)).second == false)
//	{
//		std::cout<<"\nmars already exist!";
//	}
//	
//	
//	std::map<std::string,int>::iterator it = mapOfSpace.begin();
//	while (it != mapOfSpace.end())
//	{
//		std::cout << "\n" << it->first << ":" << it->second;
//		it++;
//	}
//	
//	if (mapOfSpace.find("sun") != mapOfSpace.end())
//		std::cout<<"\nFound sun!";
//		
//	if (mapOfSpace.find("earth2") != mapOfSpace.end())
//		std::cout<<"\nFound: earth2!";
//	else
//		std::cout<<"\nNOT Found: earth2!";
//		
//		
//		
//	it = mapOfSpace.find("sun");
//	std::cout << "\nFound: " << it->first << " and " << it->second;
//		
	
	
	
//=========================================================================================

	
	std::map<int, std::string> music{
		{3, "Abba"}, {1, "Journey"},
		{2,"Katseye"}
		};// maps sort and organize by key values
	
	std::cout<<"\n"<<music.at(1);
	std::cout<<"\n"<<music[1];//index also works
	music.at(1)="One Direction";// this changes the value
	music[4]= "Queen";// index cna create the variable at location
	
	try{
		music.at(5) = "BTS";// finds the spot then if it does it adds it
	} catch(std::exception& e)
	{
		std::cout<<"\n\033[31mError! adding BTS\033[0m";
	}
	
	
	
	
	std::cout<<"\n"<<music.at(1);
	
	std::map<int,std::string>::iterator itr = music.begin();
	while (itr != music.end())
	{
		std::cout << "\n" << itr->first << ":" << itr->second;
		itr++;
	}
	
	
	std::map<int,std::string>::iterator itr2 = music.end();
		while (itr2 != music.begin())
		{
			itr2--;//end contains garbage data so we need to decrement first
			std::cout << "\n" << itr2->first << ":" << itr2->second;
	}
		
		
}
