//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
class Solution{
  public:
    /*You are required to complete below function */
    string multiplyStrings(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        string ans(n+m,'0'); //taking a string of length m+n and initializing it with 0,
        bool isS1Negative = false;
        bool isS2Negative = false;
        
        if(s1[0] == '-') {   //strings are negative or not
            isS1Negative = true;
            s1[0] = '0';
        }
        
        if(s2[0] == '-') {
            isS2Negative = true;
            s2[0] = '0';
        }
        
        
        for(int i = n - 1; i>=0; i--){
            for(int j = m - 1; j >= 0; j--){
                int p = (s1[i] - '0') * (s2[j] - '0') + (ans[i + j + 1] - '0');
                //string s="800";  cout<<s[0]-'0';  ans: 8
                //ans[i+j+1] - '0' it is for the carry
                ans[i+j+1] = p % 10 + '0';
                ans[i+j] += p / 10 ;
            }
        }

        for(int i=0;i<n+m;i++){
            if(ans[i] != '0') {
                ans = ans.substr(i);
                break;
            }
        }
        if (isS1Negative && isS2Negative) {
            return ans;
        }
        else if(isS1Negative || isS2Negative) {
            reverse(ans.begin(),ans.end());
            ans += "-";
            reverse(ans.begin(),ans.end());
            return ans;
        } else if (!isS1Negative && !isS2Negative) {
            return ans;
        }
        return "0";
    }

};

//{ Driver Code Starts.
 
int main() {
     
    int t;
    cin>>t;
    while(t--)
    {
    	string a;
    	string b;
    	cin>>a>>b;
    	Solution obj;
    	cout<<obj.multiplyStrings(a,b)<<endl;
    }
     
}
// } Driver Code Ends