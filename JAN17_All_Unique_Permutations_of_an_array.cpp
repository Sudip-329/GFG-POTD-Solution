//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        // code here
        vector<vector<int>>ans;  //need to return a vector
        set<vector<int>>s;   //storing a full arr.
        sort(arr.begin(), arr.end());
        s.insert(arr);
        while(next_permutation(arr.begin(),arr.end())){  //it genarates next permutation.
            s.insert(arr);
        }
        for(auto x : s)
        {
            ans.push_back(x);
        }
        return ans;
    }
};

/*Sorting the array: Sorting a vector of size n has a time complexity of O(n log n).
Generating permutations using next_permutation: In the worst case, this involves generating
all possible permutations of the sorted array. There are n! (factorial) permutations for an 
array of size n. The next_permutation function takes O(n) time for each permutation in average 
case, so the overall time complexity for generating all permutations is O(n * n!).
Therefore, the overall time complexity of the given code is O(n log n + n * n!),*/

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;
        vector<int> arr(n);
        
        for(int i=0 ; i<n ; i++)
            cin>>arr[i];

        Solution ob;
        vector<vector<int>> res = ob.uniquePerms(arr,n);
        for(int i=0; i<res.size(); i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<res[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends