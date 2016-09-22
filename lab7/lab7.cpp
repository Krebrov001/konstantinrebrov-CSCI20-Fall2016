#include <iostream>
#include <string>
#include <time.h>
#include <cstdlib>
using namespace std;

void wait (int seconds) {
    clock_t endwait;
    endwait = clock() + seconds * CLOCKS_PER_SEC;
    while (clock() < endwait) {}
}

void SongPart1(string animal) {
    cout << "There was a greedy famer and he had a " << animal << ".\n";
    cout << "He was so greedy that he didn't feed the " << animal << ".\n";
    for (int x = 0; x < 2; x++) {
        cout << "He didn't feed the " << animal << "." << endl;
    }
    cout << "He didn't feed the " << animal << " at all!" << endl;
    
    return;
}

void SongPart2(string animal, string location) {
    cout << "The " << animal << " didn\'t like this at all!" << endl;
    cout << "And the " << animal << " said," << endl;
    cout << "\"I do not like you farmer.\n";
    cout << "You are very greedy and mean." << endl;
    cout << "You do not feed me, and I'll run away from you." << endl;
    for (int x = 0; x < 3; x++) {
        cout << "I'll run away from you." << endl;
    }
    cout << "And I'll hide in the " << location << ".\"" << endl;
    
    return;
}

void SongPart3(string animal, string location, int hours) {
    cout << "The " << animal << " ran away to the " << location << ".\n";
    cout << "In " << hours << " hours the farmer went to look for ";
    cout << "his " << animal << "." <<endl;
    for (int x = 0; x < 3; x++) {
        cout << "He looked for the " << animal << " everywhere in the ";
        cout << location << "." << endl;
    }
    cout << "But he didn't find the " << animal << " and returned to ";
    cout << "his house without luck." << endl;
    
    return;
}

int main() {
    
    string animals[5] = { "dog", "cat", "pig", "goat", "horse" };
    string place[5] = { "field", "barn", "school", "village", "city" };
    
    for (int x = 0; x < (sizeof(animals)/sizeof(*animals)); x++) {
        SongPart1(animals[x]);
        wait(1);
        cout << endl;
        int randomNumber = rand() % (sizeof(place)/sizeof(*place));
        SongPart2(animals[x], place[randomNumber]);
        wait(1);
        cout << endl;
        SongPart3(animals[x], place[randomNumber], rand() % 6);
        wait(2);
        cout << endl;
    }
    
    return 0;
}