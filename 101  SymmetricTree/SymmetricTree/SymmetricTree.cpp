#include<iostream>
#include<stack>

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
    bool isSymmetric(TreeNode* root) {
		/* 检查根结点，问题：如果root!=null,root->left=null.root->right!=null,返回值是否有错误 */
        if (!root || !root->left && !root->right) return true;  
		/* 检查根节点的左右子节点是否对称 */
        TreeNode *t1 = root->left, *t2 = root->right;  
        if (t1&&!t2 || !t1&&t2 || t1->val!=t2->val) return false;  
  
        stack<TreeNode *> s1, s2;  
        s1.push(t1), s2.push(t2);  
        bool flag = false;  
        while (!s1.empty() && !s2.empty())  
        {  
            if (!flag && (t1->left || t2->right))  
            {  
                s1.push(t1), s2.push(t2);  
                t1 = t1->left, t2 = t2->right;  
                if (t1&&!t2 || !t1&&t2 || t1->val!=t2->val) return false;  
                s1.push(t1), s2.push(t2);  
            }  
            else if (t1->right || t2->left)  
            {  
                t1 = t1->right, t2 = t2->left;  
                if (t1&&!t2 || !t1&&t2 || t1->val!=t2->val) return false;  
                flag = false;  
            }  
            else  
            {  
                t1 = s1.top(), t2 = s2.top();  
                s1.pop(), s2.pop();  
                flag = true;  
            }  
        }  
        return s1.empty() && s2.empty();
    }
};
int main()
{
	int a[] = {1,2,3,4,5,6,7};
	TreeNode* tree = CreateTreeFromArray(a,sizeof(a)/sizeof(a[0]));
	return 0;
}
 