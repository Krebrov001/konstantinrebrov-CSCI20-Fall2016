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
    float totalPrice = 0.0; // the total price for all ordered items
    
    string displayMessage; // string to display the number of items
    
    // declare the prices for the items
    float prices[10] = { 2.99, 1.99, 3.50, 2.05, 5.99,
    0.50, 1.00, 1.00, 1.25, 1.50 };
    // declare the number of items in the inventory
    int inventory[10] = { 5, 6, 4, 7, 3, 12, 8, 10, 8, 5 };
    
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
            cout << " " << items[x] << ": ";
            printf("$%.2f", prices[x]);
            displayMessage = "Number of "; 
            displayMessage.append(items[x]); 
            displayMessage.append("s left: ");
            displayMessage.append(to_string(inventory[x]));
            printf("%32s", displayMessage.c_str());
            cout << endl;
        }
        cout << "> ";
        // input the user's choice
        cin >> userChoice;
        cout << endl;
        // compare the user's choice to valid options
        for (int x = 0; x < (sizeof(items)/sizeof(*items)); x++) {
            if (userChoice == items[x]) {
                status = 1;
                if (inventory[x] > 0) {
                    cout << "Your choice was " << userChoice << "." << endl;
                    // add the user's choice to the storage string
                    allChoices.append(userChoice);
                    allChoices.append(" ");
                    // add the total price
                    totalPrice += prices[x];
                    printf("Price: $%.2f\n", prices[x]);
                    // subtract 1 from the inventory;
                    inventory[x]--;
                }
                else {
                    cout << "No more " << items[x] << "s left." << endl;
                }
                break;
            }
            else if (userChoice == "q") {
                status = 2;
                cout << "No more orders." << endl;
                break;
            }
        }
        if (status == 0) {
            cout << "You did not enter one of the above items." << endl;
        }
        cout << endl;
        
    } while(status != 2);
    
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
    printf("The total cost is: $%.2f", totalPrice);
    
    return 0;
}