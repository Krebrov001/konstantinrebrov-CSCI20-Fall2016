/* This program was made
 * by Konstantin Rebrov.
 * It has 3 parts:
 * Weekly Wage
 * Number of Calories
 * Class Grades
 */
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

/* The wait function is called
 * to delay the program
 * when running the code.
 */
void wait ( int seconds ) 
{ 
  clock_t endwait; 
  endwait = clock () + seconds * CLOCKS_PER_SEC ; 
  while (clock() < endwait) {} 
} 

/* Calculates a person's
 * weekly wage based on
 * hourly salary and hours.
 */
void WeeklyWage() {
    // Input all the data.
    string name1;
    cout << "Enter your full name." << endl;
    getline(cin, name1);
    float payPerHour;
    float hoursPerWeek;
    cout << "Enter your hourly salary." << endl;
    cin >> payPerHour;
    cout << "Enter how many hours you work per week." << endl;
    cin >> hoursPerWeek;
    
    // Calculate and output all the data.
    float payPerWeek = payPerHour * hoursPerWeek;
    cout << "Your name is " << name1 << ".\n";
    cout << "You work " << hoursPerWeek << " hours per week." << endl;
    printf("You get paid $%.2f per hour.\n", payPerHour);
    printf("Your gross pay per week is $%.2f.\n", payPerWeek);
    float taxRate = 0.17;
    payPerWeek = payPerWeek - (payPerWeek * taxRate);
    printf("Your net pay per week is $%.2f.\n" , payPerWeek);
}
/* Calculates the number of
 * calories a person has
 * expanded in his/her
 * lifetime.
 */
void NumCalories() {
    // Input the name and age.
    string name2;
    cin.ignore(1,'\n');
    cout << endl << "Enter your full name." << endl;
    getline(cin, name2);
    int age;
    cout << "Enter your age." << endl;
    cin >> age;
    cout << "Hi, " << name2 << "." << endl;
    cout << "You are " << age << " years old." << endl;
    
    // Calculate and display the number of calories.
    int ageDays = age * 365;
    int caloriesPerAge = ageDays * 2200;
    int caloriesPerYear = caloriesPerAge / age;
    cout << "You have expended " << caloriesPerAge;
    cout << " calories in your lifetime." << endl;
    cout << "That is about " << caloriesPerYear; 
    cout << " calories per year." << endl;
    
    // Calculate and display the number of burgers.
    const int burgerCalories = 490;
    int numBurgers = caloriesPerAge / burgerCalories;
    wait(1);
    cout << "A burger contains " << burgerCalories << " calories." << endl;
    cout << "If your diet consisted of burgers only, ";
    cout << "that means you ate " << numBurgers;
    cout << " burgers in your lifetime!" << endl;
    numBurgers = caloriesPerYear / burgerCalories;
    cout << "On average, you eat " << numBurgers 
    << " burgers per year..." << endl;
    wait(1);
    cout << "You should watch your weight";
    wait(1);
    cout << ", and eat less burgers!" << endl;
    cout << endl;
}
/* Calculates a student's
 * grade sheet based on
 * 5 grades that are
 * halfway through the
 * class.
 */
void NumGrades() {
    /* Input the name and grades.
     * Calculate the average.
     */
    cin.ignore(1, '\n');
    string name3;
    cout << "What is your name?" << endl;
    getline(cin, name3);
    string grades[5] = {"first", "second", "third", "fourth", "fifth"};
    int numGrades[5];
    int gradesAvg = 0;
    for (int x = 0; x < 5; x++) {
        cout << "Enter the " << grades[x] << " grade." << endl;
        cin >> numGrades[x];
        gradesAvg += numGrades[x];
    }
    gradesAvg /= (sizeof(numGrades) / sizeof(*numGrades));
    int maxGrade = 100 * 2 - gradesAvg;
    maxGrade = (maxGrade > 100) ? 100 : maxGrade;
    int finalScore1 = (maxGrade + gradesAvg) / 2;
    int minGrade = 70 * 2 - gradesAvg;
    minGrade = (minGrade > 100) ? 100 : minGrade;
    int finalScore2 = (minGrade + gradesAvg) / 2;
    
    // Output all the data.
    cout << "Name: " << name3 << "." << endl;
    for (int y = 0; y < 5; y++) {
        cout << "Grade " << (y + 1) << ": " << numGrades[y] << "." << endl;
    }
    cout << "Your average grade for the first half is " << gradesAvg 
    << "." << endl;
    if ((finalScore1 >= 70) && (finalScore2 >= 70)) {
        cout << "The maximum average grade for the second half ";
        cout << "that you need to pass this class is ";
        cout << maxGrade << "." << endl;
        cout << "If you get this grade your final score will be ";
        cout << finalScore1 << "." << endl;
        cout << "The minimum average grade for the second half ";
        cout << "that you need to pass this class is ";
        cout << minGrade << "." << endl;
        cout << "If you get this grade your final score will be ";
        cout << finalScore2 << "." << endl;
    }
    else {
        cout << "You will not be able to pass this class." << endl;
    }
}
int main() {
    /* Call all the functions
     * or programs from the 
     * main function.
     */
     
    WeeklyWage();
    
    wait(2);
    NumCalories();
    
    wait(2);
    NumGrades();
    
    return 0;
}