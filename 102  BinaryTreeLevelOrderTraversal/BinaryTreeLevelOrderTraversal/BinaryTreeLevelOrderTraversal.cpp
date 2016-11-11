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

/* 方法1：用每一层最左边的节点作为层与层的标记 */
/*
class Solution {
public:
	Solution():root(NULL){}
    vector<vector<int>> levelOrder(TreeNode* root)
	{
		vector<vector<int>> result;
		if (root != NULL)
		{
			queue<TreeNode *> q;
			q.push(root);
			TreeNode *t;
			unsigned int index=0;
			TreeNode *flag = NULL;	
			result.resize(1);
			while(!q.empty())
			{
				t=q.front();
				q.pop();
				if (t->left != NULL) 
				{
					if (flag == NULL)
						flag = t->left;
					q.push(t->left);
				}
				if (t->right != NULL)
				{
					if (flag == NULL)
						flag = t->right;
					q.push(t->right);
				}

				if (t != flag)
				{
					result[index].push_back(t->val);
				}
				else
				{
					if (t->left != NULL)
						flag = t->left;
					else if (t->right != NULL)
						flag = t->right;
					else
						flag = NULL;
					index++;
					result.resize(index+1);
					result[index].resize(1);
					result[index][0] = t->val;
				}
			}
		}
		return result;
    }
private:
	TreeNode *root;
};
*/
/* 方法2：开辟两个队列，将每一层的数据分别放入两个队列中，两个队列形成数字逻辑电路中的乒乓操作 */
class Solution {
public:
	Solution():root(NULL){}
    vector<vector<int>> levelOrder(TreeNode* root)
	{
		vector<vector<int>> result;
		if (root != NULL)
		{
			queue<TreeNode *> q1,q2;
			bool flag;
			vector<int> temp_result;
			TreeNode *t;
			q1.push(root);
			while(!q1.empty() || !q2.empty())
			{
				if (q1.empty())
					flag = false;
				else if (q2.empty())
					flag = true;

				if (flag)
				{
					//q2为空
					t = q1.front();
					q1.pop();

					if (t->left != NULL)
						q2.push(t->left);
					if (t->right != NULL)
						q2.push(t->right);
				}
				else
				{
					t = q2.front();
					q2.pop();
					
					if (t->left != NULL)
						q1.push(t->left);
					if (t->right != NULL)
						q1.push(t->right);
				}
				temp_result.push_back(t->val);
				if ((flag && q1.empty()) || ((!flag) && q2.empty()))
				{
					result.push_back(temp_result);
					temp_result.resize(0);
				}

			}
		}
		
		return result;
    }
private:
	TreeNode *root;
};
/* 方法3：每次在输出某一层的元素时，统计下一层节点的个数 */



int main()
{
	int a[] = {1,2,3};
	TreeNode* tree = CreateTreeFromArray(a,sizeof(a)/sizeof(a[0]));
	Solution s;
	vector<vector<int>> result = s.levelOrder(tree);
	return 0;
}
 