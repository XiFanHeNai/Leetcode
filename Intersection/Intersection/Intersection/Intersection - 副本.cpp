#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	Solution(vector<int> n1, vector<int> n2)
	{
		nums1 = n1;
		nums2 = n2;
	}
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
	{
		vector<int> temp_1(nums1.size()),temp_2(nums2.size());
		vector<int> result((nums1.size()>nums2.size())? nums1.size():nums2.size());//ȡ�ϳ�������ĳ������½��������
		int index_num=0,index_temp=0;
		int index_temp1=0;
		int index_temp2=0;


		if ((nums1.size() == 0) 
			|| (nums2.size() == 0) 
			|| ((nums1.size() == 2)&&(nums1[0] != nums1[1])) 
			|| ((nums2.size() == 2)&&(nums2[0] != nums2[1])))//����һ��Ϊ�գ�������������Ϊ2������û�н��㣬��ֱ�ӷ��ؿ�
		{
			result.resize(0);
			return result;
		}

		if (nums1.size() == 0)
			temp_1.resize(0);
		else if ( (nums1.size()  == 1) || ((nums1.size() == 2)&&(nums1[0] == nums1[1])) )
		{
			temp_1.resize(1);
			temp_1[0] = nums1[0];
		}
		else if (nums1.size() >= 3)
		{
			//������1�п��ܳ�Ϊ����ĵ���ȡ����
			while(index_num < nums1.size()-2)
			{	
				if ((nums1[index_num] == nums1[index_num+1]) && (nums1[index_num] != nums1[index_num+2]))
				{
					while((index_temp1 < index_temp) && (temp_1[index_temp1] != nums1[index_num])) //�޳��Ѵ��ڵ�Ǳ�ڽ���
						index_temp1++;
					if (index_temp1 == index_temp)//�����µ�Ǳ�ڽ���
					{
						temp_1[index_temp] = nums1[index_num];
						index_temp++;
					}
					index_temp1=0;
				}
				index_num++;
			}
			if (nums1[index_num] == nums1[index_num+1])
			{
				while((index_temp1 < index_temp) && (temp_1[index_temp1] != nums1[index_num])) //�޳��Ѵ��ڵ�Ǳ�ڽ���
					index_temp1++;
				if (index_temp1 == index_temp)//�����µ�Ǳ�ڽ���
				{
					temp_1[index_temp] = nums1[index_num];
					index_temp++;
				}
				index_temp1=0;
				
			}
			temp_1.resize(index_temp);
		}
		index_temp1=0;
		index_temp=0;
		index_num=0;

		//ͬ��������2
		if ( (nums2.size()  == 1) || ((nums2.size() == 2)&&(nums2[0] == nums2[1])) )
			temp_2[0] = nums2[0];
		else if (nums2.size() >= 3)
		{
			while(index_num < nums2.size()-2)
			{
				if ((nums2[index_num] == nums2[index_num+1]) && (nums2[index_num] != nums2[index_num+2]))
				{
					while((index_temp2 < index_temp) && (temp_2[index_temp2] != nums2[index_num])) //�޳��Ѵ��ڵ�Ǳ�ڽ���
						index_temp2++;
					if (index_temp2 == index_temp)//�����µ�Ǳ�ڽ���
					{
						temp_2[index_temp] = nums2[index_num];
						index_temp++;
					}
					index_temp2=0;
				}
				index_num++;
			}
			if (nums2[index_num] == nums2[index_num+1])
			{
				while((index_temp2 < index_temp) && (temp_2[index_temp2] != nums2[index_num])) //�޳��Ѵ��ڵ�Ǳ�ڽ���
					index_temp2++;
				if (index_temp2 == index_temp)//�����µ�Ǳ�ڽ���
				{
					temp_2[index_temp] = nums2[index_num];
					index_temp++;
				}
				index_temp2=0;
			}
			temp_2.resize(index_temp);
		}
		//�Ƚ�������ȡ�Ľ������
		index_temp2=0;
		index_temp=0;

		if ((temp_1.size() == 0) || (temp_2.size() == 0))
		{
			result.resize(0);
			return result;
		}
		while(index_temp1 < temp_1.size())
		{
			while( index_temp2 < temp_2.size() ) 
			{
				if (temp_1[index_temp1] == temp_2[index_temp2])
				{
					result[index_temp] = temp_1[index_temp1];
					index_temp++;
				}
				index_temp2++;
			}
			index_temp2=0;
			index_temp1++;
		}
		result.resize(index_temp);
		return result;
    }
private:
	vector<int> nums1;
	vector<int> nums2;
};
int main()
{
	//int a1[] = {};
	//int a1[]={1};
	//vector<int> v1(a1,a1+(sizeof(a1)/sizeof(int))) ;
	vector<int> v1(0);
	int a2[] = {5};
	//int a2[]={1};
	vector<int> v2(a2,a2+(sizeof(a2)/sizeof(int))) ;


	Solution s1(v1,v2);
	vector<int> result = s1.intersection(v1,v2);
	int index=0;
	for (index=0;index<result.size();index++)
		cout << result[index] << endl;


	cout << "Hello World \n" << endl;
	return 0;
}
