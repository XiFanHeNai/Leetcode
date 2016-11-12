#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};

TreeNode *CreateTreeFromArray(int *a,unsigned int length)
{
	if (a == NULL)
		return NULL;
	else
	{
		TreeNode *root = (TreeNode *)new(nothrow) TreeNode(0);//new出错时不返回NULL,而是抛出异常，new(nothrow)则刚好与之相反，不抛异常但返回NULL
		//TreeNode *root =  &TreeNode(0);//调用TreeNode的构造函数,分配临时内存，地址保持不变，仅改变该地址所存储的内容
		unsigned int center=(length%2)? ((length-1)/2):(length/2);
		root->val = a[center];
		if (length > 2)
		{
			root->left = CreateTreeFromArray(a,center);
			root->right = CreateTreeFromArray(a+center+1,(length-center-1));
		}
		else if (length == 2)
		{
			root->left = CreateTreeFromArray(a,center);
		}

		return root;
	}
}

class Solution {
public:
	Solution():root(NULL){}
    int maxDepth(TreeNode* root)
	{
		int depth=0;
		int left_depth,right_depth;
        if (root != NULL)
		{
			left_depth = maxDepth(root->left);
			right_depth = maxDepth(root->right);
			depth = (left_depth >= right_depth)? (left_depth+1):(right_depth+1);		
		}
		return depth;
    }
private:
	TreeNode *root;
};

int main()
{
	int a[] = {1,2,3};
	TreeNode* tree = CreateTreeFromArray(a,sizeof(a)/sizeof(a[0]));
	Solution s;
	vector<vector<int>> result = s.levelOrder(tree);
	return 0;
}
 