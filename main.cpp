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
    
    // Part One : Testing
    cout << "\nTesting sum_ascii...\n";

    string test1 = "HELLO";
    cout << "sum_ascii(\"HELLO\") = " << sum_ascii(test1) << endl;
   
    string test2 = "ABC";
    cout << "sum_ascii(\"ABC\") = " << sum_ascii(test2) << endl;
    
    return 0;
}

/* 
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/
