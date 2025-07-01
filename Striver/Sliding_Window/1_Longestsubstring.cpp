#include <iostream>
using namespace std;

int main()
{
    int l = 0, r = 0, maxlen = 0, len = 0;
    string s;
    cout << "Enter the String: ";
    cin >> s;
    int Hash[256] = {-1};
    while (r < s.length()){
        if (Hash[s[r]] != -1){
            if (Hash[s[r]] >= l)
                l = Hash[s[r]] + 1;
        }
        len = r - l + 1;
        maxlen = max(maxlen, len);
        Hash[s[r]] = r;
        r++;
    }
    cout << "The longest Substring length is: " << maxlen;
}