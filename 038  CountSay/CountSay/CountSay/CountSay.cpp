#include <iostream>
#include <string>

using namespace std;
class Solution {
public:
	Solution(int m):n (m){}
    string countAndSay(int n) {
		string result("1");
        if (n==1)
			return result;
		else
		{
			int times=2;
			string temp("1");
			
			while(times <= n)
			{
				unsigned int index=0;
				unsigned int count=1;
				result.resize(0);
				while(index < temp.size())
				{
					if ((index < temp.size()-1) && (temp[index] == temp[index+1]))
						count++;
					else 
					{
						result.resize(result.size()+2);
						result[result.size()-2] = count+'0';
						result[result.size()-1] = temp[index];
						count=1;				
					}
					index++;
				}
				temp.assign(result);
				times++;
			}
			return result;
		}
    }
private:
	int n;
};

int main()
{
	Solution s(0);
	string result = s.countAndSay(6);
	return 0;
}