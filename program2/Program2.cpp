#include <iostream>
using namespace std;

class ATMClass {
    public:
        ATMClass() {
            accountBalance = 0;
        }
        ATMClass(double input) {
            accountBalance = input;
        }
        void Deposit(double input) {
            if (input > 0) {
                accountBalance += input;
            }
            else {
                cout << "Error: you did not enter a valid ";
                cout << "deposit amount." << endl;
            }
        }
        void Withdrawl(double input) {
            if (input <= accountBalance) {
                accountBalance -= input;
            }
            else {
                cout << "Error: you did not enter a valid ";
                cout << "withdrawl amount." << endl;
            }
        }
        void PrintAccountBalance() {
            printf("Your account balance is $%.2f.\n", accountBalance);
        }
    private:
        double accountBalance;
};

int main() {
    ATMClass atmMachine;
    
    atmMachine.Deposit(100);
    atmMachine.Withdrawl(20);
    atmMachine.PrintAccountBalance();
    atmMachine.Withdrawl(60);
    atmMachine.Withdrawl(40);
    atmMachine.PrintAccountBalance();
    atmMachine.Deposit(73);
    atmMachine.Withdrawl(40);
    
    return 0;
}