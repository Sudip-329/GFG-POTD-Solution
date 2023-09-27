//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        // code here
       /* vector<int>ans;
        unordered_map<int,int> map;
        for(int i=0; i<n; i++)
        {
            map[arr[i]]++;
        }
        for(auto i : map)
        {
            if(i.second >=2)
            {
                ans.push_back(i.first);
            }
        }
        if(ans.size()>=1)
        {
            sort(ans.begin(), ans.end());
            return ans;
        }
        else{
            ans.push_back(-1);
            return ans;
        }*/
        
        
        // 2nd method
        
        vector<int>ans;
        int freq[n] = {0};
        for(int i=0;i<n;i++){
            freq[arr[i]]++;
        }
        for(int i=0; i<n; i++)
        {
            if(freq[i] > 1)
            {
                ans.push_back(i);
            }
        }
        if(ans.empty())
        {
            ans.push_back(-1);
        }
        return ans;

    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends