class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		return qselect(nums, 0, nums.size()-1, nums.size()-k);
	}
private:
	int qselect(vector<int>& a, int l, int r, int k)
	{
		if (r==l) return a[r];
		int v=a[l];
		int i=l+1,j=r;
		int temp=0;
		while (1)
		{
			while ((a[i]<=v) && (i<r)) i++;
			while ((a[j]>=v) && (j>l)) j--;
			if (i<j)
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
			else break;
		}
		a[l]=a[j];
		a[j]=v;
		if (k==j) return a[k];
		else if (k<j) return qselect(a,l,j-1,k);
		else return qselect(a,j+1,r,k);
	}
};
