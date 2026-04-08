#include <iostream>

// Exam Practice 1

class student {
	private:
		int studentID;
		int creditHours;
		std::string track;
		std::string timing;
		bool online;
	
	public:
		student(int studentID, int creditHours, std::string track, std::string timing, bool online)
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

int main(){
	
	return 0;
}
