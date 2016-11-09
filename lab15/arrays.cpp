#include <iostream>
#include <string>
using namespace std;

int main() {
    string personInfo[3][4] = {
	{ "Konstantin", "December", "third", "4" } , 
	{ "Shane", "August", "tenth", "∞" } ,
	{ "Keanan", "September", "eighth", "0" } 
	};

cout << "Number of entries in the array: ";
cout << sizeof(personInfo)/sizeof(*personInfo) << endl;
cout << sizeof(personInfo[0])/sizeof(*personInfo[0]) << endl;
}