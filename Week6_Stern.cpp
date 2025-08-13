#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <iomanip>
#include <numeric>
#include <limits>
using namespace std;

int main()
{
    std::ifstream file( "TextInput.txt" );
    std::string line;
    std::vector<double> GPAvec;
    std::vector<string> firstNamevec;
    std::vector<string> lastNamevec;
    double GPA;
    string firstName;
    string lastName;
    
// Reads in values from file
    while (std::getline(file, line)){
        std::stringstream ss(line);
        ss >> GPA;
        GPAvec.push_back(GPA);
        ss >> firstName;
        firstNamevec.push_back(firstName);
        ss >> lastName;
        lastNamevec.push_back(lastName);
    }

// Prints header of student list
std::cout << "First Name   " 
    << "|   Last Name   " 
    << "|   GPA" 
    << endl;
std::cout << "------------------------------------------"      << endl;

// Prints each list
    for (size_t i = 0; i < GPAvec.size(); ++i) {
        cout << std::setw(10) 
        << std::left
        << firstNamevec[i] 
        << "   |   "
        << std::setw(10) 
        << std::left
        << lastNamevec[i] 
        << "  |   "
        << std::fixed
        << std::setprecision(1)
        << GPAvec[i]
        << endl;
    }
std::cout << "------------------------------------------" << endl;

// Print total number of students
std::cout << "Total number of students: " 
    << GPAvec.size() << endl;

// Find average of GPA for students
double sum = std::accumulate(GPAvec.begin(), GPAvec.end(), 0.0); 
// Print out average
std::cout << "Average GPA: " 
    << std::setprecision(2) 
    << std::fixed 
    << sum / GPAvec.size();

// Close file
    file.close();    

    return 0;
}
