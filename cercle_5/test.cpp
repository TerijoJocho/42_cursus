#include <iostream>
#include <string>

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        ListNode*   mergeTwoLists = new ListNode();
        ListNode*   tmp = mergeTwoLists;

        while (list1 && list2)
        {
            // std::cout << "list1->val= " << list1->val << " ; " << "list2->val= " << list2->val << std::endl;
            if (list1->val < list2->val) 
            {
                tmp->val = list1->val;
                // std::cout << "if,merge->val= " << tmp->val << std::endl;
                tmp->next = new ListNode();
                tmp = tmp->next;
                tmp->val = list2->val;
                // std::cout << "if,merge->next->val= " << tmp->val << std::endl;
            }
            else
            {
                tmp->val = list2->val;
                // std::cout << "else,merge->val= " << tmp->val << std::endl;
                tmp->next = new ListNode();
                tmp = tmp->next;
                tmp->val = list1->val;   
                // std::cout << "else,merge->next->val= " << tmp->val << std::endl;
            }
            list1 = list1->next;
            list2 = list2->next;
            if (list1 && list2)
            {
                tmp->next = new ListNode();
                tmp = tmp->next;
            }
        }
        return mergeTwoLists;
    }
};

int main()
{
    Solution s;
    ListNode*   list1 = new ListNode();
    // list1->next = new ListNode(2);
    // list1->next->next = new ListNode(4);
    ListNode*   list2= new ListNode();
    // list2->next = new ListNode(3);
    // list2->next->next = new ListNode(4);

    ListNode* tmp = list1;
    std::cout << "list1: ";
    while (tmp) {
        std::cout << tmp->val;
        tmp = tmp->next;
    }
    std::cout << "\n";

    tmp = list2;
    std::cout << "list2: ";
    while (tmp) {
        std::cout << tmp->val;
        tmp = tmp->next;
    }
    std::cout << "\n";

    tmp = s.mergeTwoLists(list1, list2);
    std::cout << "merge list: ";
    while (tmp) {
        std::cout << tmp->val;
        tmp = tmp->next;
    }
}