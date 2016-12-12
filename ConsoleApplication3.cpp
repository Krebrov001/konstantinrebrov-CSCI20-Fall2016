/* This project was made by Konstantin Rebrov
 * CSCI-20 Final Project Fall 2016
 * 12/12/2016
 * The AI goes through a maze
 * Maze maps are a grid 25 * 25
 * 1: a wall
 * 0: empty space
 * 2: starting location
 * 3: finish location
 */


#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <windows.h>
#include <cwchar>
#include <time.h>
#include <ios>
#include <cstdlib>
using namespace std;


class Game {
public:
	Game() {
		steps = 0;
		gameStatus = true;      // status of the game
		for (int y = 0; y < (sizeof(foundLocations) / sizeof(*foundLocations)); y++) {
			for (int x = 0; x < (sizeof(foundLocations[0]) / sizeof(*foundLocations[0])); x++) {
				foundLocations[y][x] = 100; // "empty" value
			}
		}
		numChoices = 0;
		mazeSolved = false;
	}
	void readLevel(int MapFile[25][25]) {
		for (int y = 0; y < 25; y++) {
			for (int x = 0; x < 25; x++) {
				switch (MapFile[y][x]) {
				case 1:
					isEmpty[y][x] = false;
					break;
				case 2:
					isEmpty[y][x] = true;
					startLocation[0] = y;
					startLocation[1] = x;
					break;	
				case 3:
					isEmpty[y][x] = true;
					finishLocation[0] = y;
					finishLocation[1] = x;
					break;
				case 0:
				default:
					isEmpty[y][x] = true;
					break;
				}
				hasVisited[y][x] = false;
				deadEnd[y][x] = false;
				isCross[y][x] = false;
			}
		}
	}
	void setAILocation() {
		AILocation[0] = startLocation[0];
		AILocation[1] = startLocation[1];
		steps = 0;
	}
	void setGameStatus(bool gameStatus) {
		this->gameStatus = gameStatus;
	}
	bool getGameStatus() const {
		return gameStatus;
	}
	bool getMazeSolved() const {
		return mazeSolved;
	}
	int getSteps() const {
		return steps;
	}
	void PrintLevel() const {
		system("CLS");
		for (int y = 0; y < 25; y++) {
			for (int x = 0; x < 25; x++) {
				if (isEmpty[y][x] == false) {
					cout << "\333\333";
				}
				else if ((AILocation[0] == y) && (AILocation[1] == x)) {
					cout << "\2 ";
				}
				else if (isEmpty[y][x] == true) {
					cout << "  ";
				}
			}
			cout << endl;
		}
	}
	void nextMove() {
		for (int y = 0; y < (sizeof(foundLocations) / sizeof(*foundLocations)); y++) {
			for (int x = 0; x < (sizeof(foundLocations[0]) / sizeof(*foundLocations[0])); x++) {
				foundLocations[y][x] = 100; // "empty" value
			}
		}
		if ((AILocation[0] == startLocation[0]) && (AILocation[1] == startLocation[1])) {
			if (steps == 0) {
				setAILocation((AILocation[0] + 1), AILocation[1]); // move down
			}
			else {
				mazeSolved = false;
				gameStatus = false;
			}
		}
		else if ((AILocation[0] == finishLocation[0]) && (AILocation[1] == finishLocation[1])) {
			mazeSolved = true;
			gameStatus = false;
		}
		else {
			numChoices = 0;
			int tempVal;
			// loop through all possible coordinates for the next location
			for (int y = 0; y < (sizeof(totalLocations) / sizeof(*totalLocations)); y++) {
				// searches for: empty, not visited yet, not marked as dead end
				if (getEmptyStatus((AILocation[0] + totalLocations[y][0]), (AILocation[1] + totalLocations[y][1])) &&
					!getEndStatus((AILocation[0] + totalLocations[y][0]), (AILocation[1] + totalLocations[y][1])) &&
					!getVisitStatus((AILocation[0] + totalLocations[y][0]), (AILocation[1] + totalLocations[y][1]))) {
					tempVal = findNextOpenLocation();              // saves each found next coordinate
					foundLocations[tempVal][0] = (AILocation[0] + totalLocations[y][0]); // y location
					foundLocations[tempVal][1] = (AILocation[1] + totalLocations[y][1]); // x location
					numChoices++;
				}
			}
			if (numChoices == 1) {
				setAILocation(foundLocations[0][0], foundLocations[0][1]);
			}
			else if (numChoices == 2) {
				isCross[AILocation[0]][AILocation[1]] = true;
				srand(time(0));
				rand(); // dispose the first random number, quirk of Visual Studio
				int randomNumber = rand() % 4 + 1;
				if (randomNumber >= 1 && randomNumber <= 2) {
					setAILocation(foundLocations[0][0], foundLocations[0][1]);
				}
				else if (randomNumber >= 3 && randomNumber <= 4) {
					setAILocation(foundLocations[1][0], foundLocations[1][1]);
				}
			}
			else if (numChoices == 3) {
				isCross[AILocation[0]][AILocation[1]] = true;
				srand(time(0));
				rand(); // dispose the first random number, quirk of Visual Studio
				int randomNumber = rand() % 9 + 1;
				if (randomNumber >= 1 && randomNumber <= 3) {
					setAILocation(foundLocations[0][0], foundLocations[0][1]);
				}
				else if (randomNumber >= 4 && randomNumber <= 6) {
					setAILocation(foundLocations[1][0], foundLocations[1][1]);
				}
				else if (randomNumber >= 7 && randomNumber <= 9) {
					setAILocation(foundLocations[2][0], foundLocations[2][1]);
				}
			}
			else if (numChoices == 0) {
				deadEnd[AILocation[0]][AILocation[1]] = true;
				// loop through all possible coordinates for the next location
				for (int y = 0; y < (sizeof(totalLocations) / sizeof(*totalLocations)); y++) {
					// searches for: empty, already visited, not marked as dead end, or cross
					if (getEmptyStatus((AILocation[0] + totalLocations[y][0]), (AILocation[1] + totalLocations[y][1])) &&
						!getEndStatus((AILocation[0] + totalLocations[y][0]), (AILocation[1] + totalLocations[y][1])) &&
						getVisitStatus((AILocation[0] + totalLocations[y][0]), (AILocation[1] + totalLocations[y][1])) ||
						getCrossStatus((AILocation[0] + totalLocations[y][0]), (AILocation[1] + totalLocations[y][1]))) {
						tempVal = findNextOpenLocation();              // saves each found next coordinate
						foundLocations[tempVal][0] = (AILocation[0] + totalLocations[y][0]); // y location
						foundLocations[tempVal][1] = (AILocation[1] + totalLocations[y][1]); // x location
					}
				}
				setAILocation(foundLocations[0][0], foundLocations[0][1]);
			}
			else {
				gameStatus = false;
			}
		}
	}
private:
	void setAILocation(int y, int x) {
		if (hasVisited[AILocation[0]][AILocation[1]] == false) {
			hasVisited[AILocation[0]][AILocation[1]] = true;
		}
		AILocation[0] = y;
		AILocation[1] = x;
		steps++;
	}
	bool getEmptyStatus(int y, int x) const {
		return isEmpty[y][x];
	}
	bool getVisitStatus(int y, int x) const {
		return hasVisited[y][x];
	}
	bool getEndStatus(int y, int x) const {
		return deadEnd[y][x];
	}
	bool getCrossStatus(int y, int x) const {
		return isCross[y][x];
	}
	int findNextOpenLocation() const {
		int y;
		for (y = 0; y < (sizeof(foundLocations) / sizeof(*foundLocations)); y++) {
			if (foundLocations[y][0] == 100) {
				break;
			}
		}
		return y;
	}
	int steps;            // steps taken
	bool gameStatus;      // status of the game
	bool mazeSolved;      // is maze solved
	bool isEmpty[25][25]; // an empty space
	int startLocation[2];    // the starting point
	int finishLocation[2];   // the finish point
	int AILocation[2];       // current position of AI
							 // possible locations for moving
	int totalLocations[4][2] = { { 0, -1 },   // left
	                             { -1, 0 },   // up
	                             { 0, +1 },   // right
	                             { +1, 0 } }; // down
	int foundLocations[3][2]; // actually open locations
	int numChoices;           // number of open locations
	bool hasVisited[25][25]; // already visited
	bool isCross[25][25]; // is intersection
	bool deadEnd[25][25]; // dead end
};


int main()
{
	// These are chunks of code to explicilty set the properties of the console.

	// set the font of the console
	// http://stackoverflow.com/a/35383318/5500589 
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 14;                   // Width of each character in the font
	cfi.dwFontSize.Y = 28;                  // Height
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	wcscpy_s(cfi.FaceName, L"Lucida Console"); // Choose your font
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);

	// set the size of the console window
	// http://stackoverflow.com/a/21238849 
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r); //stores the console's current dimensions
	MoveWindow(console, r.left, r.top, 900, 800, TRUE); // 900 width, 800 height

	system("title Maze Walker");  // set the tile of the console window

	// http://stackoverflow.com/a/38086124
	/* you can use these constants
	FOREGROUND_BLUE
	FOREGROUND_GREEN
	FOREGROUND_RED
	FOREGROUND_INTENSITY
	BACKGROUND_BLUE
	BACKGROUND_GREEN
	BACKGROUND_RED
	BACKGROUND_INTENSITY
	*/
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	// explicitly set the console text to white
	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);

	// Create the loading text screen
	int loadingMax = 20;
	int full = 0;
	int empty = loadingMax;
	srand(time(0));
	rand(); // dispose the first random number, quirk of Visual Studio
	do {
		system("CLS");
		cout << endl << endl;
		cout << setw(27) << setfill(' ') << "Loading ..." << endl;
		cout << endl;
		cout << setw(10) << setfill(' ') << "";
		cout << "|";
		cout << setw(full) << setfill('#') << "";
		cout << setw(empty) << setfill('_') << "";
		cout << "|";
		cout << endl;
		Sleep(rand() % 1000 + 1);
		full++;
		empty--;
	} while (full <= loadingMax);

	string userInput;
	string inputStorage = "";
	string outputStorage = "";
	int gamesPlayed = 0;
	char* inputLetter = nullptr;
	char* outputLetter = nullptr;
	bool startStatus = false;

	while (true) { // start the main menu
		system("CLS");
		// explicitly set the console text to white
		SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << endl;
		cout << setw(20) << setfill(' ') << "Main Menu" << endl;
		if (!inputStorage.empty()) {
			inputLetter = &inputStorage.at(0);
		}
		if (!outputStorage.empty()) {
			outputLetter = &outputStorage.at(0);
		}
		for (int i = 1; i <= gamesPlayed; i++) {
			cout << endl;
			cout << setw(5) << setfill(' ') << "";
			cout << "Enter a map file location: (or q to quit)" << endl;
			cout << setw(5) << setfill(' ') << ">";
			if (*inputLetter == '|') {
				inputLetter++;
			}
			while (*inputLetter != '|') {
				cout << *inputLetter;
				inputLetter++;
			}
			cout << endl;
			cout << setw(8) << setfill(' ') << "";
			if (*outputLetter == '|') {
				outputLetter++;
			}
			while (*outputLetter != '|') {
				cout << *outputLetter;
				outputLetter++;
			}
			cout << endl;
		}

		if (startStatus) {
			Sleep(2000);
		}
		startStatus = false;

		cout << endl;
		cout << setw(5) << setfill(' ') << "";
		cout << "Enter a map file location: (or q to quit)" << endl;
		cout << setw(5) << setfill(' ') << ">";
		cin >> userInput;

		if (userInput == "q") {
			break;
		}

		ifstream reader(userInput);
		if (!reader.is_open()) {
			cout << setw(5) << setfill(' ') << "";
			cout << "Error: file not found" << endl;
			Sleep(1500);
		}
		else { // read the file
			int tempval1;
			string tempval2;
			string tempval3;
			bool check = false;
			int numElements = 0;
			int numRows = 0;
			int numCols = 0;

			// this code checks if the file format is right

			while (!reader.eof()) {
				reader >> tempval2;
				if (atoi(tempval2.c_str()) > 0 || isdigit(tempval2.c_str()[0])) {
					tempval1 = atoi(tempval2.c_str());
					if (!(tempval1 >= 0 && tempval1 <= 3)) {
						check = true;
						break;
					}
				}
				else {
					check = true;
					break;
				}
				numElements++;
			}

			reader.clear();
			reader.seekg(0, ios::beg);
			while (!reader.eof()) {
				getline(reader, tempval3);
				numRows++;
			}

			numCols = numElements / numRows;

			const int rows = 25;
			const int columns = 25;

			if (!(numCols == columns && numRows == rows) || check) {
				cout << setw(5) << setfill(' ') << "";
				cout << "Error: wrong file format" << endl;
				Sleep(1500);
			}
			else { // start the game

				inputStorage.append(userInput);
				inputStorage.push_back('|');
				gamesPlayed++;

				// 25 by 25 grid
				int gridLocs[rows][columns];

				reader.clear();
				reader.seekg(0, ios::beg);
				for (int y = 0; y < numRows; y++) {
					for (int x = 0; x < numCols; x++) {
						reader >> gridLocs[y][x];
					}
				}
				reader.close();

				// pick a random color
				int color1;
				int color2;
				switch (rand() % 3 + 1) {
				case 1:
					color1 = FOREGROUND_BLUE;
					break;
				case 2:
					color1 = FOREGROUND_RED;
					break;
				case 3:
				default:
					color1 = FOREGROUND_GREEN;
					break;
				}
				switch (rand() % 3 + 1) {
				case 1:
					color2 = FOREGROUND_BLUE;
					break;
				case 2:
					color2 = FOREGROUND_RED;
					break;
				case 3:
				default:
					color2 = FOREGROUND_GREEN;
					break;
				}
				SetConsoleTextAttribute(hConsole, color1 | color2 | FOREGROUND_INTENSITY);

				Game game1;
				game1.setGameStatus(true);
				game1.readLevel(gridLocs);
				game1.setAILocation();
				while (game1.getGameStatus()) {
					system("CLS");
					game1.PrintLevel();
					game1.nextMove();
					Sleep(1000);
				}
				startStatus = true;
				if (game1.getMazeSolved()) {
					outputStorage.append("Maze was solved. Steps taken: ");
					outputStorage.append(to_string(game1.getSteps()));
					outputStorage.push_back('|');
				}
				else {
					outputStorage.append("This maze is unsolveable.");
					outputStorage.push_back('|');
				}

			} // start the game

		} // read the file

	} // while (true) main menu

	// end of program
	return 0;
}