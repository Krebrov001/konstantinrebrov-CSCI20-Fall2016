/* Name: Konstantin Rebrov
 * Date: 11/17/2016
 * I've added comments to describe what
 * this code does.
 * In my view, this code is not finished yet
 * and is still supposed to be in development.
 * The code contains some logical errors
 * and bad programming practices.
 * I don't like how it's formatted.
 */
#include <iostream>
#include <cstring>
using namespace std;
 
int main()
{
                char firststr[10]; // creates a char array c-string with size 10
                int firstname = 0;
                // assigns to char pointer head the uninitialized value of c-string firststr
                char *head = firststr; 
                // assigns to char pointer tail the uninitialized value of c-string firststr
                char *tail = firststr;
                
                /* prompt the user to enter input into c-string
                 * Logical error: the program prompts the user
                 * to enter a 10 letter word or less.
                 * Means: firststr's max length is 10.
                 * Well, what if the user enters a string with 10
                 * letters like, "Konstantin"?
                 * The c-string will be printed to the screen using cout.
                 * However, it will not enter the first if statement
                 * because the max c-string length for that condition is 9!
                 * Such a string will not get printed again char by char.
                 * It will enter the else statement and display a warning.
                 * Such a warning would confuse the user who entered
                 * a c-string with 10 chars long.
                 * Additionally the 10th char (index 9) should contain '\0'.
                 * The cout statement should prompt the user to enter
                 * a 9 letter word or less.
                 */
                cout << "Please enter a 10 letter word or less" << endl; // FIXME
                cin >> firststr;
                strlen(firststr); // returns the length, value is not used
                firstname = strlen(firststr); // firstname contains the length of c-string
                cout << "Your word is " << firststr << endl; // prints the word
                if (firstname<10) // if the c-string is 9 chars or less
                {
                    /* loops through all the memory locations
                     * a c-string's char values are consecutive in memory
                     * the char pointer head stores the memory location
                     * of the first char of the c-string firststr
                     * By incrementing head, it is able to loop through
                     * all the memory locations and print every char
                     * by dereferencing to get the value.
                     * The looping stops when the null terminator
                     * '\0' is reached.
                     */
                                while (*head != '\0')
                                {
                                                cout << *head;
                                                head++;
                                }
                } // after the loop ends, head contains the memory location of '\0'
                else // If the c-string's length is greater than 9
                     // Means: 10 or more
                {
                                cout << "WARNING WORD TOO BIG TO DISPLAY!!" << endl;
                }
                cout << endl; // print a '\n' and flush the output stream
                // sets tail to the address of the last char
                // that is directly before '\0'
                tail = &firststr[strlen(firststr) - 1];
                if (firstname < 10) // if firststr's length is 9 or less
                {
                    /* loops through all chars backwards
                     * the while loop compares each char, or rather
                     * that char's ASCII value to 0
                     * I think that this loop condition is unsecure
                     * It could lead to bugs.
                     * For example: if you had chars in memory locations
                     * directly before firststr, it would print out
                     * those chars.
                     */
                                while (*tail>0)
                                {
                                                cout << *tail;
                                                tail--;
                                }
                }
                cout << endl;
                head = firststr; // sets head to first memory location of firststr
                // sets tail to memory location of last character
                tail = &firststr[strlen(firststr) - 1];
                // increments head and decrements tail
                // "goes in one level" of the memory locations of the c-string
                head++;
                tail--;
                /* The code then checks if the chars at the corresponding
                 * memory locations are the same.
                 * If so, it is declared a "palindrome".
                 * However there is one logical error:
                 * This code only compares the two next inner chars
                 * and it does not iterate through the entire string.
                 * It will detect non-palindromes like the string "abcdefbh".
                 */
                if (*head == *tail)
                {
                                cout << "It is an palindrome!" << endl;
                }
                else
                {
                                cout << "It is not an palindrome" << endl;
                }
 
                return 0; // end the main method and return a value of 0
}
