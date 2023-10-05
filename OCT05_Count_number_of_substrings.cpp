//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    long long int upto(string s, int k){
        int l=0,r=0,cnt=0;
        long long int ans=0;
        vector<int> vec(26,0);
        while(r<s.length()){
            vec[s[r]-'a']++;
            if(vec[s[r]-'a'] == 1) cnt++;
            while(cnt>k){
                vec[s[l]-'a']--;
                if(vec[s[l]-'a']<=0){
                    cnt--;
                }
                l++;
            }
            ans+=(r-l+1);
            r++;
        }
        return ans;
        
    }
    long long int substrCount (string s, int k) {
        return upto(s,k)-upto(s,k-1);
    }
};

//{ Driver Code Starts.


int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		int k; cin >> k;
		Solution ob;
		cout <<ob.substrCount (s, k) << endl;
	}
}
// } Driver Code Ends