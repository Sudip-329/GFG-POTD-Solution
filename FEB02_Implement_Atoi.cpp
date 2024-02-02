//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    //You are required to complete this method 
    int atoi(string s) {
        //Your code here
        int n = s.size();
        int count = 0;
        int flag = 0;
        
        for(int i=0; i<n; i++)
        {
            if(s[i]=='-')
            {
                flag=1;
                i++;
            }
            if(s[i]!='-' and (s[i]>='0' && s[i]<='9'))
            {
                count*=10;
                count+= s[i]-'0';
                //cout<<count<<"here";
                
            }
            else{
                return -1;
            }
        }
        if(flag == 1)
        {
           return count*= (-1);
        }
        else{
            return count;
        }
        
    }
};
/*
class Solution{
  public:
    /*You are required to complete this method 
    int atoi(string s) {
        int index = 0;
        int ans = 0;
        bool neg = 0;
        
        if(s[index] == '-'){
            neg = 1;
            ++index;
        }
        
        
        for(; index < s.size(); index++){
            if(isdigit(s[index])){
                ans *= 10;
                ans += (s[index] - '0');
            }
            else{
                return -1;
            }
        }
        
        return ans * (neg ? -1 : 1);
    }
};*/

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends