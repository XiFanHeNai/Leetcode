#include <iostream>

using namespace std;

typedef unsigned int uint32;

int guess(int Num);

class Solution {
public:
	Solution(int P,int R)
	{
		Range=R;
		PickNum = P;
	}
    int guessNumber(int n) {
		uint32 High=0 ;
		uint32 Low=0 ;
		uint32 Half=0 ;
 


		if (guess(n) > 0)
		{
			High = n;
			Low = 1;
		}
		else if (guess(n) < 0)
		{
			High = Range;
			Low = n;
		}
		else
			return n;

		Half = ( (High+Low)%2 == 0 )?(High+Low)/2:(High+Low+1)/2;
		int result;
		while((result = guess(Half)) != 0)
		{
			if ( result < 0)
				Low = Half;
			else
				High = Half;

			Half = ( (High+Low)%2 == 0 )?(High+Low)/2:(High+Low+1)/2;
			if (Low == High)
				return 0;
		}
		return Half;
    }
private:
	int Range;
	int PickNum;
};

int Pick;
int guess(int Num)
{
	if (Num < Pick)
		return -1;
	else if (Num > Pick)
		return 1;
	else
		return 0;
}





int main()
{
	class Solution Solu_1(1702766719,2126753390);
	//class Solution Solu_1(13,20);
	Pick = 1702766719;

	if (0 == Solu_1.guessNumber(2))
		cout << "target can not be found \n" << endl;
	else
		cout << "Find the target: " << Solu_1.guessNumber(2)<<endl;

	cout << "Hello World !! \n" << endl;
	return 0;
}