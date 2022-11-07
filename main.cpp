#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function Prototypes
int getLeadingDigit(int b);

int main() {
    ifstream enrollments;
    enrollments.open("enrollments.txt");
    string line;

    // Array to hold count of corresponding leading digit - Ex. if the line reads '10' then leadingDigit[0] will be incremented
    int leadingDigit [9] = {0};

    if (enrollments.is_open()){
        while (getline(enrollments, line) ) {
            // Integer to take in the current enrollment value for the given line
            int a;

            // Assign line to 'a'
            a = stoi(line);

            // Reassign 'a' to its leading digit
            a = getLeadingDigit(a);

            // Increment array
            leadingDigit[a - 1]++;

        } // End for loop

        enrollments.close();
    } else {
        cout << "Cannot open file. " << endl;
    }

    for (int i = 0; i < 9; ++i) {
        cout << i + 1 << " is the leading digit " << leadingDigit[i] << " times." << endl;
    }

    return 0;
}


int getLeadingDigit(int b) {
    while (b >= 10){
        b /= 10;
    }
    return b;
}

