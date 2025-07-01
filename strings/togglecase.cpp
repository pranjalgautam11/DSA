#include <iostream>
#include <string>
using namespace std;
int main(){

    string name = "Bhavu";

    for(int i=0; i < name.length(); i++){
        char c = name[i];
        if(islower(c))
            name[i] = toupper(name[i]);
        else if(isupper(c))
            name[i] = tolower(name[i]);
    }
    cout << name << endl;
}