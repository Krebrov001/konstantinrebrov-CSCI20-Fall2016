/* Name: Konstantin Rebrov
 * Date: 9/22/2016
 * Instructor: April Browne
 * Class: CSCI - 20
 */
#include <iostream>

using namespace std;

// This function converts pounds to kilograms
double ToKilo(double pounds) {
    /* scope for pounds is from here
      to the closing brace of ToKilo */
    return pounds / 2.2;
}

// This function converts kilograms to pounds
double ToPounds(double kilograms) {
    /* scope for kilograms is from here
      to the closing brace of ToPounds */
    return kilograms * 2.2;
}

int main() {
    double kiloValue; // scope is from here down to the closing brace of main
    double poundValue; // scope is from here down to the closing brace of main
    
    cout << "Enter a kilogram value." << endl;
    cin >> kiloValue;
    cout << kiloValue << " kilograms in pounds is ";
    cout << ToPounds(kiloValue) << endl;
    
    cout << "Enter a pound value." << endl;
    cin >> poundValue;
    cout << poundValue << " pounds in kilograms is ";
    cout << ToKilo(poundValue) << endl;
}