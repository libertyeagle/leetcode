#include <stdio.h>
int trap(int* height, int heightSize) {
   	int maxindex=0;
	int max=height[0];
	int i=0;
	for (i=1; i<heightSize; i++) if (height[i]>max) {
		maxindex=i;
		max=height[i];
	}
	int localmax=height[0];
	int area=0;
	for (i=1; i<maxindex; i++) {
		if (height[i]>localmax) localmax=height[i];
		else area+=(localmax-height[i]);	
	}
	localmax=height[heightSize-1];
	for (i=heightSize-2; i>maxindex; i--) {
		if (height[i]>localmax) localmax=height[i];
		else area+=(localmax-height[i]);	
	}
	return area;
}
int main(int argc, char *argv[]) {
	int n;
	int a[100];
	scanf("%d",&n);
	int i;
	for (i=0; i<n; i++) scanf("%d",&a[i]);
	printf("%d",trap(a,n));
}