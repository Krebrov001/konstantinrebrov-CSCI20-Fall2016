/* Name: Konstantin Rebrov
 * Date: 11/3/2016
 * This program allows the user
 * to enter his or her first and last name
 * and generates three possible usernames.
 */
#include <iostream>
#include <string>
using namespace std;

int main() {
    
    string userInput; // for the input
    string firstName = "";
    string lastName = "";
    
    // all possible usernames
    string userName1 = "";
    string userName2 = "";
    string userName3 = "";
    
    // input gets saved to the userInput c++ string every time
    cout << "Enter your first name." << endl;
    cin >> userInput;
    
    // check if a string is larger than the max size
    // and trim it down to the max size
    if (userInput.length() > 10) {
        cout << "Your name is larger than the max size." << endl;
        cout << "Trimming string..." << endl;
        firstName.assign(userInput, 0, 10);
    }
    else {
        firstName = userInput;
    }
    // converts the string to lower case
    for (int x = 0; x < firstName.length(); x++) {
        firstName.at(x) = tolower(firstName.at(x));
    }
    
    cout << "Enter your last name." << endl;
    cin >> userInput;
    
    if (userInput.length() > 20) {
        cout << "Your name is larger than the max size." << endl;
        cout << "Trimming string..." << endl;
        lastName.assign(userInput, 0, 20);
    }
    else {
        lastName = userInput;
    }
    for (int x = 0; x < lastName.length(); x++) {
        lastName.at(x) = tolower(lastName.at(x));
    }
    
    if (firstName == lastName) {
        cout << "Both names are the same." << endl;
    }
    
    /* create the three possible usernames and print them out */
    userName1 = userName1.assign(firstName, 0, 2) + lastName;
    
    userName2 = firstName + lastName;
    
    userName3 = firstName.at(0) + lastName;
    
    cout << "Which of the three user names would you like:" << endl;
    cout << " - " << userName1 << endl;
    cout << " - " << userName2 << endl;
    cout << " - " << userName3 << endl;
    
    return 0;
}