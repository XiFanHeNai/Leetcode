#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	Solution (string str):s(str){}//��ֵ��ʼ��

	string reverseVowels(string s)
	{
		string result(s);
		string vowels_char(s);
		//��ԭʼ�ַ����г�ȡԪ����ĸ��ɴ�Ԫ���ַ���
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
				vowels_char[vowels_count++] = s[index];//�������ľ����Ԫ����ĸ
				break;
			default:
				;
			}
			index ++;
		}
		vowels_char.resize(vowels_count);

		//��ʼ�滻�ַ����е�ԭ���ַ�
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
				result[index] = vowels_char[--vowels_count] ;//�������ľ����Ԫ����ĸ
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