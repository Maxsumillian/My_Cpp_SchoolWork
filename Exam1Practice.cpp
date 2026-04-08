#include <iostream>

// Exam Practice 1

class Student {

	
	private:
		int studentID;
		int creditHours;
		std::string track;
		std::string timing;
		bool online;
	
	public:
		Student(int studentID, int creditHours, std::string track, std::string timing, bool online)
			:studentID(studentID), creditHours(creditHours), track(track), timing(timing), online(online)
			{}
				
		int getStudentID()		{	return studentID;		}
		int getCreditHours()	{	return creditHours;	}
		std::string getTrack()	{	return track;		}
		std::string getTiming()	{	return timing;		}
		bool getOnline()		{	return online;		}
		
		
		void setStudentID(int studentID){
			this->studentID = studentID;
		}
		void setCreditHours(int creditHours){
			this->creditHours = creditHours;
		}
		void setTrack(std::string track){
			this->track = track;
		}
		void setTiming(std::string timing){
			this->timing = timing;
		}
		void setOnline	(bool online){
			this->online = online;
		}	
			
		
				
};




class Charge{
	
	friend std::ostream& operator<<(std::ostream&, Charge oneCharge);
	
	private:
		std::string label;
		double charge;
		
		
	public:
		Charge(std::string label, double charge)
		:label(label), charge(charge)
		{}
		

		std::string getLabel()	{	return label;	}
		double getCharge()	{	return charge;	}
		
		
		void setLabel(std::string label){
			this->label = label;
		}
		void setLabel(double label){
			this->label = label;
		}
		
	
		float operator-(float discountPercentage){
			return charge * discountPercentage;
		}
		
		float operator+(float discountPercentage){
			return charge * discountPercentage;
		}
	
		//returning a charge class inside the class
		Charge operator*(int credits){
			
			Charge oneCharge("Base Tuition", this->charge*credits);
			
			return oneCharge;
			
		}
	
};

std::ostream& operator<<(std::ostream& o, Charge oneCharge)
{
	o<<oneCharge.label<<" \t $ "<<oneCharge.charge;	
}






int main(){
	
	Charge newCharge("payment", 10);
	
	float discountPercent = .10;
	
	std::cout<<"\n"<<newCharge-discountPercent;//retunrs 100 beacuse 10*10 is 100
	std::cout<<"\n"<<newCharge+discountPercent;
	
	Charge newCharge2 = newCharge*(10);
	std::cout<<"\n"<<newCharge2.getCharge();
	
	return 0;
}
