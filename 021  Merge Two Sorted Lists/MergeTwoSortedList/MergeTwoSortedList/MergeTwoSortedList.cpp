#include <iostream>
#include <cstdlib>

using namespace std;


struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL){}
};

ListNode * CreateList(int* a, int len)
{
	if (len == 0)
		return NULL;
	int index=0;

	ListNode *head = new ListNode(0);
	if (head == NULL)
		return NULL;
	head->val = a[0];
	head->next = NULL;
	ListNode *temp = head;
	while(index++ < len-1)
	{
		ListNode* Node = (ListNode*)malloc(sizeof(struct ListNode));
		Node->val = a[index];
		Node->next = NULL;
		
		temp->next = Node;
		temp = temp->next;
	}
	return head;
}

class Solution {
public:
	Solution():l1(&ListNode(0)),l2(&ListNode(0)){}
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
	{
        
    }
private:
	ListNode *l1;
	ListNode *l2;
};



int main()
{
	int a[] = {3,5,8,11,13,14,15};
	ListNode * list1 = CreateList(a,7);
	return 0;
}