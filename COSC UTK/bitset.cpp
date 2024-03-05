/* Program Name: BITSET
 * Student Name: Lauren Thompson
 * Program Description: The BITSET lab uses bitset operators to solve various designed problems. */

#include <bitset>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class BITSET {
    vector<int> mSets;

  public:
    BITSET();
    bool Test(int index) const;
    void Set(int index);
    void Clear(int index);
    int GetNumSets() const;
    int GetSet(int index) const;
};
string ToBinary(int bit_set, int spacing = 4);
int main() {
    BITSET sets;
    string command;
    int which;
    do {
        cout << "> ";
        if (!(cin >> command) || "q" == command) {
            // If cin fails for any reason, it usually means
            // an EOF state, break and quit.
            break;
        }
        if ("t" == command) {
            if (!(cin >> which)) {
                cout << "Invalid index\n";
            } else {
                cout << sets.Test(which) << '\n';
            }
        } else if ("s" == command) {
            if (!(cin >> which)) {
                cout << "Invalid index\n";
            } else {
                sets.Set(which);
            }
        } else if ("g" == command) {
            int spacing;
            string line;
            getline(cin, line);
            istringstream sin{line};
            if (!(sin >> which)) {
                cout << "Invalid index\n";
            } else {
                if (!(sin >> spacing)) {
                    spacing = 4;
                }
                cout << ToBinary(sets.GetSet(which), spacing) << '\n';
            }
        } else if ("c" == command) {
            if (!(cin >> which)){
                cout << "Invalid index\n";
            } else {
                sets.Clear(which);
            }
        } else if ("n" == command){
            
            cout << sets.GetNumSets() << endl;
        }
        else {
            cout << "Unknown command '" << command << "'\n";
        }
    } while (true);
    return 0;
}

// Converts inputted binary (an int) to a string
string ToBinary(int bit_set, int spacing) {
    string ret;

    // Add values to the ret string 
    int counter = 0;
    for (int i = 31; i >= 0; i--) {
        
        if (bit_set & (1 << i)) {

            ret += '1';

        } else {

            ret += '0';

        }

        counter++;
        
        // Checks to see if string needs spaces added 
        if (counter % spacing == 0 && i != 0) {
            ret += ' ';
        }
    }
    return ret;
}

// BITSET Class Members
BITSET::BITSET() : mSets(1, 0) {}

bool BITSET::Test(int index) const {

    // Defines and search for highlighted bit in specific set
    int which_set = index / 32;
    int which_bit = index % 32;

    if (which_set >= GetNumSets()) {

        return false;
    }

    // Tests the bit at specific space and returns true if it's a 1 or false if it's a 0
    if (mSets.at(which_set) & (1 << which_bit)){
        
        return true;

    } else {
        
        return false; 
    }

}

void BITSET::Set(int index) {
    int which_set = index / 32; 
    int which_bit = index % 32;
    // Expands the set if index exceeds which_set
    if (which_set >= GetNumSets()){
        
        mSets.resize(which_set + 1);
    }

    // Sets which_bit at specific space to 1
    mSets.at(which_set) = mSets.at(which_set) | (1 << which_bit);
}

void BITSET::Clear(int index) {
    int which_set = index / 32;
    int which_bit = index % 32;

    // Clears which_bit at specific space to 0
    if (which_set < GetNumSets()) {

        mSets.at(which_set) = mSets.at(which_set) & ~(1 << which_bit);
    }

    // Removes a ste from the vector if it's all 0
    for (int i = mSets.size()-1; i > 0; i--){
        
        if (mSets.back() == 0){
            
            mSets.pop_back();
        } else {
            
            break;
        }
    }
}

// Gets the number of sets | size of the vector
int BITSET::GetNumSets() const { return static_cast<int>(mSets.size()); }

int BITSET::GetSet(int which_set) const {

    // Checks to see if the index exists
    if (which_set >= int(mSets.size())){
        
        return 0;
    } else {

        return mSets.at(which_set);
    }
}
