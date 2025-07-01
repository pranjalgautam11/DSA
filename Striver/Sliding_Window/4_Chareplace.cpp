#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int LongestRepeatingCharReplacement(string s, int k){
    int l=0, r=0, maxlen=0, maxfreq=0;
    int Hash[26] = {0};

    while(r<s.length()){
        Hash[s[r] - 'A']++;
        maxfreq = max(maxfreq, Hash[s[r]-'A']);

        int len = r-l+1;

        if(len-maxfreq>k){
            Hash[s[l]-'A']--;
            l++;
        }
        else // (len-maxfreq <= k) condition
            maxlen = max(maxlen,len);
        r++;
    }
    return maxlen;
}

int main(){
    int n; string s;
    cout << "Enter the String and number of replacement allowed: ";
    cin >> s >> n;
    cout << "Longest Repeating Character Sequence is of length: " << LongestRepeatingCharReplacement(s,n);
}