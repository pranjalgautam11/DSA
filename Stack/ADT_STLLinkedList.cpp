#include <iostream>
#include <list>
using namespace std;

int peek(list<int> s, int index) {
    if (index < 0 || index >= s.size()) return -1;
    auto it = s.begin();
    advance(it, index);
    return *it;
}

void display(list<int> s) {
    for (int x : s) cout << x << " ";
    cout << endl;
}

int isFull(list<int> s, int max){
    if(s.size()==max) return 1;
    else return 0;
}

int main() {
    list<int> stackList;
    // PUSHING ELEMENTS
    int n;
    cout << "Enter number of elements in stack: ";
    cin >> n;
    int val;
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> val;
        stackList.push_front(val);
    }

    // CHECK IF EMPTY
    cout << "\nIs stack empty? " << (stackList.empty() ? "YES" : "NO") << endl;

    // CHECK IF FULL
    cout << "\nIs stack full? " << (isFull(stackList, n) ? "YES" : "NO") << endl;

    // TOP ELEMENT
    if (stackList.empty()) cout << "\nTop element of stack: " << stackList.front() << endl;

    // PEEK ELEMENT
    int p;
    cout << "\nEnter index to peek: ";
    cin >> p;
    cout << "Element at index " << p << " : " << peek(stackList,p) << endl;

    // DISPLAYING STACK ELEMENTS
    cout << "\nStack elements:\n";
    display(stackList);

    // POPPING
    if (!stackList.empty()) {
        stackList.pop_front();
        stackList.pop_front();
    }

    cout << "\nStack elements after popping twice:\n";
    display(stackList);
}
