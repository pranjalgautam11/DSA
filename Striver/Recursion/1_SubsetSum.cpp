#include <iostream>
#include <vector>
using namespace std;

vector<int> Subsetsum(vector<int> &arr, int index, int sum) {
    if(index == arr.size()) {
        return {sum};
    }

    // Exclude the current element (Not picking the element)
    vector<int> exclude = Subsetsum(arr, index + 1, sum);

    // Include the current element (Picking the element and adding to sum)
    vector<int> include = Subsetsum(arr, index + 1, sum + arr[index]);

    // Combine both results (Position, itr at first elem, itr at last elem)
    exclude.insert(exclude.end(), include.begin(), include.end());

    return exclude;
}

int main() {
    vector<int> Numbers = {1, 2, 3};
    vector<int> result = Subsetsum(Numbers, 0, 0);

    cout << "Subset sums: ";
    for(int sum : result) {
        cout << sum << " ";
    }
    cout << endl;

    return 0;
}
