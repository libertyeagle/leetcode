class Solution {
public:
	int longestIncreasingPath(vector<vector<int>>& matrix) {
		if (matrix.size()==0) return 0;
		vector<vector<int>> pathRec(matrix.size(),vector<int>(matrix[0].size(),0));
		vector<vector<bool>> visited(matrix.size(),vector<bool>(matrix[0].size(),false));
		for (int i=0; i<matrix.size(); ++i)
			for (int j=0; j<matrix[0].size(); ++j)
				dfs(matrix, i, j, pathRec, visited);
		return maxPath;
	}
private:
	vector<vector<int>> dir{{1,0},{-1,0},{0,1},{0,-1}};
	int maxPath=1;
	void dfs(vector<vector<int>>& matrix ,int i, int j, vector<vector<int>>& pathRec, vector<vector<bool>>& visited)
	{
		if (pathRec[i][j]) return;
		else pathRec[i][j]=1;
		visited[i][j]=true;
		for (auto delta : dir)
		{
			int newi=i+delta[0], newj=j+delta[1];
			if ((newi<0) || (newi>=matrix.size()) || (newj<0) || (newj>=matrix[0].size()) || visited[newi][newj]) continue;
			if (matrix[newi][newj]>matrix[i][j]) 
			{
				 dfs(matrix, newi, newj, pathRec, visited);
				pathRec[i][j]=max(pathRec[i][j], pathRec[newi][newj]+1);
				if (pathRec[i][j]>maxPath) maxPath=pathRec[i][j];
			}
		}
		visited[i][j]=false;
	}
};