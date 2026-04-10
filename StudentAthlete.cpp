//
// Created by maxy2 on 4/9/2026.
//

#include <iostream>

class StudentAthlete {
    friend std::ostream& operator<<(std::ostream& o, StudentAthlete athlete);
    private:
        std::string firstName;
        std::string lastName;
        int grade;//(k-12)
        float totalFees;

    public:
        StudentAthlete(std::string firstName, std::string lastName, int grade)
            :firstName(firstName), lastName(lastName), grade(grade) {
            totalFees = 0;
        }

        float operator+=(float additinalFee) {
            return totalFees += additinalFee;
        }

        bool operator==(std::string lastName) {
            // return this->lastName.compare(lastName) == 0; // this works too Basically compare checks to see if they are diffrences if there are no diffrences it returns 0
            return this->lastName == lastName;
        }

        bool operator==(int grade) {
            return this->grade == grade;
        }


};

std::ostream& operator<<(std::ostream& o, StudentAthlete athlete) {
    o<<"Grade : "<<athlete.grade<<"| Name: "<<athlete.firstName<<" "<<athlete.lastName<<"| Total Fees: "<<athlete.totalFees;
    return o;
};


class Athlete {
    friend std::ostream& operator<<(std::ostream& o, Athlete athlete);
    private:
        std::string firstName;
        std::string lastName;
        std::string sport;
        // static float athleticFees;// we made this static because it belongs to this class not each instance of the class so changing this changes all of them for all instances of this class
        static inline float athleticFees = 125.5;// you can use "inline" cleaner version to set the initial value

    public:
        Athlete(std::string firstName, std::string lastName, std::string sport)
            :firstName(firstName), lastName(lastName), sport(sport) {}

        bool operator==(std::string sport) {
                return this->sport == sport;
        }
};

std::ostream& operator<<(std::ostream& o, Athlete athlete) {
    o<<"Sport : "<<athlete.sport<<"| Name: "<<athlete.firstName<<" "<<athlete.lastName;
    return o;
};


// float Athlete::athleticFees = 125.5;// set the initial athletic fee this is a definition and isn't considered access

















int main() {

    //testing
    StudentAthlete max("Max","Yang",24), will("will","Yang",19);
    //
    std::cout<< max <<"\n"<< will;
    // // std::cout<< will;
    //
    // if (max == will) {
    //     std::cout<<"\nWill"<<std::endl;
    // }
    //
    // std::cout<<(max == will);

    std::cout << "\n" << (max == "Yang");
    std::cout << "\n" << (max == 20);



};