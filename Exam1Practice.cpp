#include <iostream>
#include <vector>

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
		std::string getTiming()	{	return timing;		}// admitted early ontime or late
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
			return charge * discountPercentage *-1;
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
	return o; //dont forget to return o beacuse even if we are using a refrence this funciton is missign a return type and can break unless we tunr it into a void function
}


class Invoice{
	private:
		Student student;
		std::vector<Charge> allCharges;
		double totalAmountDue;
		
	public:
		Invoice(int studentID, int creditHours, std::string track, std::string timing, bool online)
			:student(studentID, creditHours, track, timing, online)
			{
				this->totalAmountDue = 0;
			}
			
		Charge chargePerCredit(std::string track)
		{
			//Charge oneCharge();
			
			if(track == "general certification")
				return 	Charge("general certification", 180);//creates and returns a charge object 
				
			if(track == "undergraduate")
				return 	Charge("undergraduate per credit", 320);
				
			if(track == "graduate")
				return 	Charge("graduate per credit", 450);
				
			if(track == "professional")
				return 	Charge("professional per credit", 650);
			
			return Charge("invalide track",0);
		}
		
		//creats charges from student track and adds to allcharges vecotor
		void compute(){
			
			Charge perCredit = chargePerCredit(student.getTrack());
			
			allCharges.push_back(perCredit);
			
//			allCharges.push_back(chargePerCredit(student.getTrack());
			
			
			Charge baseTuition = perCredit * student.getCreditHours();
			allCharges.push_back(baseTuition);
			
			if(student.getTiming() == "early")
			{
				Charge early("Early registartion discount", baseTuition-.5);
				allCharges.push_back(early);
				
			} else if (student.getTiming() == "late")
			{
				Charge late("Early registartion discount", baseTuition+.12);
				allCharges.push_back(late);
			}
			
			for (int x = 1; x < allCharges.size(); x++)
				totalAmountDue += allCharges[x].getCharge();
			
			//shoulnt use a range-based loop beacause we need to start at one
//			for(Charge oneCharge : allChanges)
//				total += oneCharge.getAmount();

			if (student.getOnline())
			{
				double discount = totalAmountDue * .15;
				
				Charge onlineDiscount("Online discount", discount);
				allCharges.push_back(onlineDiscount);
				totalAmountDue -= discount;
			}
			
		}
};



int main(){
	
	Charge newCharge("payment", 10);
	
	float discountPercent = .10;
	
	std::cout<<"\n"<<newCharge-discountPercent;//retunrs 100 beacuse 10*10 is 100
	std::cout<<"\n"<<newCharge+discountPercent;
	
	Charge newCharge2 = newCharge*10;
	std::cout<<"\n"<<newCharge2.getCharge();
	
	newCharge2 = newCharge2*10;
	std::cout<<"\n"<<newCharge2;
	newCharge2 = newCharge2*10;
	std::cout<<"\n"<<newCharge2;
	newCharge2 = newCharge2*10;
	std::cout<<"\n"<<newCharge2;
	
	return 0;
}
