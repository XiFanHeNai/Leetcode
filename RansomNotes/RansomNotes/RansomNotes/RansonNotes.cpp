#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef unsigned int uint32;
class Solution {
public:
	Solution(string Note,string Maga)
	{
		ransomNote = Note;
		magazine = Maga;
	}
    bool canConstruct(string ransomNote, string magazine)
	{
		vector<uint32> StaRansomNote(26,0);
		vector<uint32> StaMagazine(26,0);

		uint32 i=0;
		for (;i<ransomNote.size();i++)
		{
			StaRansomNote[ransomNote[i]-'a'] ++;
		}

		//uint32 j=ransomNote[0];
		uint32 k=magazine.size();
		uint32 j=0;
		for (j=0;j<1;j++)
		{
			StaMagazine[magazine[j] - 'a']++;
			//j++;
		}

		for (int i=0;i<26;i++)
		{
			if( StaRansomNote[i] > StaMagazine[i])
				return false;
		}
		return true;
	}
private:
	string ransomNote;
	string magazine;
};




int main()
{
	string ransomNote = "aa";
	string Magazine = "ab";
	class Solution Solu_1(ransomNote,Magazine);

	if (true == Solu_1.canConstruct(ransomNote,Magazine))
		cout << "It is able to be constructed !\n"<<endl;
	else
		cout << "It can not be constructed !\n"<<endl;
	return 0;
}

