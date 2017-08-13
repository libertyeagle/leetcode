class Solution {
public:
	vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
		vector<int> temp(k,0);
		vector<int> &maxNum=temp;
		for (int i=0; i<=k; i++)
			if (i<=nums1.size() && k-i<=nums2.size())
			{
				auto candidate=merge(maxSingleList(nums1, i), 
				maxSingleList(nums2, k-i));
				if (compare(candidate, maxNum, 0, 0)) maxNum=candidate;
			}
		return maxNum;
	}
private:
	bool compare(const vector<int>& num1, const vector<int> &num2, int pos1, int pos2 )
	{
		while (pos1<num1.size() && pos2<num2.size() && num1[pos1]==num2[pos2])
		{
			++pos1;
			++pos2;
		}
		return pos2==num2.size() || (pos1<num1.size() && num1[pos1]>num2[pos2]);
	}
	vector<int> merge(const vector<int>& selected1,const vector<int>& selected2)
	{
		auto len1=selected1.size(), len2=selected2.size();
		auto len=len1+len2;
		if (len1==0) return selected2;
		else if (len2==0) return selected1;
		int currPos1=0, currPos2=0;
		vector<int> retVec{};
		for (int i=0; i<len; i++)
			retVec.push_back(compare(selected1, selected2, currPos1, currPos2) ? 
				selected1[currPos1++] : selected2[currPos2++]);
		return retVec;
	}
	vector<int> maxSingleList(vector<int>& nums, int k)
	{
		auto len=nums.size();
		if (k==len) return nums;
		int currentPos=0, selectLastPos=len-k;
		vector<int> retVec{};
		for (int i=1; i<=k; ++i)
		{
			vector<int> maxPair=maxElemnt(nums.begin()+currentPos, nums.begin()+selectLastPos+1);
			int maxVal=maxPair[0], maxPos=currentPos+maxPair[1];
			retVec.push_back(maxVal);
			currentPos=maxPos+1;
			++selectLastPos;
		}
		return retVec;
	}
	vector<int> maxElemnt(vector<int>::const_iterator start, vector<int>::const_iterator end)
	{
		int maxVal=*start;
		int maxPos=0;
		for (auto it=start; it!=end; ++it)
			if (*it>maxVal)
			{
				maxVal=*it;
				maxPos=it-start;
			}
		return vector<int>{maxVal, maxPos};
	}
};