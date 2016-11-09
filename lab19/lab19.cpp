/* Name: Konstantin Rebrov
 * Date: 11/9/2016
 * This program takes an input file
 * with a matrix of numbers.
 * It works with any number of rows and columns.
 * The sums of the rows, columns, and average number
 * are added to the output file.
 */
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
    string inputFile = "";  // input file destination
    string outputFile = ""; // output file destination
    
    /* User input can be either a relative or absolute path to file
     * Relative: numbersMatrix.txt
     * Absolute: /home/ubuntu/files/numbersMatrix.txt
     */
    cout << "Enter a file for data input." << endl;
    cin >> inputFile;
    
    ifstream read;
    
    read.open(inputFile);
    
    // if the file cannot be opened
    if (!(read.is_open())) {
        cout << inputFile << ": No such file or directory" << endl;
        return 1;
    }
    
    int numElements = 0; // number of elements in the file
    int rows = 0;        // number of rows in the file
    int columns = 0;     // number of columns in the file 
    
    // temporary variables for counting the number of elements and rows
    int tempVar1;
    string tempVar2; 
    
    // count the number of elements
    while (!(read.eof())) {
        read >> tempVar1;
        numElements++;
    }
    
    // count the number of rows
    read.clear();
    read.seekg(0, ios::beg);
    while (!(read.eof())) {
        getline(read, tempVar2);
        rows++;
    }
    
    // count the number of columns
    columns = numElements / rows;
    
    int myArray[rows + 1][columns + 1]; // matrix for storage of numbers
    
    // read data from the file and calculate the sums and average
    read.clear();
    read.seekg(0, ios::beg);
    for (int i = 0; i < columns + 1; ++i) {
        myArray[rows][i] = 0; // clear the columns sums values
    }
    for (int y = 0; y < rows; ++y) {
        myArray[y][columns] = 0; // clear the rows sums values
        for (int x = 0; x < columns; ++x) {
            read >> myArray[y][x];
            myArray[y][columns] += myArray[y][x]; // add to rows sums
            myArray[rows][x] += myArray[y][x];    // add to collumns sums
            myArray[rows][columns] += myArray[y][x]; // add to total sum
        }
    }
    // determine the average (mean) value
    myArray[rows][columns] = myArray[rows][columns] / numElements;
    
    read.close();
    
    /* Determines the path to the output file
     * The output file is written to the same
     * directory as the input file.
     * Absolute directory path works
     * only on Linux filesystems.
     */
    if (inputFile.rfind('/') != string::npos) {
        outputFile = inputFile.substr(0, inputFile.rfind('/') + 1);
    }
    outputFile.append("output.txt");
    
    // write the matrix to the ouput file
    ofstream write(outputFile);

    for (int y = 0; y < rows + 1; ++y) {
        for (int x = 0; x < columns + 1; ++x) {
            if (x == 0) {
                write << setw(2) << left << myArray[y][x];
            }
            else {
                write << setw(3) << right << myArray[y][x];
            }
        }
        write << endl;
    }
    
    write.close();
    
    return 0;
}