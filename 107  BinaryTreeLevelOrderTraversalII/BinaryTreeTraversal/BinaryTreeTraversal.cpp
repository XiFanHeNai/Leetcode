#include<iostream>
#include<vector>
#include<queue>

using namespace std;


/* ������� */
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
	/* ����:�Ȱ����ϵ��£������ҵķ�ʽ���������Ȼ��������������鷴�򼴿� */
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