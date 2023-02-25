//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int checkCompressed(string s, string t) {
        int j = 0;
        string num = "";//empty string
        for(int i=0; i<t.size(); i++)
        {
            if(t[i] - '0' >= 0 && t[i] - '0' <= 9)
            {
                num+= t[i];
                if(t[i+1] - '0' >= 0 && t[i+1] <= '9')
                {
                    continue;
                }
                else
                {
                    j+= stoi(num);
                    num = "";
                }
            }
            else
            {
                if(t[i] != s[j])
                    return 0;
                j++;
            }
            if(j > s.size())
                return 0;
        }
        return 1;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S,T;
        
        cin>>S>>T;

        Solution ob;
        cout << ob.checkCompressed(S,T) << endl;
    }
    return 0;
}
// } Driver Code Ends