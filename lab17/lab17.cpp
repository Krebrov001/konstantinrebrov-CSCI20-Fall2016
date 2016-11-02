/* Name: Konstantin Rebrov
 * Date: 11/2/2016
 * This program allows the user
 * to enter his or her first and last name
 * and generates three possible usernames.
 */
#include <iostream>
#include <string.h>
using namespace std;

int main() {
    
    char userInput[21]; // for the input
    char firstName[11] = "";
    char lastName[21] = "";
    
    int sameNames = 0; // counter to check if each char is the same
    
    // all possible usernames
    char userName1[23] = "";
    char userName2[31] = "";
    char userName3[22] = "";
    
    // input gets saved to the userInput c string every time
    cout << "Enter your first name." << endl;
    cin >> userInput;
    
    // check if a string is larger than the max size
    // and trim it down to the max size
    if (strlen(userInput) > 10) {
        cout << "Your name is larger than the max size." << endl;
        cout << "Trimming string..." << endl;
        strncat(firstName, userInput, 10);
    }
    else {
        strcpy(firstName, userInput);
    }
    // converts the string to lower case
    for ( int x = 0; x < strlen(firstName); x++) {
        firstName[x] = (char) tolower(firstName[x]);
    }
    
    cout << "Enter your last name." << endl;
    cin >> userInput;
    
    if (strlen(userInput) > 20) {
        cout << "Your name is larger than the max size." << endl;
        cout << "Trimming string..." << endl;
        strncat(lastName, userInput, 20);
    }
    else {
        strcpy(lastName, userInput);
    }
    for (int x = 0; x < strlen(lastName); x++) {
        lastName[x] = (char) tolower(lastName[x]);
    }
    
    // my own unique way of how to caompare if two c strings are the same
    if (strlen(firstName) == strlen(lastName)) {
        for (int x = 0; x < strlen(firstName); x++) {
            if (firstName[x] == lastName[x]) {
                sameNames++; // every same char adds to the counter
            }
        }
    }
    if (sameNames == strlen(firstName)) {
        cout << "Both names are the same." << endl;
    }
    
    /* create the three possible usernames and print them out */
    strncpy(userName1, firstName, 2);
    strcat(userName1, lastName);
    
    strcpy(userName2, firstName);
    strcat(userName2, lastName);
    
    strncpy(userName3, firstName, 1);
    strcat(userName3, lastName);
    
    cout << "Which of the three user names would you like:" << endl;
    cout << " - " << userName1 << endl;
    cout << " - " << userName2 << endl;
    cout << " - " << userName3 << endl;
    
    return 0;
}