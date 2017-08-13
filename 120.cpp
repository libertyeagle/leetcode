class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		vector<vector<int>> dp(triangle.size(), vector<int>(triangle[triangle.size()-1].size(),0));
		dp[0][0]=triangle[0][0];
		for (int i=1; i<triangle.size(); ++i)
		 for (int j=0; j<i+1; ++j)
		  if (j==0) dp[i][j]=dp[i-1][j]+triangle[i][j];
		  else if (j==i) dp[i][j]=dp[i-1][j-1]+triangle[i][j];
		  else dp[i][j]=min(dp[i-1][j-1]+triangle[i][j],dp[i-1][j]+triangle[i][j]);
		int minLength=INT_MAX;
		for (int j=0; j<triangle.size(); j++)
		 if (dp[triangle.size()-1][j]<minLength) minLength=dp[triangle.size()-1][j];
		return minLength;
	}
};