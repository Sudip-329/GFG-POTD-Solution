//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

/*class Solution {
private:
    vector<string> primes;
    bool computed = false; // Initialize computed to false
    
public:
    void sieve() {
        const int n = 9999;
        vector<bool> prime(n + 1, true); // Initialize all as prime
        prime[0] = prime[1] = false; // 0 and 1 are not prime
    
        for(int i = 2; i <= n; i++) {
            if(prime[i]) {
                for(int j = i * i; j <= n; j += i)
                    prime[j] = false;
            }
        }
    
        for(int i = 1000; i <= n; i++) { // Corrected boundary check
            if(prime[i])
                primes.push_back(to_string(i));
        }
        
        computed = true; // Update computed to true after sieve completion
    }
    
    int solve(int num1, int num2) { // Corrected variable names to follow naming conventions
        if(num1 == num2)
            return 0;
            
        if(!computed)
            sieve();
        
        const int inf = 1e9;
        
        map<string, int> d;
        for(auto& prime : primes)
            d[prime] = inf;
            
        string start = to_string(num1);
        string end = to_string(num2);
            
        d[start] = 0;
        queue<string> q;
        q.push(start);
        
        while(!q.empty()) {
            string cur = q.front();
            q.pop();
            
            for(int i = 0; i < 4; i++) {
                for(char j = (i == 0 ? '1' : '0'); j <= '9'; j++) {
                    if(j != cur[i]) {
                        string next = cur;
                        next[i] = j;
                        
                        auto it = d.find(next);
                        if(it != d.end() && it->second > d[cur] + 1) {
                            it->second = d[cur] + 1;
                            q.push(next);
                            
                            if(next == end)
                                return d[next];
                        }
                    }
                }
            }
        }
        
        return -1;
    }
};
*/

class Solution{   
public:
    int solve(int num1,int num2)
    {   
      //code here
      vector<int> prime(10000,1);   //1000<=num1,num2<=9999
      for(int i=2;i*i<10000;i++){
          if(prime[i]){
              for(int j=2*i;j<10000;j+=i) prime[j]=0;
          }
      }
      unordered_set<int>st;
      for(int i=1000;i<10000;i++) if(prime[i]) st.insert(i);
      
      queue<pair<int,int>> q;
      q.push({0,num1});
      while(!q.empty()){
          int dist=q.front().first;
          int n=q.front().second;
          q.pop();
          if(n==num2) return dist;
          string num=to_string(n);
          for(int i=0;i<4;i++){
              for(int j=0;j<=9;j++){
                  char c=num[i];
                  num[i]=('0'+j);
                  int t=stoi(num);
                  if(st.find(t)!=st.end()){
                      st.erase(t);
                      if(t==num2) return dist+1;
                      q.push({dist+1,t});
                  }
                  num[i]=c;
              }
          }
      }
      return -1;
    }
};


//{ Driver Code Starts.
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
      int num1,num2;
      cin>>num1>>num2;
      Solution obj;
      int answer=obj.solve(num1,num2);
      cout<<answer<<endl;
  }
}
// } Driver Code Ends