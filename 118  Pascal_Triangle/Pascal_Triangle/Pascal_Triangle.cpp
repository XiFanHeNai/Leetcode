#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/* ���ַ�������һ�ֲ���ֱ�Ӽ��㷽����Ч�ʻ�û�г��ԣ��ڶ��ֲ��ö�����ʽ�洢ÿһ�е����ݣ�Ч�ʽϺá������㷨��δ�б��ʵ����� */
/*
class Solution {
public:
	Solution (int n):numRows(n){}
    vector<vector<int>> generate(int numRows)
    {
		vector<vector<int>> result(numRows);
        if (numRows != 0)
		{
			unsigned int row_index=0;
			queue<int> q;
			while(row_index++ < numRows)
			{
				int val=1;
				unsigned int index=1;
				int temp_sum=1;
				while(index++ < row_index)
				{
					if (index == 2)
					{
						val = q.front();
						q.pop();
						result[row_index-1].push_back(1);
					}
					else
					{
						temp_sum=val+q.front();
						val = q.front();q.pop();
						result[row_index-1].push_back(temp_sum);
					}
					q.push(temp_sum);
				}
				result[row_index-1].push_back(1);
				q.push(1);
			}
			
		}
		return result;
    }
private:
	int numRows;
};
*/

class Solution {
public:
	Solution (int n):rowIndex(n){}
    vector<int> getRow(int rowIndex) 
    {
		vector<int> result;
		unsigned int row_index=0;
		queue<int> q;
		while(row_index++ < rowIndex+1)
		{
			int val=1;
			unsigned int index=1;
			int temp_sum=1;
			while(index++ < row_index)
			{
				if (index == 2)
				{
					val = q.front();
					q.pop();
				}
				else
				{
					temp_sum=val+q.front();
					val = q.front();q.pop();
				}
				q.push(temp_sum);
			}
			q.push(1);
		}
		while(!q.empty())
		{
		    result.push_back(q.front());
		    q.pop();
	    }
		return result; 
    }
private:
	int rowIndex;
};
int main()
{
	Solution s(0);
	vector<int> result = s.getRow(2);
	return 0;
}