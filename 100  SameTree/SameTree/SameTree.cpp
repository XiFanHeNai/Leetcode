#include <iostream>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x),left(NULL),right(NULL){};
};


class Solution {
public:
	Solution():p(NULL),q(NULL){}
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if ((p == NULL && q!= NULL) || (p!=NULL && q==NULL))
			return false;
		else if (p == NULL && q == NULL)
			return true;
		else
		{
			if (p->val != q->val)
				return false;
			else
				return (isSameTree(p->left,q->left) & isSameTree(p->right,q->right));
		}
			
    }
private:
	TreeNode* p;
	TreeNode* q;
};

int main()
{
	TreeNode *p=NULL;
	TreeNode *q=NULL;
	Solution s;
	bool result = s.isSameTree(p,q);
	return 0;
}