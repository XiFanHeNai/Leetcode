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
		TreeNode *root = (TreeNode *)new(nothrow) TreeNode(0);//new����ʱ������NULL,�����׳��쳣��new(nothrow)��պ���֮�෴�������쳣������NULL
		//TreeNode *root =  &TreeNode(0);//����TreeNode�Ĺ��캯��,������ʱ�ڴ棬��ַ���ֲ��䣬���ı�õ�ַ���洢������
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
    }
private:
	TreeNode *root;
};
/* ����3��ÿ�������ĳһ���Ԫ��ʱ��ͳ����һ��ڵ�ĸ��� */



int main()
{
	int a[] = {1,2,3};
	TreeNode* tree = CreateTreeFromArray(a,sizeof(a)/sizeof(a[0]));
	Solution s;
	vector<vector<int>> result = s.levelOrder(tree);
	return 0;
}