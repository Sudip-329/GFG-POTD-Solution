/*string reverseWord(string str)
{
    // Your code goes here
    reverse(str.begin(),str.end());
    return str;
}*/


//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    string reverseWord(string str)
    {
        int len = str.length();
        int n = len-1;
        int i = 0;
        while(i<=n){
            swap(str[i],str[n]);
            n--;
            i++;
        }   
        return str;
    }
};



//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
    	string s;
    	cin >> s;
    	Solution ob;
    	cout << ob.reverseWord(s) << endl;
	}
	return 0;
	
}


// } Driver Code Ends