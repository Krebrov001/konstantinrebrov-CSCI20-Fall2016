/* Name: Konstantin Rebrov
 * Date: 10/7/2016
 * This program recreates the
 * animals flowchart using
 * two types of control structures.
 */
#include <iostream>
#include <string>
using namespace std;

/* Function declarations are for organization.
 * Both functions do the same thing.
 * Accepted inputs include:
 * yes, Yes, YES
 * no, No, NO
 */
void NestedIf();

void SwitchStatements();

int main() {
    cout << "Running the program..." << endl;
    cout << endl;
    
    cout << "Testing the nested if statements." << endl;
    cout << endl;
    NestedIf();
    
    cout << endl;
    cout << "Testing the switch statements." << endl;
    cout << endl;
    SwitchStatements();
    
    return 0;
}

/* This function accepts string inputs
 * and uses if statements to determine
 * if the strings are equal.
 */
void NestedIf() {
    string input;
    
    cout << "What animal are you?" << endl;
    
    cout << "Do you like the outdoors?" << endl;
    cin >> input;
    
    if (input == "yes" || input == "Yes" || input == "YES") {
        cout << "Do you like to run?" << endl;
        cin >> input;
        
        if (input == "yes" || input == "Yes" || input == "YES") {
            cout << "You are a horse!" << endl;
        }
        else if (input == "no" || input == "No" || input == "NO") {
            cout << "You are a turtle!" << endl;
        }
    }
    else if (input == "no" || input == "No" || input == "NO") {
        cout << "Do you like cheese?" << endl;
        cin >> input;
        
        if (input == "yes" || input == "Yes" || input == "YES") {
            cout << "You are a mouse!" << endl;
        }
        else if (input == "no" || input == "No" || input == "NO") {
            cout << "Do you like to swim?" << endl;
            cin >> input;
            
            if (input == "yes" || input == "Yes" || input == "YES") {
                cout << "You are a fish!" << endl;
            }
            else if (input == "no" || input == "No" || input == "NO") {
                cout << "You are a cat!" << endl;
            }
        }
    }
    
    return;
}

/* This function accepts string inputs
 * and performs a switch on the first
 * char of the string to determine if
 * the chars are equal.
 * y, Y, n, and N would technically work
 * as inputs but it is reccomended to
 * use the full strings as inputs.
 */
void SwitchStatements() {
    string input;
    
    cout << "What animal are you?" << endl;
    
    cout << "Do you like the outdoors?" << endl;
    cin >> input;
    char a = input[0];
    
    switch (a) {
        case 'y':
        case 'Y':
            cout << "Do you like to run?" << endl;
            cin >> input;
            a = input[0];
            
            switch (a) {
                case 'y':
                case 'Y':
                    cout << "You are a horse!" << endl;
                    break;
                case 'n':
                case 'N':
                    cout << "You are a turtle!" << endl;
                    break;
            }
            
            break;
        case 'n':
        case 'N':
            cout << "Do you like cheese?" << endl;
            cin >> input;
            a = input[0];
            
            switch (a) {
                case 'y':
                case 'Y':
                    cout << "You are a mouse!" << endl;
                    break;
                case 'n':
                case 'N':
                    cout << "Do you like to swim?" << endl;
                    cin >> input;
                    a = input[0];
                    
                    switch (a) {
                        case 'y':
                        case 'Y':
                            cout << "You are a fish!" << endl;
                            break;
                        case 'n':
                        case 'N':
                            cout << "You are a cat!" << endl;
                            break;
                    }
                    
                    break;
            }
            
            break;
    }
    
    return;
}