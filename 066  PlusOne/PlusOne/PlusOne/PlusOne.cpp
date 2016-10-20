#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	Solution(vector<int>& d):digits(d){}
	vector<int> plusOne(vector<int>& digits) {
		int index=digits.size();
        while(index-- > 1)
		{
			if (digits[index] == 9)
			{
				digits[index] = 0;
			}
			else
			{
				digits[index]++;
				return digits;
			}
		}

		if (digits[index] != 9)
		{
			digits[index]++;
			return digits;
		}
		else
		{
			digits.resize(digits.size()+1,0);
			digits[0]=1;
			return digits;
		}
    }
private:
	vector<int>& digits;
};

int main(void)
{
	int tv[2] = {1,0};
	vector<int> ttv(tv,tv+sizeof(tv)/sizeof(tv[0]));
	vector<int> &v = ttv;
	Solution s(v);
	vector<int> result = s.plusOne(v);
	return 0;
}