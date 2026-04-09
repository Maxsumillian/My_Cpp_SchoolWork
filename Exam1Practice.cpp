#include <iostream>//this stands for input output stream
#include <vector>

// Exam Practice 1








// std::cout<<obj1;
// cout is a object from a ostream class



class Student {

	
	private:
		int studentID;
		int creditHours;
		std::string track;
		std::string timing;
		bool online;
	
	public:
		Student(int studentID, int creditHours, std::string track, std::string timing, bool online)
			:studentID(studentID), creditHours(creditHours), track(track), timing(timing), online(online)//initialaztion list
			{}
				
		int getStudentID()		{	return studentID;		}
		int getCreditHours()	{	return creditHours;	}
		std::string getTrack()	{	return track;		}
		std::string getTiming()	{	return timing;		}// admitted "early" "ontime" or "late"
		bool getOnline()		{	return online;		}
		
		
		void setStudentID(int studentID)
		{
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
		
		std::string display()
		{
			return "Student ID#: " + studentID;
		}
			
};

class Charge{
	
	friend std::ostream& operator<<(std::ostream&, Charge oneCharge);
//	friend Charge operator+(Charge c, Charge i);
	
	private:
		std::string label;
		double amount;
		
		
	public:
		Charge(std::string label, double amount)
		:label(label), amount(amount)
		{}
				
		//accsessor 
		std::string getLabel()	{	return label;	}
		double getCharge()	{	return amount;	}
		
		//mutators
		void setLabel(std::string label){
			this->label = label;
		}
		void setLabel(double label){
			this->label = label;
		}
		
		//overloaded operators | [Charge] - (float) returns [amount * discountPercentage *-1]
		float operator-(float discountPercentage){
			return amount * discountPercentage *-1;
		}
		
		float operator+(float discountPercentage){
			return amount * discountPercentage;
		}
	
		//returning a Charge class inside the class
		Charge operator*(int credits){
			
			return Charge("Base Tuition", this->amount*credits);
			
		}
		
};

//Charge operator+(Charge c, Charge i)
//{
//	return Charge(c.label + i.label, c.amount + i.amount );
//}

std::ostream& operator<<(std::ostream& o, Charge oneCharge)
{
	o<<oneCharge.label<<" \t $ "<<oneCharge.amount;	
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
			//we create a Charge class called perCredit that is equal to the function "chargePerCredit" that returns a Charge
			// that needs a student track to make its Charge tbased on the track and we get the student track from the student inn this invoice class that is needed for initialization o finvoice
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
		
		void display()
			{
				student.display();
				
				for (Charge oneCharge : allCharges)
					std::cout<<oneCharge;
					
				//conditinal operator/tertinary operator [condition]?[true]:[false];
				std::cout<<( totalAmountDue > 9000.00 ? std::cout<<"Please contact the register": 
											   std::cout<<"Your semester bill is $"<< totalAmountDue);
				
			}
	
};


//static int +++(int a)
//{
//	return a + 1 + 1 + 1;
//}



//===========================================================================================================
//refrenceses change the actual value likea  pointer so it sgood to change multiple values
void inputData(int& credits, int& studentID)
{
	//input with data validation	
}

bool inputOnline()
{
	// no need to validate but ask yes or no
	//return (answer == "yes");
}
//===========================================================================================================

int main(){
	
	//int a = 1;
//	a++;
	
//	Charge newCharge("payment", 10);
//	
//	float discountPercent = .10;
//	
//	std::cout<<"\n"<<newCharge-discountPercent;//retunrs 100 beacuse 10*10 is 100
//	std::cout<<"\n"<<newCharge+discountPercent;
//	
//	Charge newCharge2 = newCharge*10;
//	std::cout<<"\n"<<newCharge2.getCharge();
//	
//	newCharge2 = newCharge2*10;
//	std::cout<<"\n"<<newCharge2;
//	newCharge2 = newCharge2*10;
//	std::cout<<"\n"<<newCharge2;
//	newCharge2 = newCharge2*10;
//	std::cout<<"\n"<<newCharge2;

//	call inputData();
//	ask for string data for track and timing usign a getline();

//	call allOnline(); to get if its online

//	 create invoice
//	Invoice newInvoice(StrudentID,CreditHours,track,online);

//	newInvoice.compute();
//	newInvoice.display();
	
	return 0;
}
