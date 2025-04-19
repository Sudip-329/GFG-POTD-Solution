class Solution {
    public int countWaystoDivide(int N, int K) {
        // Code here
        Integer[][][] dp=new Integer[N+1][N+1][K+1];
    return solve(1,0,K,N,dp);
    }
    public int solve(int index,int sum,int k,int n,Integer[][][] dp){
       if(sum>n) return 0;
        if(k==0 && sum == n) return 1;
        if(k==0&&sum!=n)return 0;
        if(dp[index][sum][k]!=null) return dp[index][sum][k];
        int count=0;
        for(int i=index;i<=n;i++){
            count+=solve(i,sum+i,k-1,n,dp);
        }
        dp[index][sum][k]=count;
        return count;
    }
}