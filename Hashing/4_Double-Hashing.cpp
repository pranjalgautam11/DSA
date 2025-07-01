#include <iostream>
using namespace std;

// Primary hash function
int Hash(int key, int size) {
    return key % size;
}

// Secondary hash function
int Hash2(int key) {
    return 7 - (key % 7); // A common choice for Hash2 is to use a prime number less than the size of the table
}

void insert(int H[], int key, int size) {
    int index = Hash(key, size);
    int index2 = Hash2(key);
    int i = 0;
    while (H[(index + i * index2) % size] != 0) {
        i++;
    }
    H[(index + i * index2) % size] = key;
}

int Search(int H[], int key, int size) {
    int index = Hash(key, size);
    int index2 = Hash2(key);
    int i = 0;
    while (H[(index + i * index2) % size] != key) {
        if (H[(index + i * index2) % size] == 0) {
            return -1;  // Key not found
        }
        i++;
        if (i == size) {
            return -1;  // Full table scan completed
        }
    }
    return (index + i * index2) % size;
}

int main() {
    int size;
    cout << "Enter the size of Hash Table: ";
    cin >> size;

    int HT[size] = {0};  // Initialize hash table with zeros

    insert(HT, 10, size);
    insert(HT, 15, size);
    insert(HT, 19, size);
    insert(HT, 25, size);
    insert(HT, 13, size);

    int keyToSearch;
    cout << "Enter key to be searched: ";
    cin >> keyToSearch;
    int searchResult = Search(HT, keyToSearch, size);
    if (searchResult != -1)
        cout << "Key " << keyToSearch << " found at index: " << searchResult << endl;
    else
        cout << "Key " << keyToSearch << " not found in the hash table." << endl;

    return 0;
}
