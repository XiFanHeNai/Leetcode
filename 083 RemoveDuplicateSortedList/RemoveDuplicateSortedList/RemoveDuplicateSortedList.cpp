#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL){}
};

class Solution {
public:
	Solution(ListNode* h):head(h){}
    ListNode* deleteDuplicates(ListNode* head) 
	{
		if (head == NULL || head->next == NULL)
			return head;
		else
		{
			ListNode *temp_list=head;
			ListNode *temp_node=NULL;
			while(temp_list->next != NULL)
			{
				temp_node = temp_list->next;
				while (temp_list->val == temp_node->val && temp_node->next != NULL)
					temp_node = temp_node->next;
				if (temp_list->val != temp_node->val)
				{
					temp_list->next = temp_node;
					temp_list = temp_list->next;
				}
				else
					temp_list->next = NULL;
			}
			return head;
		}
        
    }
private:
	ListNode* head;
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

int main(void)
{
	int a[] = {1,1,1,1};
	ListNode *list = CreateList(a,sizeof(a)/sizeof(a[0]));
	Solution s(list);
	ListNode *result=s.deleteDuplicates(list);
	return 0;
}