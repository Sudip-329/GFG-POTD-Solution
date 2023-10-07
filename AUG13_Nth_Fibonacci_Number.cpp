//  >> CPP CODE <<

class Solution {
  public:
    int nthFibonacci(int n){
        if(n==0) return 0;
        int mod=1e9+7;
        
        int a=0,b=1;
        
        n-=2;
        
        while(n-->=0)
        {
            int c=(a%mod+b%mod)%mod;
            a=b;
            b=c;
        }
        
            return b;
    }
};


class Solution {
  public:
    int nthFibonacci(int n){
        int x, y;
        x = y = 1;
        
        const int mod = 1e9 + 7;
            
        for(int i = 3; i < n + 1; i++){
            x = (x + y) % mod;
            swap(x, y);
        }
        
        return y;
    }
};