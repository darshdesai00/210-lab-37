#include <iostream>
#include <string>
using namespace std;


// Part One 
int sum_ascii(const string &s) {
    int total = 0;
    for (char c : s) {
        total += (int)c;
    }
    return total;
}

int main() {
    char a = 'A';
    cout << a << endl;
    cout << (int) a << endl;
    int b = 66;
    cout << b << endl;
    cout << (char) b << endl;
    
    // Part Two 
    ifstream file("data.txt");   // your dataset file
    if (!file.is_open()) {
        cout << "Error: could not open data file.\n";
        return 1;
    }

    string code;;
    long long grand_total = 0;

    // Read 12-character strings of hexadecimal characters
    while (file >> code) {
        grand_total += sum_ascii(code);
    }
    
    return 0;
}

/* 
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/
