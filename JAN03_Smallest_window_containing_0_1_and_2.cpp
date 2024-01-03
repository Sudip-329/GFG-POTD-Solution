//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
/*
  TLE - 1065
class Solution{
    public:
    int smallestSubstring(string S) {
        unordered_map<char,int>map;
        int ans = INT_MAX;
        int size = S.size();
        int st =0;
        for(int end=0; end<size; end++)   //start
        {
            map[S[end]]++;
            
            if(map.size()==3)
            {
                while(st<end && map[S[st] ]> 1){
                    map[S[st]]--;
                    st++;
                }
                ans = min(ans,end-st+1);
            }
            
        }
        return ans==INT_MAX? -1 : ans;
    }
};
*/

class Solution {
public:
    int smallestSubstring(string S) {
        int zero = -1, one = -1, two = -1, res = 100001;

        for (int i = 0; i < S.length(); i++) {
            if (S[i] == '0') zero = i;
            if (S[i] == '1') one = i;
            if (S[i] == '2') two = i;

            if (zero == -1 || one == -1 || two == -1)
            { 
                continue; //says to start the next iteration without executing
                          // below commands
            }
            int minimum = min({one, zero, two});
            int maximum = max({one, zero, two});
            res = min(res, maximum - minimum + 1);
        }

        return res == 100001 ? -1 : res;
    }
};




//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.smallestSubstring(S);
        cout << endl;
    }
}
// } Driver Code Ends