//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    void help(string str,vector<string>& ans, int freq[], string S ){
        if(str.size()== S.size()){
            ans.push_back(str);
            return;
        }
        
        for(int i=0;i<S.size();i++){
            if(!freq[i]){
                str.push_back(S[i]);
                freq[i]=1;
                help(str,ans,freq,S);
                freq[i]=0;
                str.pop_back();
            }
        }
    }
    
    vector<string> permutation(string S)
    {
        int n=S.size();
        vector<string> ans;
        int freq[n];
        for(int i=0;i<n;i++) freq[i]=0;
        help("",ans,freq,S);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends