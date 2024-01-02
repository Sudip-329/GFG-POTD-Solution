//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

/*class Solution
{
    public:
    //Function to check if two strings are rotations of each other or not.
    bool areRotations(string s1,string s2)
    {
        // Your code here
        string s = s1+s2;
        if(s.find(s2) != -1)
        {
            return 1;
        }
        return 0;
    }
};*/

class Solution
{
    public:
    //Function to check if two strings are rotations of each other or not.
    bool areRotations(const std::string& s1, const std::string& s2) {
    // Check if both strings are of equal length
    if (s1.length() != s2.length()) {
        return false;
    }

    // Concatenate s1 with itself
    std::string s1s1 = s1 + s1;

    // Check if s2 is a substring of s1s1
    if (s1s1.find(s2) != std::string::npos) {
        return true;
    } else {
        return false;
    }
}
};

// } Driver Code Ends
//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s1;
        string s2;
        cin>>s1>>s2;
        Solution obj;
        cout<<obj.areRotations(s1,s2)<<endl;

    }
    return 0;
}

// } Driver Code Ends