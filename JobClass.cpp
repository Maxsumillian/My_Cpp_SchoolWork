#include <iostream>


/*


 2 + 2 			'a' + 10
 2 + 2.5		"Hey" + "There"
 
 C++ can do things liek this	
















*/


class Job
{
	
	
	friend int operator+(int num, Job job);
//	friend int operator=(Job job, int num);
	friend 	std::ostream& operator<<(std::ostream& o, Job j);// needs oStream
	friend  std::istream& operator>>(std::istream& i, Job& j);// needs isStream
		
	private:
		int jobNum;
		int hours;
		float rate;
	public:
		Job(int jn,float h, float r)
		{
			jobNum = jn;
			hours = h;
			rate = r;
		}
		
		//this is cool able overide a operator funciton like this
		//allows jobs + ints
		int operator+(int num)
		{
			return hours + num;
		}
		
		float operator+(float num)
		{
			
			return rate += num;
		}
		
		void operator=(int num)
		{
			jobNum = num;
		}
		
		//assign the data
		void operator=(Job j)
		{
//			jobNum = j.jobNum;
			hours = j.hours;
			rate = j.rate;
		}


		bool operator>(Job j)
		{
			return ((hours*rate) > (j.hours*j.rate));
		}
		
		
		bool operator<(Job j)
		{
			return ((hours*rate) < (j.hours*j.rate));
		}
		
		//pre aka x++;
		// increments then prints cou<<++x; (only matters when in one line of code)
		operator++()
		{
			std::cout<<"\nPRE: ";
			this->rate++;
		}
		
		// post aka ++x;
		//increments after printing cout<<x++;
		// for post you use a dummy integer its how the (langauge was made)
		operator++(int x)
		{
			std::cout<<"\nPOST: ";
			this->rate++;
		}
		
		
//		Slower longer version
//		bool operator>(Job j)
//		{
//			bool thisJobisMore;
//			return ((hours*rate) > (j.hours*j.rate))
//				thisJobisMore = true;
//			else
//				thisJobisMore = false;
//				
//			return thisJobisMore;
//		}
		
		
		
//		int getHours(){return hours;}
		float getRate(){return rate;}
		float getJobNum(){return jobNum;}
		
};

//// cannot be overloadrd
//			::
//			.
//			?:
//			->


// need to make job here a refrence beacuse we dont want a temperary job we want the actaull job we are changing
std::istream& operator>>(std::istream& i, Job& j)
{
	 std::cout << "\nEnter job number: ";
    i >> j.jobNum;
    
    std::cout << "Enter hours: "; // Fixed prompt
    i >> j.hours;
    
    std::cout << "Enter rate: ";  // Fixed prompt
    i >> j.rate;
    
    return i;
	
}


std::ostream& operator<<(std::ostream& o, Job j)
{
	o<<j.jobNum<<" "<<j.hours<<" "<<j.rate;		
	return o;
}


// allows ints + jobs
int operator+(int num, Job job)
{
	
	return num + job.hours;//able to return and set values same time
};
























int main()
{
	
	
	
	Job jobA(111,10,10.50);
	Job jobB(222,20,20.50);
	Job jobC(0,0,0);

	std::cout<<"\n"<<jobA + 5;// works beacuse of hte int operator+ overide funciton
	
	std::cout<<"\n"<<jobA.operator+(5);
//	std::cout<<"\n"<<jobA + 5.25;
	std::cout<<"\n"<<jobA + 5.25F;
	
	std::cout<<"\n"<<jobA.getRate();
	
//	std::cout<<"\n"<<jobB + (jobA + 10);// this works because the ints are all to to the rigth wuht otu overirde operator funcitons
	
	std::cout<<"\n"<<jobB + 10 + jobA;
	
	jobC = 333;
//	jobC = jobA;// it uses copy constructor if not overridden 

	jobC = jobA;

	std::cout<<"\n"<<jobC.getJobNum();
	std::cout<<"\n"<<jobC.getRate();
	
	if(jobA > jobB)
		std::cout<<"\nJob A cost more!";
	else
		std::cout<<"\nJob B cost more!";
			
	
	std::cout<<"\n"<<jobA;
	
	std::cin>>jobA;
	std::cout<<jobA;
	++jobA;
	std::cout<<jobA;
	jobA++;
	std::cout<<jobA;
	
//	std::cout<<"\n"<<jobB + 10 + jobA.getHours();
	
//	std::cout<<"\n"<<jobB + 5;

//	std::cout<< 2 + 2.5; //prints 4.5
	
//	std::cout<< 2 + "2.5"; //prints 5
	
//	std::cout<< "2" + 2.5; // syntax error

	
};
