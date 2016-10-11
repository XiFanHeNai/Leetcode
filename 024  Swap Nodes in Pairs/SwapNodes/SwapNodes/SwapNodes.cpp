#include <iostream>
using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
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
		ListNode* Node = new ListNode(0);
		Node->val = a[index];
		Node->next = NULL;
		
		temp->next = Node;
		temp = temp->next;
	}
	return head;
}

class Solution {
public:
	Solution(ListNode* l1):head(l1){}
    ListNode* swapPairs(ListNode* head) 
	{
		if (head == NULL || head->next == NULL)
			return head;
		else
		{
			ListNode* temp_node=NULL;
			ListNode* temp_list = new ListNode(0);
			temp_list->next = head;
			ListNode* result = head->next;

			while(temp_list->next != NULL && temp_list->next->next != NULL)
			{
				temp_node = temp_list->next;
				temp_list->next = temp_list->next->next;
				temp_node->next = temp_list->next->next;
				temp_list->next->next = temp_node;

				temp_list = temp_list->next->next;
			}
			return result;
		}
    }
private:
	ListNode* head;
};

int main(void)
{
	int a[] = {1,2,3};
	ListNode * list1 = CreateList(a,sizeof(a)/sizeof(a[0]));
	Solution s(list1);
	ListNode* result = s.swapPairs(list1);
	return 0;
}