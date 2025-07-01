#include <iostream>
using namespace std;

int Hash(int key, int size){
    return key%size;
}

int prob(int H[],int key, int size){
    int index = Hash(key,size);
    int i=0;
    while(H[index+i]%size!=0)
        i++;
    
    return (index+i)%size;
}
void insert(int H[], int key, int size){
    int index = Hash(key,size);
    if(H[index]!=0)
        index = prob(H,key,size);
    H[index] = key;
}

int Search(int H[], int key, int size) {
    int index = Hash(key, size);
    int i = 0;
    while (H[(index + i) % size] != key) {
        if (H[(index + i) % size] == 0) {
            return -1;  // Key not found
        }
        i++;
    }
    return (index + i) % size;
}

int main(){
    int size;
    cout << "Enter the size of Hash Table: ";
    cin >> size;

    int HT[size] = {0};

    insert(HT,10,size);
    insert(HT,15,size);
    insert(HT,19,size);
    insert(HT,25,size);
    insert(HT,13,size);

    int keyToSearch;
    cout << "Enter key to be searched: ";
    cin >> keyToSearch;
    int searchResult = Search(HT, keyToSearch, size);
    if (searchResult != -1)
        cout << "Key " << keyToSearch << " found at index: " << searchResult << endl;
    else
        cout << "Key " << keyToSearch << " not found in the hash table." << endl;
}