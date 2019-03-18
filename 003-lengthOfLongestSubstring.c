#include <stdio.h>
#include <stdlib.h>
/**
 * Solution (DP, O(n)):
 * 
 * Assume L[i] = s[m...i], denotes the longest substring without repeating
 * characters that ends up at s[i], and we keep a hashmap for every
 * characters between m ... i, while storing <character, index> in the
 * hashmap.
 * We know that each character will appear only once.
 * Then to find s[i+1]:
 * 1) if s[i+1] does not appear in hashmap
 *    we can just add s[i+1] to hash map. and L[i+1] = s[m...i+1]
 * 2) if s[i+1] exists in hashmap, and the hashmap value (the index) is k
 *    let m = max(m, k), then L[i+1] = s[m...i+1], we also need to update
 *    entry in hashmap to mark the latest occurency of s[i+1].
 * 
 * Since we scan the string for only once, and the 'm' will also move from
 * beginning to end for at most once. Overall complexity is O(n).
 *
 * If characters are all in ASCII, we could use array to mimic hashmap.
 

int lengthOfLongestSubstring(string s) {
    // for ASCII char sequence, use this as a hashmap
    vector<int> charIndex(256, -1);
    int longest = 0, m = 0;

    for (int i = 0; i < s.length(); i++) {
        m = max(charIndex[s[i]] + 1, m);    // automatically takes care of -1 case
        charIndex[s[i]] = i;
        longest = max(longest, i - m + 1);
    }

    return longest;
}
*/
int lengthOfLongestSubstring(char* s) {
    unsigned int result=0;
    unsigned int i=0,j=0;
    unsigned char map[256]={0};//由于没有规定字符串的组成，代表可能会包含特殊符号，因此该空间较大。
    if (s == NULL){
        return 0;
    } else {
        while(*(s+j) != '\0'){
            printf("i=%d,j=%d\n",i,j);
            if (map[*(s+j)]){ //检测到已存在的字符
                result = (result>(j-i))? result:(j-i);
                while(*(s+i) != *(s+j)){
                    map[*(s+i)] = 0; //已经过检测的字符，不属于新的检查范围
                    i++;
                }
                ++i;
                ++j;
            } else {
                map[*(s+j)] = 1;
                ++j;
            }
        }
        result = (result>(j-i))? result:(j-i);
        return result;
    }
}

void main(void)
{
    char* s="a";
    unsigned int result;
    printf("This is Leetcode Question No.3 \n");
    result = lengthOfLongestSubstring(s);
    printf("result = %d \n",result);
}
