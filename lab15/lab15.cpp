/* Name: Konstantin Rebrov
 * Date: 10/25/2016
 * This program uses one array to store the menu items.
 * The user is given a choice to order one of these items
 * at a time or quit the ordering process.
 * If the user enters something else, an error message
 * and a prompt for ordering again will appear.
 * The orders get saved to a string.
 * After the ordering process is quit,
 * the string is parsed to an array.
 * Then the program prints out all the ordered items
 * that are stored in the array.
 */
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
    // menu items for ordering
    string items[10] = { "cheese", "milk", "bread", "broccoli", "pumpkin",
    "apple", "turnip", "sunchoke", "parsley", "parsnip" };
    string userChoice; // the current choice
    string allChoices = ""; // all of the user's choices
    
    int status; // trinary code status, boolean won't work
    /* 0 means user choice is empty
     * 1 means user choice is successful
     * 2 means quit the ordering process
     */
     
     // ordering process
    do {
        status = 0;
        // Tell the user the ordering choices
        cout << "Please choose one of the following items: ";
        cout << "(or q to quit)" << endl;
        for (int x = 0; x < (sizeof(items)/sizeof(*items)); x++) {
            cout << items[x] << " ";
        }
        cout << endl;
        // input the user's choice
        cin >> userChoice;
        // compare the user's choice to valid options
        for (int x = 0; x <(sizeof(items)/sizeof(*items)); x++) {
            if (userChoice == items[x]) {
                status = 1;
                break;
            }
            else if (userChoice == "q") {
                status = 2;
                break;
            }
        }
        // print a message based on the status
        if (status == 1) { 
            cout << endl << "Your choice was " << userChoice << "." << endl;
            // add the user's choice to the storage string
            allChoices.append(userChoice);
            allChoices.append(" ");
        }
        else if (status == 2) {
            cout << "No more orders." << endl;
        }
        else {
            cout << "You did not enter one of the above items." << endl;
            cout << endl;
        }
    } while(status != 2);
    cout << endl;
    
    // counts the number of ordered items
    int numChoices = 0;
    for (int x = 0; x < allChoices.length(); x++) {
        if (allChoices[x] == ' ') {
            numChoices++;
        }
    }
    // This code splits the storage string into an array.
    // http://stackoverflow.com/a/16029565
    string choicesList[numChoices];
    int i = 0;
    stringstream ssin(allChoices);
    while (ssin.good() && i < numChoices) {
        ssin >> choicesList[i];
        ++i;
    }
    
    // Print out all the ordered items from the array.
    cout << "You ordered the following itmes: ";
    for (int x = 0; x < (sizeof(choicesList)/sizeof(*choicesList)); x++) {
        cout << choicesList[x] << " ";
    }
    cout << endl;
    
    return 0;
}