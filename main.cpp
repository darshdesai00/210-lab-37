#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <list>
using namespace std;


// Part Three: hash function
int gen_hash_index(const string &s) {
    int total = 0;
    for (char c : s) {
        total += (int)c;
    }
    return total;
}

// Milestone 1
void print_first_100(const map<int, list<string>> &hash_table) {
    cout << "\n--- First 100 Hash Table Entries ---\n";
    int printed = 0;

    for (const auto &entry : hash_table) {
    if (printed >= 100) break;

    cout << "Hash Index: " << entry.first << endl;

    if (!entry.second.empty()) {
    cout << "   First value: " << entry.second.front() << endl;
    }

    cout << endl;
    printed++;
    }
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

    string code;
    long long grand_total = 0;
    
    // Read 12-character strings of hexadecimal characters
    while (file >> code) {
        grand_total += gen_hash_index(code);

    }

    file.close();

    // Output the grand total
    cout << "Grand total ASCII sum = " << grand_total << endl;

    // Part Three : Hash Table
    ifstream file2("data.txt");
    if (!file2.is_open()) {
        cout << "Error: could not reopen data file.\n";
        return 1;
    }

    map<int, list<string>> hash_table;
    string code2;

    while (file2 >> code2) {
        int hash_index = gen_hash_index(code2);
        hash_table[hash_index].push_back(code2);
    }

    file2.close();
  
cout << "\nFirst 100 hash table entries:\n";
    int printed = 0;

    for (auto &entry : hash_table) {
    if (printed >= 100) break;

    cout << "Hash Index: " << entry.first << endl;

    if (!entry.second.empty()) {
    cout << "   First value: " << entry.second.front() << endl;
}


    cout << endl;  // space between entries
    printed++;
   
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
