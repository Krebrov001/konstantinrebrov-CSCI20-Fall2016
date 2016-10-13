/* Name: Konstantin Rebrov
 * Date: 10/12/2016
 * This program prints out
 * every minute between 1:00 pm and 2:59 pm
 * every 15 minute interval between two times
 * that are input by the user.
 */
#include <iostream>
#include <time.h>
#include <string>
using namespace std;

// function declarations improve the readability of the program
void wait(int seconds);

int timeReturn(string timeString);

int main() {
    int hours;
    int minutes;
    string timeminutes;
    
    for (int totminutes = 60; totminutes < 180; totminutes++) {
        // wait(60); // UNCOMMENT
        hours = totminutes / 60;
        minutes = totminutes % 60;
        timeminutes = to_string(minutes);
        timeminutes = (minutes < 10) ? "0" + timeminutes : timeminutes;
        cout << hours << ":" << timeminutes << " pm" << endl;
        cout << endl;
    }
    
    string startHour;
    string endHour;
    int firstHour;
    int secondHour;
    int quarterHour = 0;
    string displayTime;
    
    cout << endl;
    cout << "Enter the start hour." << endl;
    getline(cin, startHour);
    cout << "Enter the end hour." << endl;
    getline(cin, endHour);
    cout << endl;
    cout << endl;
    
    firstHour = timeReturn(startHour);
    secondHour = timeReturn(endHour);
    
    for (firstHour = firstHour; firstHour < secondHour; firstHour++) {
        
        for (int quarterHour = 0; quarterHour < 4; quarterHour++) {
            
            if (firstHour < 10) {
                displayTime = "0" + to_string(firstHour) + ":";
            }
            else if (firstHour < 13) {
                displayTime = to_string(firstHour) + ":";
            }
            else if (firstHour < 22) {
                displayTime = "0" + to_string(firstHour - 12) + ":";
            }
             else {
                displayTime = to_string(firstHour - 12) + ":";
            }
        
            displayTime = displayTime + to_string(quarterHour * 15);
            if (displayTime.length() == 4) {
                displayTime = displayTime + "0";
            }
        
            if (firstHour < 12) {
                displayTime = displayTime + " am";
            }
            else {
                displayTime = displayTime + " pm";
            }
        
            cout << displayTime << endl;
            cout << endl;
        
            // wait(60 * 15); // UNCOMMENT
        }
        
    }
    
    return 0;
}

/* The wait function makes the computer wait
 * for the number of seconds that is defined in the argument.
 * To use it for real time in the program,
 * Remove the // before the function calls in the main method
 * that are labeled UNCOMMENT.
 */
void wait(int seconds)
{ 
  clock_t endwait; 
  endwait = clock() + seconds * CLOCKS_PER_SEC ; 
  while (clock() < endwait) {} 
} 

/* This function accepts a string argument of the following formats
 * 1, 10, 14, 8:00, 15:00, 6:00 am, 9:00 AM, 5:00 pm, 10:00 PM
 * and converts it to an int of the following formats
 * 2, 10, 12, 17, 24
 */
int timeReturn(string timeString) {
    int stringLength = timeString.length();
    int timeHour;
    switch (stringLength) {
        case 1:
            timeHour = timeString.at(0) - '0';
            break;
        case 2:
            timeHour = (timeString.at(0) - '0') * 10;
            timeHour += timeString.at(1) - '0';
            break;
        case 4:
            timeHour = timeString.at(0) - '0';
            break;
        case 5:
            timeHour = (timeString.at(0) - '0') * 10;
            timeHour += timeString.at(1) - '0';
            break;
        case 7:
            if (timeString.at(5) == 'a' || timeString.at(6) == 'A') {
                timeHour = timeString.at(0) - '0';
            }
            else if (timeString.at(5) == 'p' || timeString.at(5) == 'P') {
                timeHour = (timeString.at(0) -'0') + 12;
            }
            break;
        case 8:
            if (timeString.at(6) == 'a' || timeString.at(6) == 'A') {
                timeHour = (timeString.at(0) - '0') * 10;
                timeHour += timeString.at(1) - '0';
            }
            else if (timeString.at(6) == 'p' || timeString.at(6) == 'P') {
                timeHour = (timeString.at(0) - '0') * 10;
                timeHour += timeString.at(1) - '0';
                timeHour += 12;
            }
            break;
        default:
            cout << "Error: invalid time format entered." << endl;
            break;
    }
    return timeHour;
}