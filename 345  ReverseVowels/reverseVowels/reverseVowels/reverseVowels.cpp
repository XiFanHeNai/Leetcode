#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	Solution (string str):s(str){}//按值初始化

	string reverseVowels(string s)
	{
		string result(s);
		string vowels_char(s);
		//从原始字符串中抽取元音字母组成纯元音字符串
		int index=0;
		int vowels_count=0;
		while(index < s.size())
		{
			switch (s[index])
			{
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
			case 'A':
			case 'E':
			case 'I':
			case 'O':
			case 'U':
				vowels_char[vowels_count++] = s[index];//并不关心具体的元音字母
				break;
			default:
				;
			}
			index ++;
		}
		vowels_char.resize(vowels_count);

		//开始替换字符串中的原因字符
		index=0;
		while(index < s.size())
		{
			switch (s[index])
			{
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
			case 'A':
			case 'E':
			case 'I':
			case 'O':
			case 'U':
				result[index] = vowels_char[--vowels_count] ;//并不关心具体的元音字母
				break;
			default:
				;
			}
			index ++;
		}
		
		return result;
	}

private:
	string s;
};


int main()
{
	Solution s("sA");
	string result;
	result = s.reverseVowels("aA");
	cout << "Hello World !!!! \n" << endl;
}