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