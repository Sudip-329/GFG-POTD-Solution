//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    char nonrepeatingCharacter(string S) {
        int cnt[26] = {0};

        for (auto ch : S) {
            cout<<cnt[ch - 'a']++<<endl;
        }

        for (auto ch : S) {
            if (cnt[ch - 'a'] == 1) {
                return ch;
            }
        }

        return '$';
    }
};

//{ Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--)
	{
	
	    string S;
	    cin >> S;
	    Solution obj;
        char ans = obj.nonrepeatingCharacter(S);
        
        if(ans != '$')
	    cout << ans;
        else cout << "-1";
            
        cout << endl;
	    
	}
	
	return 0;
}

// } Driver Code Ends