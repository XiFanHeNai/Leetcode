#include<iostream>
#include<vector>
#include<queue>

using namespace std;


/* 优秀代码 */
/*
class Solution
{
public:
    vector<vector<int> > result;

    void levelTra(TreeNode *root, int level)
    {
        if(root == NULL)
            return;
        if(level == result.size())
        {
            vector<int> v;
            result.push_back(v);
        }
        result[level].push_back(root->val);
        levelTra(root->left, level+1);
        levelTra(root->right, level+1);
    }

    vector<vector<int> > levelOrderBottom(TreeNode *root) 
    {
        levelTra(root, 0);
        return vector<vector<int> >(result.rbegin(), result.rend());
    }
};
*/



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
	/* 方法:先按从上到下，从左到右的方式层序遍历，然后将最终输出的数组反向即可 */
	vector<vector<int>> levelOrderBottom(TreeNode* root)
	{
		vector<vector<int>> result;
		if (root != NULL)
		{
			queue<TreeNode*> q;
			q.push(root);
			unsigned int index=0;
			while(!q.empty())
			{
				unsigned int t_size = q.size();
				
				vector<int> t_array;
				TreeNode *t;
				for(index=0;index<t_size;index++)
				{
					t=q.front();
					q.pop();
					t_array.push_back(t->val);

					if (t->left != NULL)
						q.push(t->left);
					if (t->right != NULL)
						q.push(t->right);

				}
				vector<vector<int>>::iterator location = result.begin();
				result.insert(location,1,t_array);
			}
		}
		return result;
    }
private:
	TreeNode *root;
};




int main()
{
	int a[] = {1,2,3};
	TreeNode* tree = CreateTreeFromArray(a,sizeof(a)/sizeof(a[0]));
	Solution s;
	vector<vector<int>> result = s.levelOrderBottom(tree);
	return 0;
}