//  Double-Ended Queue: add and remove the data to and from both end.

#include <bits/stdc++.h>
using namespace std;

void display(deque<int> dq){
    deque<int> temp = dq;
    while(temp.size()!=0){
        cout << temp.front() << " ";
        temp.pop_front();
    }
}

int main(){
    deque<int> dq;
    
    // Enqueue or Pushing elements in a Queue
    dq.push_back(1);
    dq.emplace_back(2); // faster than pushback

    dq.push_front(3);
    dq.emplace_front(4);

    // Inserting with help of array
    vector<int> v = {15,22,11,7};
    for(int ele : v){
        dq.push_back(ele);
    }

    // Displaying Dequeue
    cout << "\nDequeue: ";
    display(dq);
    cout << "\nSize of Dequeue: " << dq.size();

    // Dequeue or Popping elements
    cout << "\nUpdated Dequeue: ";
    dq.pop_back();
    dq.pop_front();
    display(dq);

    cout << "\nSize of dequeue: " << dq.size();
    
    // rest functions same as vectors
}