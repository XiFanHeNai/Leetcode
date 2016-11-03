#include <iostream>
#include <vector>
#include <utility>

using namespace std;

/*���Գ�ʼ��const������������͵Ķ��󣬵����ܶ����Ǹ�ֵ���ڿ�ʼִ�й��캯���ĺ�����֮ǰ��������ɳ�ʼ����
��ʼ��const�������������ݳ�Ա��Ψһ�������ڹ��캯����ʼ���б��С�*/
class Solution {
public:
	Solution(vector<int> &temp):nums1(temp),m(0),nums2(temp),n(0){}
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
	{
		unsigned int i=m+n;
		while(n>0 && m>0)
		{
			if (nums1[m-1] <= nums2[0])
			{
				while(n>0) nums1[--i] = nums2[--n];
				break;
			}
			else if (nums2[n-1] <= nums1[0])
			{
				while(m>0) nums1[--i] = nums1[--m];
				while(n>0) nums1[--i] = nums2[--n];
				break;
			}
			else
				nums1[--i] = (nums1[m-1] >= nums2[n-1])?nums1[--m]:nums2[--n];
		}
		while(n>0) nums1[--i] = nums2[--n];//Ϊ��ֹ����������֣���ʵ��m=0,n>0�����
    }
private:
	vector<int>& nums1;
	int m;
	vector<int>& nums2;
	int n;
};


int main(void)
{
	//int a[6] = {1,3,5};int b[3] = {2,4,6};
	int a[6] = {4,7,8};int b[3] = {1,3,5};
	vector<int> n1(a,a+sizeof(a)/sizeof(a[0]));
	vector<int> n2(b,b+sizeof(b)/sizeof(b[0]));
	vector<int> &nums1 = n1;
	vector<int> &nums2 = n2;
	Solution s(nums1);
	s.merge(nums1,nums1.size()-nums2.size(),nums2,nums2.size());
	return 0;
}