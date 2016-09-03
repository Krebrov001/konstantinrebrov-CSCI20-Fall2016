/* Name: Konstantin Rebrov
 * Date: 9/2/2016
 * Class: CSCI-20
 * Instructor: April Browne
 */
 
#include <iostream>
#include <string>
#include <time.h> // needed for wait function
using namespace std;

/* This function causes the program
 * to wait for some amount of time.
 * https://ubuntuforums.org/showthread.php?t=1357606
 */
void wait ( int seconds ) 
{ 
  clock_t endwait; 
  endwait = clock () + seconds * CLOCKS_PER_SEC ; 
  while (clock() < endwait) {} 
} 

int main() {
    
    string inputData;
    int centsAmount;
    int qtrsAmount;
    int dimesAmount;
    int niklsAmount;
    int penysAmount;
    int noQtrs;
    int noDimes;
    
    string welcomeMessage = "Welcome!\n";
    cout << welcomeMessage << endl;
    
    int numTries = 0;
    while (true) {
    
        if (numTries >= 3) {
            wait (1);
            
            cout << endl;
            cout << "You have exceeded the maximum number of tries." << endl;
            cout << "This machine is locked because we detected " <<
            "potentially suspicious activity." << endl;
            return 0;
        }
        else {
            cout << "Enter a monetery amount in ¢ (cents)." << endl;
            cin >> inputData;
        }
        
        /* This if statement checks
         * if the string in inputData
         * is an integer value.
         * http://stackoverflow.com/a/27149160
         */
        if (atoi(inputData.c_str())>0 || isdigit(inputData.c_str()[0]) ) {
            break;
        }
        else {
            cout << "You have not entered a valid amount in ¢ (cents).";
            cout << endl << "Please try again.\n" << endl;
            numTries++;
        }
    
    }
    
    /* Convert the string inputData
     * into an int value.
     * http://stackoverflow.com/questions/7663709/convert-string-to-int-c
     */
    centsAmount = atoi(inputData.c_str());
    cout << endl << "You have input " << centsAmount << "¢ into the " <<
    "machine." << endl;
    
    wait (2); // wait function, see above
    
    noQtrs = centsAmount % 25;
    qtrsAmount = (centsAmount - noQtrs) / 25;
    cout << "There are " << qtrsAmount << " quarters." << endl;
     
    wait (1);
    noDimes = noQtrs % 10;
    dimesAmount = (noQtrs - noDimes) / 10;
    cout << "There are " << dimesAmount << " dimes." << endl;
    
    wait (1);
    niklsAmount = (noDimes - (noDimes % 5)) / 5;
    cout << "There are " << niklsAmount << " nickels." << endl;
    
    wait (1);
    penysAmount = (noDimes % 5) / 1;
    cout << "There are " << penysAmount << " pennies." << endl;
    
    wait (2);
    
    /* This chunk of code calculates
     * the total amount of money.
     * A CointStar machine cannot
     * read your mind.
     */
    int moneySum = qtrsAmount * 25 + dimesAmount * 10;
    moneySum = moneySum + niklsAmount * 5 + penysAmount * 1;
    float moneyTotal = (float) (moneySum / 100.0);
    cout << endl << endl;
    printf("The total amount of money is $%.2f.\n", moneyTotal);
    
    wait (1);
    cout << endl;
    float feePercent = 0.109;
    float moneyGet = moneyTotal - moneyTotal * feePercent;
    printf("The redeeming fee is $%.2f.\n", (moneyTotal * feePercent));
    printf("\nYou get $%.2f in return.\n", moneyGet);
    
    wait (2);
    int moneyLost = (int) moneyGet;
    moneyGet = (float) moneyLost;
    cout << endl;
    cout << "There has been a problem with returning your change." << endl;
    printf("You get $%.2f.\n", moneyGet);
    wait (1);
    cout << endl << "Here is your money." << endl;
    cout << "Have a nice day!" << endl;
    
    return 0;
}