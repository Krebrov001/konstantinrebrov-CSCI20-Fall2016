#include <iostream>
#include <string>
using namespace std;

struct MonsterStruct {
    string traits1[6];
    /* name
     * head
     * eyes
     * ears
     * nose
     * mouth
     */
    
};

class MonsterClass {
    public:
    string traits2[6];
    /* name
     * head
     * eyes
     * ears
     * nose
     * mouth
     */
     
};

int main() {
    /* Declare the monster objects
     * from the monster struct 
     * and class.
     */
     
    MonsterStruct Monster1;
    MonsterStruct Monster2;
    
    MonsterClass Monster3;
    MonsterClass Monster4;
    MonsterClass Monster5;
    
    /* Initialize options for each of
     * the monsters' features.
     */
    string Options[][8] = { 
    { "head", "Zombus", "Franken", "Happy" }, 
    { "eyes", "Vegitas", "Wackus", "Spritem", "Alien" }, 
    { "ears", "Vegitas", "Wackus", "Spritem", "Horny","Alien", "Elephant" }, 
    { "nose", "Vegitas", "Wackus", "Spritem", "Elephant" }, 
    { "mouth", "Vegitas", "Wackus", "Spritem", "Elephant" } 
    };
    
    /* Initialize values for each
     * of the four monsters.
     */
    Monster1 = { "EvilMonster", "Zombus", "Vegitas", "Wackus", "Spritem", 
    "Wackus" };
    Monster2 = { "Moonian", "Happy", "Alien", "Alien", "Vegitas", "Spritem" };
    Monster3 = { "Demon", "Franken", "Wackus" , "Horny", "Vegitas", 
    "Elephant" };
    Monster4 = { "Mammoth", "Zombus", "Vegitas", "Elephant", "Elephant", 
    "Elephant" };
    
    // Input name for the fifth monster.
    cout << "Enter name for Monster 5." << endl;
    cin >> Monster5.traits2[0];
    cout << endl;
    
    /* Input all the other values for
     * the fifth monster's features
     * and check if they match the
     * options.
     */
    int x;
    for (int y = 0; y < 5; y++) {
        bool repeat = true;
        tryAgain:
        cout << "Enter " << Options[y][0] << " for Monster 5." << endl;
        cout << "Options are:";
        for (x = 1; x < (sizeof(Options[y])/sizeof(*Options[y])) - 1; x++) {
            if (Options[y][x] == "") {
                break;
            }
            cout << " " << Options[y][x];
        }
        cout << "." << endl;
        cin >> Monster5.traits2[y + 1];
        for (x = 1; x < (sizeof(Options[y])/sizeof(*Options[y])) - 1; x++) {
            if (Options[y][x] == Monster5.traits2[y + 1]) {
                repeat = false;
                break;
            }
        }
        if (repeat) {
            cout << "You did not enter a valid " << Options[y][0] << 
            " for Monster5." << endl;
            cout << "Please try again." << endl;
            goto tryAgain;
        }
        cout << endl;
    }
    
    /* Output all the values
     * for each monster.
     */
    int z;
    for (z = 0; z < 6; z++) {
        cout << Monster1.traits1[z];
        switch (z) {
            case 0:
                cout << ": ";
                break;
            case 5:
                cout << endl;
                break;
            default:
                cout << ", ";
                break;
        }
    }
    for (z = 0; z < 6; z++) {
        cout << Monster2.traits1[z];
        switch (z) {
            case 0:
                cout << ": ";
                break;
            case 5:
                cout << endl;
                break;
            default:
                cout << ", ";
                break;
        }
    }
    for (z = 0; z < 6; z++) {
        cout << Monster3.traits2[z];
        switch (z) {
            case 0:
                cout << ": ";
                break;
            case 5:
                cout << endl;
                break;
            default:
                cout << ", ";
                break;
        }
    }
    for (z = 0; z < 6; z++) {
        cout << Monster4.traits2[z];
        switch (z) {
            case 0:
                cout << ": ";
                break;
            case 5:
                cout << endl;
                break;
            default:
                cout << ", ";
                break;
        }
    }
    for (z = 0; z < 6; z++) {
        cout << Monster5.traits2[z];
        switch (z) {
            case 0:
                cout << ": ";
                break;
            case 5:
                cout << endl;
                break;
            default:
                cout << ", ";
                break;
        }
    }
    
    return 0;
}