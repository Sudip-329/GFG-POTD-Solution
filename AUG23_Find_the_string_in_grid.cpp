/*class Solution   //1st method
{
public:
    bool isfound(int row, int col, vector<vector<char>> &grid, string word)
    {
        // Code here
        int n, m, nrow = row, ncol = col, j;
        n = grid.size();
        m = grid[0].size();
        j = 1;
        while (j < word.length())
        {
            // left side of row
            if (ncol - j >= 0 && grid[nrow][ncol - j] == word[j])
            {
                j++;
                if (j == word.length())
                    return true;
            }
            else
                break;
        }
        j = 1;
        while (j < word.length())
        {
            // right side of row
            if (ncol + j < m && grid[nrow][ncol + j] == word[j])
            {

                j++;
                if (j == word.length())
                    return true;
            }
            else
                break;
        }
        j = 1;
        while (j < word.length())
        {
            // up side of col
            if (nrow - j >= 0 && grid[nrow - j][ncol] == word[j])
            {

                j++;
                if (j == word.length())
                    return true;
            }
            else
                break;
        }
        j = 1;
        while (j < word.length())
        {
            if (nrow + j < n && grid[nrow + j][ncol] == word[j])
            {

                j++;
                if (j == word.length())
                    return true;
            }
            else
                break;
        }
        j = 1;
        while (j < word.length())
        {

            if (ncol - j >= 0 && nrow - j >= 0 && grid[nrow - j][ncol - j] == word[j])
            {

                j++;
                if (j == word.length())
                    return true;
            }
            else
                break;
        }
        j = 1;
        while (j < word.length())
        {

            if (ncol - j >= 0 && nrow - j >= 0 && grid[nrow - j][ncol - j] == word[j])
            {

                j++;
                if (j == word.length())
                    return true;
            }
            else
                break;
        }
        j = 1;
        while (j < word.length())
        {

            if (ncol + j < m && nrow + j < n && grid[nrow + j][ncol + j] == word[j])
            {

                j++;
                if (j == word.length())
                    return true;
            }
            else
                break;
        }
        j = 1;
        while (j < word.length())
        {
            if (ncol - j >= 0 && nrow + j < n && grid[nrow + j][ncol - j] == word[j])
            {

                j++;
                if (j == word.length())
                    return true;
            }
            else
                break;
        }
        j = 1;

        while (j < word.length())
        {
            if (ncol + j < m && nrow - j >= 0 && grid[nrow - j][ncol + j] == word[j])
            {

                j++;
                if (j == word.length())
                    return true;
            }
            else
                break;
        }

        return false;
    }
    vector<vector<int>> searchWord(vector<vector<char>> grid, string word)
    {
        // Code here
        vector<vector<int>> ans;
        int row, col, len;
        row = grid.size();
        col = grid[0].size();
        len = word.length();
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (word[0] == grid[i][j])
                {
                    if (len==1 || isfound(i, j, grid, word))
                    {
                        ans.push_back({i, j});
                    }
                }
            }
        }
        return ans;
    }
};
*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    int dx[] = { -1 , 1 ,  0  , 0 , -1  , -1  ,  1  , 1  };
        int dy[] = { 0  , 0 , -1  , 1 , -1  ,  1  , -1  , 1  };
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> ans;
        
        auto valid = [&](int x, int y, int p) -> bool {
            if(x < 0 or x >= n or y < 0 or y >= m)
                return 0;
            
            return grid[x][y] == word[p];
        };
        
        function<bool(int, int, int, int)> helper = [&](int x, int y, int dir, int p) -> bool {
            if(p == word.size() - 1)
                return 1;
                
            if(valid(x + dx[dir], y + dy[dir], p + 1))
                return helper(x + dx[dir], y + dy[dir], dir, p + 1);
                
            return 0;
        };
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                for(int k = 0; k < 8; k++){
                    if(valid(i, j, 0) and helper(i, j, k, 0)){
                        vector<int> t = {i, j};
                        ans.push_back(t);
                        break;
                    }
                }
            }
        }
        
        sort(ans.begin(), ans.end());
        
        return ans;
	}
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	}
	return 0;
}
// } Driver Code Ends


