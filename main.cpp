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

// Milestone 2
void search_key(const map<int, list<string>> &hash_table) {
    string target;
    cout << "Enter key to search for: ";
    cin >> target;

    int hash_index = gen_hash_index(target);

    // Check if hash index exists
    auto it = hash_table.find(hash_index);
    if (it == hash_table.end()) {
        cout << "Key NOT found.\n";
        return;
    }

    // Search inside the list (bucket)
    const list<string> &bucket = it->second;
    for (const string &val : bucket) {
        if (val == target) {
            cout << "Key FOUND in hash index " << hash_index << "!\n";
            return;
        }
    }

    cout << "Key NOT found.\n";
}

// Milestone 3
void add_key(map<int, list<string>> &hash_table) {
    string newkey;
    cout << "Enter key to add: ";
    cin >> newkey;

    int hash_index = gen_hash_index(newkey);

    hash_table[hash_index].push_back(newkey);

    cout << "Key added successfully at hash index " << hash_index << "!\n";
}


// Milestone 4
void remove_key(map<int, list<string>> &hash_table) {
    string target;
    cout << "Enter key to remove: ";
    cin >> target;

    int hash_index = gen_hash_index(target);

    auto it = hash_table.find(hash_index);
    if (it == hash_table.end()) {
        cout << "Key NOT found.\n";
        return;
    }

    list<string> &bucket = it->second;

    for (auto list_it = bucket.begin(); list_it != bucket.end(); ++list_it) {
    if (*list_it == target) {
        bucket.erase(list_it);
        cout << "Key removed successfully from hash index " << hash_index << "!\n";
        return;
        }
    }

    cout << "Key NOT found.\n";
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
  
int choice = 0;
    
    while (choice != 6) {
        cout << "\n Hash Table Menu \n";
        cout << "1. Print first 100 entries\n";
        cout << "2. Search for a key\n";
        cout << "3. Add a key\n";
        cout << "4. Remove a key\n";
        cout << "5. Modify a key\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            print_first_100(hash_table);
        }
        else if (choice == 2) {
            search_key(hash_table);
        }
        else if (choice == 3) {
            add_key(hash_table);
        }
        else if (choice == 4) {
            remove_key(hash_table);
        }
        else if (choice == 6) {
            cout << "Exiting...\n";
        }
        else {
            cout << "Feature not established yet.\n";
        }
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
