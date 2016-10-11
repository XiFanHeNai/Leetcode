#include <iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
 };


class Solution {
public:
	Solution(ListNode* h, int m):head(h),n(m){}

    ListNode* removeNthFromEnd(ListNode* head, int n) 
	{
        int list_len=0;
		ListNode *Node = head;
		while(Node != NULL)
		{
			list_len++;
			Node = Node->next;
		}
		if ((n > list_len) || (n == 0))
			return NULL;

		if (n == list_len)//判断是否是头节点被删除
		{
			head = head->next;
			return head;
		}
		int index=1;
		Node = head;
		while(++index != list_len-n+1)
		{
			Node = Node->next;
		}
		if (index == list_len) //删除尾节点
			Node->next = NULL;
		else
			Node->next = Node->next->next;

		return head;
    }
private:
	ListNode * head;
	int n;
};


struct ListNode * CreatList(int *a, int len)
{
	struct ListNode *head = new  struct ListNode(0);
	if (len == 0)
	{
		return head;
	}
	head->next = NULL;
	head->val = a[0];

	struct ListNode *temp_list = head;
	int index=0;
	while(index++ <len-1)
	{
		struct ListNode *list = new  struct ListNode(a[index]);
		temp_list->next = list;
		temp_list = temp_list->next;
	}
	return head;
}
int main()
{
	int a[] = {1};
	struct ListNode * list= CreatList(a,1);
	Solution s(list,5);
	struct ListNode * result = s.removeNthFromEnd(list,1);
	return 0;
}
