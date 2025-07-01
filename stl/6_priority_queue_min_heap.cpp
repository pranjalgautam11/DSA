/*
    Priority Queue:  STL Priority Queue does not follow any of the FIFO or LIFO principle, 
    but the deletion of elements is done on the basis of its priority. So, the element with the highest 
    (by default) is always removed first. It uses vector as underlying container.
*/

#include <bits/stdc++.h>
using namespace std;

void display(priority_queue<int> pq){
    priority_queue<int> temp = pq;
    while(temp.size()!=0){
        cout << temp.top() << " ";
        temp.pop();
    }
}

void displayminimumheap(priority_queue<int, vector<int>, greater<int>> pq1){
    priority_queue<int, vector<int>, greater<int>> temp = pq1;
    while(temp.size()!=0){
        cout << temp.top() << " ";
        temp.pop();
    }
}

int main(){
    priority_queue<int> pq;

    // Inserting Element
    pq.push(5);
    pq.push(1);
    pq.push(10);
    pq.emplace(7);

    cout << "Top element in Priority Queue: " << pq.top() << endl;
    cout << "Size of Priority Queue: " << pq.size() << endl;
    
    // Displaying Priority Queue
    cout << "\nPriority Queue\n";
    display(pq);
    
    // Popping the element
    cout << "\nPriority Queue after popping\n";
    pq.pop();
    display(pq);

    // <---MINIMUM HEAP--->

    priority_queue<int, vector<int>, greater<int>> pq1; // declaring minimum heap with help of greater

    // Inserting Element
    pq1.push(5);
    pq1.push(1);
    pq1.push(10);
    pq1.emplace(7);

    cout << "\n\nTop element in Minimum Heap: " << pq1.top() << endl;
    cout << "Size of Minimum Heap: " << pq1.size() << endl;
    
    // Displaying Minimum Heap
    cout << "\nMinimum Heap\n";
    displayminimumheap(pq1);
    
    // Popping the element
    cout << "\nMinimum Heap after popping\n";
    pq1.pop();
    displayminimumheap(pq1);
}