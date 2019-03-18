#include <stdio.h>
#include <stdlib.h>


double FindKth(int* nums1,int nums1Size,int* nums2,int nums2Size,int k)
{
    int nums1_index=0,nums2_index=0;
    printf("nums1=%d,nums1Size=%d,nums2=%d,nums2Size=%d,k=%d\n",*nums1,nums1Size,*nums2,nums2Size,k);
    if (nums1Size < nums2Size){
        return FindKth(nums2,nums2Size,nums1,nums1Size,k);
    }
    if (nums2Size == 0){
        return (float) *(nums1+k-1);
    }
    if (k == 1){
        return (*nums1 < *nums2)? *nums1:*nums2; 
    }

    
    nums2_index = (nums2Size > k/2)? k/2:nums2Size;
    nums1_index = k-nums2_index;
    printf("\tnums1_index=%d,nums2_index=%d\n",nums1_index,nums2_index);
    if (*(nums1+nums1_index-1) < *(nums2+nums2_index-1)){
        return FindKth(nums1+nums1_index,nums1Size-nums1_index,nums2,nums2Size,k-nums1_index);
    } else {
        return FindKth(nums1,nums1Size,nums2+nums2_index,nums2Size-nums2_index,k-nums2_index);
    }
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int total_size = nums1Size+nums2Size;  
    double result;
    if (total_size%2)
    {
        result = FindKth(nums1, nums1Size,nums2, nums2Size, (total_size+1)/2);
        printf("result = %f\n",result);
        return FindKth(nums1, nums1Size,nums2, nums2Size, (total_size+1)/2);
    }else{
        result = FindKth(nums1, nums1Size,nums2, nums2Size, total_size/2)/2.0;
        printf("result = %f\n",result);
        result = FindKth(nums1, nums1Size,nums2, nums2Size, total_size/2+1)/2.0;
        printf("\tresult = %f\n",result);
        
        return FindKth(nums1, nums1Size,nums2, nums2Size, total_size/2)/2.0+\
            FindKth(nums1, nums1Size,nums2, nums2Size, total_size/2+1)/2.0;
    }
}

void main(void)
{
    int a[]={1,4,6,8};
    int b[]={2,3,5,7,9,10};
    double result = findMedianSortedArrays(a,sizeof(a)/sizeof(a[0]),b,sizeof(b)/sizeof(b[0]));
    printf("the result is %f\n",result);
    printf("This is Leetcode Question No.4 \n");
}
