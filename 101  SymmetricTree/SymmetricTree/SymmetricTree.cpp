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
    bool isSymmetric(TreeNode* root) {
		/* ������㣬���⣺���root!=null,root->left=null.root->right!=null,����ֵ�Ƿ��д��� */
        if (!root || !root->left && !root->right) return true;  
		/* �����ڵ�������ӽڵ��Ƿ�Գ� */
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
 