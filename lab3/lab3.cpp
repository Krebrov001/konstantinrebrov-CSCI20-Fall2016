#include <iostream>
#include <string>
using namespace std;

int main() {
    int num1;
    float num2;
    char letter;
    string name;
    
    cout << "Enter your full name." << endl;
    getline(cin, name);
    cout << "Enter your age." << endl;
    cin >> num1;
    cout << "Enter a floating point value." << endl;
    cin >> num2;
    cout << "Enter a char value." << endl;
    cin >> letter;
    
    cout << endl << name << " is " << num1 << " years old.\n" << endl;
    cout << "Decimal number: " << num2 << endl;
    cout << "Letter: " << letter << endl;
    
    return 0;
}