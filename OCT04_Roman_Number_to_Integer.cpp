




// ex : XV = x=10 + v=5         ans : 15
// ex : XLIV = x=10 l = 50 i=1 v=5   x<l so subtract and i<v so subtract
/*   -10+50-1+5 = 44 (ans : 44)
   ex : XXIII  x=10 i=1
       now here equal values are present so normally add them
       10+10+1+1+1 = 23(ans)    x is not smaller than i so no need to subtract

    ex : DCXL d=500 c=100 x=10 l = 50  d>c okk ,c>x okk, but x<l so,subtract x
*/

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
    public:
        int romanToDecimal(string &s){
            unordered_map<char, int> mp = { { 'I' , 1 },
                           { 'V' , 5 },
                           { 'X' , 10 },
                           { 'L' , 50 },
                           { 'C' , 100 },
                           { 'D' , 500 },
                           { 'M' , 1000 } };

            int sum = mp[s.back()];  //it is adding the last character as we are not
            // adding the last element in the for loop.
            for(int i=0; i<s.length()-1; i++)
            {
                if(mp[s[i]] < mp[s[i+1]])
                {
                    sum -= mp[s[i]];
                }
                else
                {
                    sum +=mp[s[i]];
                }
            }
            return sum;
        }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends