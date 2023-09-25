/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 != nullptr && list2 != nullptr) {
            ListNode* ret_ptr;
            if (list1->val <= list2->val) {
                ret_ptr = list1;
                list1 = list1->next;
            }
            else {
                ret_ptr = list2;
                list2 = list2->next;
            }
            ret_ptr->next = mergeTwoLists(list1, list2);
            return ret_ptr;
        }
        if (list1 != nullptr) return list1;
        else return list2;
    }
};