/* Name: Konstantin Rebrov
 * Date: 10/18/2016
 * I chose the first assigned program
 * Number Guessing Game
 * I did not use the standard namespace.
 * I wanted to do something different.
 */
#include <iostream>
#include <cstdlib>
#include <ctime>
using std::cout;
using std::cin;
using std::endl;

/* This is the class for the game.
 * It sets and gets the values of 
 * the private variables
 * userGuess and rightNumber.
 */
class NumGame {
    public:
    NumGame() {
        userGuess = 0;
        rightNumber = 0;
    }
    void SetRightNumber(int num1, int num2) {
        srand(time(0));
        rightNumber = ((rand() % num2) + num1);
    }
    void SetUserGuess(int enterNum) {
        userGuess = enterNum;
    }
    int GetRightNumber() {
        return rightNumber;
    }
    int GetUserGuess() {
        return userGuess;
    }
    private:
        int userGuess;
        int rightNumber;
};

/* The main function contains all
 * of the input/output to play the game.
 * For more information see Program3Pseudocode.cpp
 */
int main() {
    int enterNumber;
    
    NumGame game1;
    
    int num1, num2;
    cout << "Enter an integer." << endl;
    cin >> num1;
    cout << "Enter an integer." << endl;
    cin >> num2;
    cout << endl;
    
    game1.SetRightNumber(num1, num2);
    
    int score = 5;
    
    do {
        cout << "Enter an integer." << endl;
        cin >> enterNumber;
        game1.SetUserGuess(enterNumber);
        
        if (game1.GetUserGuess() >= num1 && game1.GetUserGuess() <= num2) {
            if (game1.GetUserGuess() > game1.GetRightNumber()) {
                cout << "lower" << endl;
                score--;
            }
            else if (game1.GetUserGuess() < game1.GetRightNumber()) {
                cout << "higher" << endl;
                score--;
            }
            else if (game1.GetUserGuess() == game1.GetRightNumber()) {
                cout << "winner" << endl;
                score++;
            }
        }
        else {
            cout << "Hey you idiot! Enter an integer between the values!";
            cout << endl;
            score--;
            cin.clear();
            cin.ignore();
        }
    } while (game1.GetUserGuess() != game1.GetRightNumber());
    
    cout << "Your score is " << score << endl;
    
    return 0;
}