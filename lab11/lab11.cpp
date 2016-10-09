/* Name: Konstantin Rebrov
 * Date: 10/8/2016
 * This program calculates the income tax
 * and the amount owed or refunded.
 */
#include <iostream>
#include <string>
using namespace std;

/* The main method is basically
 * my whole program.
 */
int main() {
    // Declare the regular variables
    string name;
    string status;
    double grossWages;
    double taxWithHeld;
    double adj_gross_income;
    double taxOwed;
    double taxRefund;
    unsigned short numPeople;
    
    // Define the constant variables
    const double PERSONAL_EXCEPTION = 3900.00;
    const double STANDARD_DEDUCTION = 6100.00;
    
    // Input the user's information
    cout << "Enter your name:" << endl;
    getline(cin, name);
    cout << "Enter your status:" << endl;
    cin >> status;
    cout << "Enter the amount of gross wages:" << endl;
    cout << "$";
    cin >> grossWages;
    cout << "Enter the amount of tax withheld:" << endl;
    cout << "$";
    cin >> taxWithHeld;
    
    // Calculate all the tax rates
    adj_gross_income = grossWages;
    numPeople = (status == "single") ? 1 : 2;
    for (int x = 0; x < numPeople; x++) {
        adj_gross_income -= PERSONAL_EXCEPTION;
        adj_gross_income -= STANDARD_DEDUCTION;
    }
    if (adj_gross_income < 0) {
        taxOwed = 0;
    }
    else {
        if (status == "single") {
            if (adj_gross_income < 8926.0) {
                taxOwed = adj_gross_income * 0.1;
            }
            else if (adj_gross_income < 36251.0) {
                taxOwed = 892.50 + (adj_gross_income - 8925.0) * 0.15;
            }
            else if (adj_gross_income < 87851.0) {
                taxOwed = 4991.25 + (adj_gross_income - 36250.0) * 0.25;
            }
            else {
                taxOwed = 17891.25 + (adj_gross_income - 87850.0) * 0.28;
            }
        }
        else if (status == "married") {
            if (adj_gross_income < 17851.0) {
                taxOwed = adj_gross_income * 0.1;
            }
            else if (adj_gross_income < 72501.0) {
                taxOwed = 1785.0 + (adj_gross_income - 17850.0) * 0.15;
            }
            else {
                taxOwed = 9982.50 + (adj_gross_income - 72500) * 0.28;
            }
        }
    }
    
    // Determine if there is a refund
    if (taxOwed > taxWithHeld) {
        taxOwed = taxOwed - taxWithHeld;
        taxRefund = 0;
    }
    else {
        taxRefund = taxOwed;
        taxOwed = 0;
    }
    
    // Print the output
    cout << endl;
    cout << "Name: " << name << endl;
    printf("Total Gross Adjusted Income: $%'.2f\n", adj_gross_income);
    printf("Total tax owed: $%'.2f\n", taxOwed);
    cout << name;
    printf(" is entitled to a REFUND of $%'.2f\n", taxRefund);
    
    // End the program
    return 0;
}