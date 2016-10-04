/* Name: Konstantin Rebrov
 * Date: 10/3/2016
 * This program provides the
 * answers to the logical puzzles.
 * The boolean expressions are
 * evaluated and then compared
 * to my answers.
 * Automatic checking is used
 * to test my answers.
 */
 
#include <iostream>
#include <string>
using namespace std;

// global variables used in multiple functions
int z, y, x;

/* Each one of these functions
 * evaluates the equations
 * and returns a boolean value.
 */
bool function1() {
    int suzyAge = 25;
    int johnAge = 21;
    return (suzyAge < johnAge);
}

bool function2() {
    x = 7;
    y = 7;
    return (x >= y);
}

bool function3() {
    int a = 1;
    int b = 9;
    return (a == b);
}

bool function4() {
    int limit = 20;
    int count = 10;
    return ((limit * count) / 2 > 0);
}

bool function5() {
    int t = -4;
    z = 0;
    return (t > 5 || z < 2);
}

bool function6() {
    int variable = -5;
    return (!(variable > 0));
}

bool function7() {
    int a = 16;
    return (a / 4 < 8 && a >= 4);
}

bool function8() {
    x = -2;
    y = 5;
    return (x * y < 10 || y * z < 10);
}

bool function9() {
    int j = -2;
    int k = 5;
    int l = 4;
    return (!(j * l < 10) || y / x * 4 < y * 2);
}

/* The class Answers has functions
 * for setting and getting my
 * answer to the above equations.
 */
class Answers {
    public: 
        void SetMyAnswer(bool truthStatement);
        bool GetMyAnswer() const;
    private: 
        bool myAnswer;
};

/* Sets myAnswer equal to an
 * input parameter.
 */
void Answers::SetMyAnswer(bool truthStatement) {
    myAnswer = truthStatement;
}

/* Gets myAnswer to the main
 * function.
 */
bool Answers::GetMyAnswer() const {
    return myAnswer;
}

/* Checks to see if my
 * answer is right or not.
 */
string CheckAnswer(bool answer1, bool answer2) {
    string correctness;
    
    /* The expression is true if both answers
     * are true or if both answers are false.
     */
    if (!((answer1 || answer2) && !(answer1 && answer2))) {
        correctness = "right";
    }
    else {
        correctness = "wrong";
    }
    return correctness;
}

int main() {
    // Create an object of the Answers class to store data.
    Answers answersList;
    
    // Evaluate the function and print the return value.
    cout << "Equation 1 evaluates to " << function1() << "." << endl;
    /* Set myAnswer and then print the return value.
     * All answers were determined by me
     * before running the program.
     */
    answersList.SetMyAnswer(false);
    cout << "My answer for equation 1 is " << answersList.GetMyAnswer();
    cout << "." << endl;
    // Automatically check my answer.
    cout << "My answer is ";
    cout << CheckAnswer(function1(), answersList.GetMyAnswer()) << "." << endl;
    cout << endl;
    
    cout << "Equation 2 evaluates to " << function2() << "." << endl;
    answersList.SetMyAnswer(true);
    cout << "My answer for equation 2 is " << answersList.GetMyAnswer();
    cout << "." << endl;
    cout << "My answer is ";
    cout << CheckAnswer(function2(), answersList.GetMyAnswer()) << "." << endl;
    cout << endl;
    
    cout << "Equation 3 evaluates to " << function3() << "." << endl;
    answersList.SetMyAnswer(false);
    cout << "My answer for equation 3 is " << answersList.GetMyAnswer();
    cout << "." << endl;
    cout << "My answer is ";
    cout << CheckAnswer(function3(), answersList.GetMyAnswer()) << "." << endl;
    cout << endl;
    
    cout << "Equation 4 evaluates to " << function4() << "." << endl;
    answersList.SetMyAnswer(true);
    cout << "My answer for equation 4 is " << answersList.GetMyAnswer();
    cout << "." << endl;
    cout << "My answer is ";
    cout << CheckAnswer(function4(), answersList.GetMyAnswer()) << "." << endl;
    cout << endl;
    
    cout << "Equation 5 evaluates to " << function5() << "." << endl;
    answersList.SetMyAnswer(true);
    cout << "My answer for equation 5 is " << answersList.GetMyAnswer();
    cout << "." << endl;
    cout << "My answer is ";
    cout << CheckAnswer(function5(), answersList.GetMyAnswer()) << "." << endl;
    cout << endl;
    
    cout << "Equation 6 evaluates to " << function6() << "." << endl;
    answersList.SetMyAnswer(true);
    cout << "My answer for equation 6 is " << answersList.GetMyAnswer();
    cout << "." << endl;
    cout << "My answer is ";
    cout << CheckAnswer(function6(), answersList.GetMyAnswer()) << "." << endl;
    cout << endl;
    
    cout << "Equation 7 evaluates to " << function7() << "." << endl;
    answersList.SetMyAnswer(true);
    cout << "My answer for equation 7 is " << answersList.GetMyAnswer();
    cout << "." << endl;
    cout << "My answer is ";
    cout << CheckAnswer(function7(), answersList.GetMyAnswer()) << "." << endl;
    cout << endl;
    
    cout << "Equation 8 evaluates to " << function8() << "." << endl;
    answersList.SetMyAnswer(true);
    cout << "My answer for equation 8 is " << answersList.GetMyAnswer();
    cout << "." << endl;
    cout << "My answer is ";
    cout << CheckAnswer(function8(), answersList.GetMyAnswer()) << "." << endl;
    cout << endl;
    
    cout << "Equation 9 evaluates to " << function9() << "." << endl;
    answersList.SetMyAnswer(true);
    cout << "My answer for equation 9 is " << answersList.GetMyAnswer();
    cout << "." << endl;
    cout << "My answer is ";
    cout << CheckAnswer(function9(), answersList.GetMyAnswer()) << "." << endl;
    cout << endl;
    
    return 0;
}