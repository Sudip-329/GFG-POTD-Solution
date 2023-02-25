//{ Driver Code Starts
import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader read =
            new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            String S[] = read.readLine().split(" ");
            
            int n = Integer.parseInt(S[0]);
            int m = Integer.parseInt(S[1]);
            
            int [][] grid = new int[n][m];
            for(int i=0; i<n; i++)
            {
                String S1[] = read.readLine().split(" ");
                for(int j=0; j<m; j++)
                {
                    grid[i][j] = Integer.parseInt(S1[j]);
                }
            }

            Solution ob = new Solution();
            System.out.println(ob.uniquePaths(n,m,grid));
        }
    }
}
// } Driver Code Ends


//User function Template for Java

class Solution {
    static int uniquePaths(int n, int m, int[][] grid) {
        // code here
        if(grid[0][0] == 0) return 0;
        if(grid[n-1][m-1]==0) return 0;
        Integer[][] dp = new Integer[n][m];
        return solution(0,0,grid,dp);
    }
    private static int solution(int i,int j, int[][] grid, Integer[][] dp){
        if(i == grid.length-1 && j== grid[0].length-1) return 1;
        if(i>=grid.length || j>= grid[0].length) return 0;
        if(grid [i][j]==0) return 0;
        if(dp[i][j] != null) return dp[i][j];
        int right = solution(i+1,j,grid,dp);
        int down = solution(i,j+1,grid,dp);
        return dp[i][j]=(right%1000000007 + down%1000000007)%1000000007;
        
    }
};