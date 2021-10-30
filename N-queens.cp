// 51. N-Queens leetcode solution

class Solution {
public:
    vector<vector<string>> ans;
    vector<vector<string>> solveNQueens(int n) {
        vector<string>v(n,string(n,'.'));
        solve(0,n,v);
        return ans;
    }
    
    void solve(int index,int n,vector<string>&v)
    {
        if(index==n)
        {
            ans.push_back(v);
            return;
        }
        for(int j=0;j<n;j++)
        {
            if(isvalid(index,j,n,v))
            {
                v[index][j] = 'Q';
                solve(index+1,n,v);
                v[index][j] = '.';
            }
        }
    }
    
    bool isvalid(int x,int y,int n,vector<string>&v)
    {
        for(int i=0;i<n;i++)
        {
            if(v[i][y]=='Q'||v[x][i]=='Q')
            {
                return false;
            }
        }
        //
        for(int i=x,j=y;i>=0&&j>=0;i--,j--)
        {
            if(v[i][j]=='Q')
            {
                return false;
            }
        }
        for(int i=x,j=y;i<n&&j>=0;i++,j--)
        {
            if(v[i][j]=='Q')
            {
                return false;
            }
        }
        for(int i=x,j=y;i>=0&&j<n;i--,j++)
        {
            if(v[i][j]=='Q')
            {
                return false;
            }
        }
        for(int i=x,j=y;i<n&&j<n;i++,j++)
        {
            if(v[i][j]=='Q')
            {
                return false;
            }
        }
        return true;
    }
};
