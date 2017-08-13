class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int len1=nums1.size(), len2=nums2.size();
		int total=len1+len2;
		if (total % 2==1)
			return static_cast<double>(findKthSmallest(nums1.begin(), nums2.begin(), len1, len2, total/2+1)); 
		else
			return (static_cast<double>(findKthSmallest(nums1.begin(), nums2.begin(), len1, len2, total/2)) +
			static_cast<double>(findKthSmallest(nums1.begin(), nums2.begin(), len1, len2, total/2+1))) / 2;
	}
private:
	int findKthSmallest(vector<int>::const_iterator it1, vector<int>::const_iterator it2, int len1, int len2, int k) {
		if (len1>len2) return findKthSmallest(it2, it1, len2, len1, k);
		// Make sure len1 always smaller than len2, otherwise k2 may exceed array index.
		if (len1==0) return it2[k-1];
		if (k==1) return min(it1[0],it2[0]);
	 	int k1=min(k/2,len1);
		int k2=k-k1;
		--k1;
		--k2;
		if (it1[k1]<it2[k2])
			return findKthSmallest(it1+(k1+1), it2, len1-(k1+1), len2, k-(k1+1));
		else if (it1[k1]>it2[k2])
			return findKthSmallest(it1, it2+(k2+1), len1, len2-(k2+1), k-(k2+1));
		else
			return it1[k1];
	}
};