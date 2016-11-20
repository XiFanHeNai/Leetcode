#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/* 方法1：按照定义，先求出各子节点的深度，该节点是否是一个平衡二叉树，以此递归 */
/*
class Solution {
public:

    bool isBalanced(TreeNode* root)
	{
		if(root == NULL)
			return true;
		else
		{
			//if (root->left != NULL && root->right != NULL)
			{
				unsigned int left_depth = MaxDepth(root->left);
				unsigned int right_depth = MaxDepth(root->right);
				if (left_depth>right_depth+1 || right_depth>left_depth+1)
					return false;
				else
					return isBalanced(root->left) & isBalanced(root->right);
			}
		}
    }
	int MaxDepth(TreeNode * root)
	{
		if (root == NULL)
			return 0;
		else
		{
			if (root->left != NULL || root->right != NULL)
			{
				unsigned int left_depth = MaxDepth(root->left);
				unsigned int right_depth = MaxDepth(root->right);
				return (left_depth >= right_depth)?(left_depth+1):(right_depth+1);
			}
			else
				return 1;
			
		}
	}
};
*/
/*方法2：由于只需要判断两子节点的深度差不大于1就可以判断出该节点是否平衡，因此不求出节点的深度 （失败，无法有效覆盖所有情况）*/
/**/
class Solution {
public:

    bool isBalanced(TreeNode* root)
	{
		if(root == NULL)
			return true;
		else
		{
			if (root->left != NULL && root->right != NULL)
			{
				if ((root->right->left == NULL && root->right->right == NULL))
				{
					if (root->left->left == NULL && root->left->right == NULL)
						return true;
					else if (root->left->left != NULL && root->left->right == NULL)
						return (root->left->left->left == NULL && root->left->left->right == NULL);
					else if (root->left->left == NULL && root->left->right != NULL)
						return (root->left->right->left == NULL && root->left->right->right == NULL);
					else
						return !(root->left->left->left != NULL || root->left->left->right != NULL ||
							root->left->right->left != NULL || root->left->right->right != NULL );
				}
				else if ((root->left->left == NULL && root->left->right == NULL))
				{
					if (root->right->left == NULL && root->right->right == NULL)
						return true;
					else if (root->right->left != NULL && root->right->right == NULL)
						return (root->right->left->left == NULL && root->right->left->right == NULL);
					else if (root->right->left == NULL && root->right->right != NULL)
						return (root->right->right->left == NULL && root->right->right->right == NULL);
					else
						return !(root->right->left->left != NULL || root->right->left->right != NULL ||
							root->right->right->left != NULL || root->right->right->right != NULL );
				}
				else
					return isBalanced(root->left) & isBalanced(root->right);
			}
			else if (root->left == NULL && root->right != NULL)
			{
				if (root->right->left != NULL || root->right->right != NULL)
					return false;
				else
					return true;
			}
			else if (root->left != NULL && root->right == NULL)
			{
				if (root->left->left != NULL || root->left->right != NULL)
					return false;
				else
					return true;
			}
			else 
				return true;
		}
    }
};
