#include <bits/stdc++.h>
using namespace std;

struct meeting {
   int start;
   int end;
   int pos;
};

class nMeetingsInOneRoom {
   public:
      bool static comparator(struct meeting m1, meeting m2) { // sort based on end time, e
         if (m1.end < m2.end) return true;
         else if (m1.end > m2.end) return false;
         else if (m1.pos < m2.pos) return true;
         return false;
      }
      void maxMeetings(int s[], int e[], int n) {
        struct meeting meet[n];
        for (int i = 0; i < n; i++) meet[i].start = s[i], meet[i].end = e[i], meet[i].pos = i + 1;
        sort(meet, meet + n, comparator);
        vector<int> answer;
        int endTime = meet[0].end;
        answer.push_back(meet[0].pos);
        for (int i = 1; i < n; i++) {
            if (meet[i].start > endTime) {
                endTime = meet[i].end;
                answer.push_back(meet[i].pos);
            }
        }
        cout<<"The order in which the meetings will be performed is "<< endl;
        for (int i = 0; i < answer.size(); i++) cout << answer[i] << " ";
      }
};

int main() {
   nMeetingsInOneRoom m;
   int n = 6;
   int start[] = {1,3,0,5,8,5};
   int end[] =   {2,4,5,7,9,9};
   m.maxMeetings(start, end, n);
   return 0;
}