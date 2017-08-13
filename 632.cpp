class Solution {
public:
	struct queueElement {
		int val, list, index;
		queueElement(int v, int l, int i) :
			val(v), list(l), index(i) { } 
		bool operator < (const queueElement &g) const {
			return val < g.val;
		}
		bool operator > (const queueElement &g) const {
			return val > g.val;
		}
	};
	vector<int> smallestRange(vector<vector<int>>& nums) {
		priority_queue<queueElement, vector<queueElement>, greater<queueElement>> k_thSmallestMinRange;
		auto numOfLists=nums.size();
		int minRange=INT_MAX;
		int currentMax=INT_MIN;
		int start=-1, end=-1;
		for (auto it=nums.begin(); it!=nums.end(); ++it)
		{
			k_thSmallestMinRange.push(queueElement((*it)[0],it-nums.begin(),0));
			if ((*it)[0]>currentMax) currentMax=(*it)[0];
		}
		while (k_thSmallestMinRange.size()==numOfLists)
		{
			auto k_thSmallest=k_thSmallestMinRange.top();
			k_thSmallestMinRange.pop();
			if (currentMax-k_thSmallest.val<minRange)
			{
				minRange=currentMax-k_thSmallest.val;
				start=k_thSmallest.val;
				end=currentMax;
			}
			if (k_thSmallest.index+1<nums[k_thSmallest.list].size())
			{
				k_thSmallestMinRange.push(queueElement(nums[k_thSmallest.list][k_thSmallest.index+1], k_thSmallest.list, k_thSmallest.index+1));
				if (nums[k_thSmallest.list][k_thSmallest.index+1]>currentMax)
					currentMax=nums[k_thSmallest.list][k_thSmallest.index+1];
			}
		}
		return vector<int>{start,end};
	}
};