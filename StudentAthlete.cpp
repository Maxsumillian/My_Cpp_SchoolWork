//
// Created by maxy2 on 4/9/2026.
//

#include <iostream>
#include <vector>
#include "inputUtils.h"

class Student {
    friend std::ostream& operator<<(std::ostream& o, Student athlete);
    private:
        std::string firstName;
        std::string lastName;
        int grade;//(k-12)
        float totalFees;

    public:
        Student(std::string firstName, std::string lastName, int grade)
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

std::ostream& operator<<(std::ostream& o, Student student) {
    o << "Grade : " << student.grade << "| Name: " << student.firstName << " " << student.lastName << "| Total Fees: " << student.totalFees;
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
    o << "Sport : " << athlete.sport << "| Name: " << athlete.firstName << " " << athlete.lastName;
    return o;
};


// float Athlete::athleticFees = 125.5;// set the initial athletic fee this is a definition and isn't considered access


void displayMenu() {
    std::cout<<"\nPlease choose from the following menu";
    std::cout<<"\n1: Add student";
    std::cout<<"\n2: Print a list of enrolled students";
    std::cout<<"\n3: Print a list of students by last name";
    std::cout<<"\n4: Print a list of students who play sports";
    std::cout<<"\n5: Print a list of students by grade";
    std::cout<<"\n6: Print a list of students by sport";
    std::cout<<"\n7: Exit program";
}

void addStudent(std::vector<Student> students, std::vector<Athlete> athletes) {
    std::string firstName = getValidatedString("What is the first name : ");
    std::string lastName = getValidatedString("What is the last name : ");
    int grade = getValidatedInt("What is the grade : ");
    if (getValidatedBool("Does the student play Sports", "yes", "no")) {
        //if they play sports then ask for name of sport and add to athletic vector and altheic fee on a loop incase they play more than one sport

        while (true)
        {
            std::string sport = getValidatedString("What sport does the student play: ");

            // add sport to vector here
            // athleticSports.push_back(sport);
            // add fee

            if (!getValidatedBool("Does the student play any additional sports?", "yes", "no"))
            {
                //if doesnt play additinal sport break the loop
                break;
            }
        }

    }

    //add student to student vector

}














int main() {

    // //testing
    // Student max("Max","Yang",24), will("will","Yang",19);
    // //
    // std::cout<< max <<"\n"<< will;
    // // // std::cout<< will;
    // //
    // // if (max == will) {
    // //     std::cout<<"\nWill"<<std::endl;
    // // }
    // //
    // // std::cout<<(max == will);
    //
    // std::cout << "\n" << (max == "Yang");
    // std::cout << "\n" << (max == 20);
    //
    // // int testinput = getValidatedInt("Enter a Integer : ");
    //
    // // std::cout << testinput;


    std::vector<Student> students;
    std::vector<Athlete> athletes;

    int menuInput;
    while (menuInput != 7) {
        displayMenu();
        menuInput = getValidatedInt("\n : ");
        switch (menuInput) {
            case 1://adds student

                break;
            case 2://prints all enrolled students

                break;
            case 3://prints all students by last name

                break;
            case 4://prints all students who play sports

                break;
            case 5://prints all students by grade

                break;
            case 6://prints all students by sport

                break;
        }
    }

    std::cout<<"done";


};