//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    int findMinOpeartion(vector<vector<int> > matrix, int n)           //test case
    {                                                                    //N = 2
        int rowsum[n]={0};                                              //matrix[][] = {{1, 2},
        int colsum[n]={0};                                              //              {3, 4}}
        int maxsum=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                rowsum[i]+=matrix[i][j];
                colsum[i]+=matrix[j][i];
            }
            maxsum=max(maxsum,max(rowsum[i],colsum[i]));
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=maxsum-rowsum[i];
        }
        return ans;
    } 
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}


// } Driver Code Ends