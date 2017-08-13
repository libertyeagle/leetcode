class Solution {
public:
	struct Cell {
		pair<int,int> pos;
		int height;
		Cell(pair<int, int> pos, int h)
		{
			this->pos=pos;
			this->height=h;
		}
	    bool operator < (const Cell &g) const {
			return height < g.height;
	    }
	    bool operator > (const Cell &g) const {
			return height > g.height;
	    }
	};
	
	int trapRainWater(vector<vector<int>>& heightMap) {
		if (heightMap.size()==0) return 0;
		auto row=heightMap.size(), col=heightMap[0].size();
		priority_queue<Cell, vector<Cell>,greater<Cell>> pendingQueue;
		vector<vector<bool>> visited(row,vector<bool>(col,false));
		for (int i=0; i<row; ++i)
		{
			visited[i][0]=true;
			visited[i][col-1]=true;
			pendingQueue.push(Cell(make_pair(i,0),heightMap[i][0]));
			pendingQueue.push(Cell(make_pair(i,col-1),heightMap[i][col-1]));
		}
		for (int j=1; j<col-1; ++j)
		{
			visited[0][j]=true;
			visited[row-1][j]=true;
			pendingQueue.push(Cell(make_pair(0,j),heightMap[0][j]));
			pendingQueue.push(Cell(make_pair(row-1,j),heightMap[row-1][j]));
		}
		vector<vector<int>> dir{{1,0},{-1,0},{0,1},{0,-1}};
		int sum=0;
		while (!pendingQueue.empty())
		{
			auto item=pendingQueue.top();
			pendingQueue.pop();
			int x=item.pos.first, y=item.pos.second, curHeight=item.height;
			for (auto delta:dir)
			{
				int deltaX=delta[0];
				int deltaY=delta[1];
				int newX=x+deltaX;
				int newY=y+deltaY;
				if ((newX<0) || (newX>=row) || (newY<0) || (newY>=col) || visited[newX][newY])
				 continue;
				visited[newX][newY]=true;
				sum+=max(0,curHeight-heightMap[newX][newY]);
				pendingQueue.push(Cell(make_pair(newX,newY),max(heightMap[newX][newY],curHeight)));
			}
		}
		return sum;
	}
};