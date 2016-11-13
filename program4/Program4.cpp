/* Name: Konstantin Rebrov
 * Date: 11/12/2016
 * This program accepts a text file
 * and makes a concordance of words from it.
 * A stop file is accepted to find out
 * which words are to be ignored in the concordance.
 * Each unique word is output, along with
 * the number of occurences and the first location
 * of occurence counting by words of the text file.
 * This information is printed to the screen and also
 * to an output file that is specified by the user.
 * The program works with all text and stop files.
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ios>
#include <iomanip>
using namespace std;

int main() {
    string textFileDir;
    string stopFileDir;
    
    ifstream inputFile1; // to read the text file
    ifstream inputFile2; // to read the stop file
    
    cout << "Input a text file name." << endl;
    cin >> textFileDir;
    inputFile1.open(textFileDir);
    if (!(inputFile1.is_open())) {
        cout << textFileDir << ": No such file or directory" << endl;
        return 1;
    }
    
    cout << "Input a stop file name." << endl;
    cin >> stopFileDir;
    inputFile2.open(stopFileDir);
    if (!(inputFile2.is_open())) {
        cout << stopFileDir << ": No such file or directory" << endl;
        return 1;
    }
    
    string storage = ""; // all the unique words
    string temp1;
    string temp2;
    
    bool isUnique;
    while (!(inputFile1.eof())) { // read the text file
        isUnique = true;
        
        inputFile1 >> temp1; // read the next word
        
        // get rid of the punctuation marks
        if (temp1.at(0) == '"' ||
            temp1.at(0) == '(') {
            temp1.erase(0, 1);
        }
        if (temp1.at(temp1.length() - 1) == '"' ||
            temp1.at(temp1.length() - 1) == ')') {
                temp1.erase(temp1.length() - 1, 1);
            }
        if (temp1.at(temp1.length() - 1) == ',' ||
            temp1.at(temp1.length() - 1) == '.' ||
            temp1.at(temp1.length() - 1) == '?' ||
            temp1.at(temp1.length() - 1) == '!' ||
            temp1.at(temp1.length() - 1) == ':' ||
            temp1.at(temp1.length() - 1) == ';') {
                temp1.erase(temp1.length() - 1, 1);
            }
            
        // uncapitalise the first letter of a sentence
        if (temp1.at(0) >= 'A' && temp1.at(0) <= 'Z') {
            temp1.at(0) += 32;
        }
        
        // read the stop file
        inputFile2.clear();
        inputFile2.seekg(0, ios::beg);
        while (!(inputFile2.eof())) {
            inputFile2 >> temp2;
            if (temp1 == temp2) { // do not count the stop words
                isUnique = false;
                break;
            }
        }
        
        if (temp1.length() < 3) { // do not count words < 3 chars long
            isUnique = false;
        }
        
        if (isUnique) { // find the unique words
            storage.append(temp1);
            storage.push_back(' ');
        }
    }
    inputFile1.close();
    inputFile2.close();
    
    // determine the number of words
    int numWords = 0;
    for (int x = 0; x < storage.length(); x++) {
        if (storage.at(x) == ' ') {
            numWords++;
        }
    }
    
    if (numWords == 0) { // storage string is empty
        return 0;
    }
    
    string uniqWords[numWords];
    int uniqCounter[numWords];
    int uniqFirstLoc[numWords];
    
    // clear the memory locations
    for (int x = 0; x < numWords; x++) {
        uniqWords[x].clear();
        uniqCounter[x] = 0;
        uniqFirstLoc[x] = 0;
    }
    
    istringstream inputString; // to read the storage string
    
    temp1.clear();
    bool isNew;
    inputString.clear();
    inputString.str(storage);
    for (int x = 0; x < numWords; x++) { // read the storage string
        isNew = true;
        
        inputString >> temp1; // read the next word from the storage string
        // compare the word to determine if it has been counted
        for (int y = 0; y < numWords; y++) {
            // if the word is not new
            if (uniqWords[y] == temp1) {
                uniqCounter[y]++;
                isNew = false;
                break;
            }
        }
        
        // if the word is new
        if (isNew) {
            // determine the next open memory location
            int z;
            for (z = 0; uniqWords[z] != ""; z++) {}
            uniqWords[z] = temp1;
            uniqCounter[z]++;
        }
    }
    
    // find the first location of occurence
    temp1.clear();
    inputFile1.open(textFileDir);
    for (int x = 0; uniqWords[x] != ""; x++) {
        inputFile1.clear();
        inputFile1.seekg(0, ios::beg);
        
        // search for word in the text file
        while (!(inputFile1.eof())) {
            uniqFirstLoc[x]++;
            inputFile1 >> temp1;
            
            // get rid of the punctuation marks
            if (temp1.at(0) == '"' ||
                temp1.at(0) == '(') {
                temp1.erase(0, 1);
            }
            if (temp1.at(temp1.length() - 1) == '"' ||
                temp1.at(temp1.length() - 1) == ')') {
                    temp1.erase(temp1.length() - 1, 1);
                }
            if (temp1.at(temp1.length() - 1) == ',' ||
                temp1.at(temp1.length() - 1) == '.' ||
                temp1.at(temp1.length() - 1) == '?' ||
                temp1.at(temp1.length() - 1) == '!' ||
                temp1.at(temp1.length() - 1) == ':' ||
                temp1.at(temp1.length() - 1) == ';') {
                    temp1.erase(temp1.length() - 1, 1);
                }
                
            // uncapitalise the first letter of a sentence
            if (temp1.at(0) >= 'A' && temp1.at(0) <= 'Z') {
                temp1.at(0) += 32;
            }
                
            if (uniqWords[x] == temp1) { // if word was found in the text file
                break;
            }
        }
    }
    inputFile1.close();
    
    ofstream outputFile1;
    string outputFileDir;
    
    cout << "Input an output file name." << endl;
    cin >> outputFileDir;
    outputFile1.open(outputFileDir);
    if (!(outputFile1.is_open())) {
        cout << "Error: " << outputFileDir << " could not be opened" << endl;
        return 1;
    }
    
    cout << endl;
    
    // print both to the screen and to output file
    cout << setfill(' ');
    cout << setw(15) << left << "The Word";
    cout << "|";
    cout << "Total # of occurences";
    cout << "|";
    cout << setw(30) << left << "First location of occurence";
    cout << endl;
    
    outputFile1 << setfill(' ');
    outputFile1 << setw(15) << left << "The Word";
    outputFile1 << "|";
    outputFile1 << "Total # of occurences";
    outputFile1 << "|";
    outputFile1 << setw(30) << left << "First location of occurence";
    outputFile1 << endl;
    
    for (int x = 0; uniqWords[x] != ""; x++) {
        cout << setw(15) << left << uniqWords[x];
        cout << "|";
        cout << setw(5) << "" << setw(16) << left << uniqCounter[x];
        cout << "|";
        cout << setw(5) << "" << setw(16) << left << uniqFirstLoc[x];
        cout << endl;
        
        outputFile1 << setw(15) << left << uniqWords[x];
        outputFile1 << "|";
        outputFile1 << setw(5) << "" << setw(16) << left << uniqCounter[x];
        outputFile1 << "|";
        outputFile1 << setw(5) << "" << setw(16) << left << uniqFirstLoc[x];
        outputFile1 << endl;
    }
    
    outputFile1.close();
    
    return 0;
}