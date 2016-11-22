#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	Solution(vector<int> p):prices(p){}
    int maxProfit(vector<int>& prices) 
	{
		if (prices.size() < 2)
			return 0;
		else
		{
			unsigned int index_buy=0,index_sell=1;
			int price_buy=prices[0],price_sell=prices[1];
			while(index_buy < prices.size() && index_sell < prices.size())
			{

				if (price_buy >= prices[index_buy])
				{
					price_buy = prices[index_buy];
					price_sell = prices[index_sell];
				}
			}
		}
    }
private:
	vector<int>& prices;
};


int main()
{

}