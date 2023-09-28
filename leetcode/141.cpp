// 141. Linked List Cycle

/* Flyod's Cycle Finding Algorithm */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr) return false;

        ListNode *slow = head, *fast = head->next;
        while (slow != nullptr && fast != nullptr) {
            if (slow == fast) return true;
            if (fast->next == nullptr) return false;
            slow = slow->next;
            fast = fast->next->next;
        }

        return false;
    }
};
