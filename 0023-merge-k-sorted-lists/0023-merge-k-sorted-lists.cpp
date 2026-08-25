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
class cmp {
public:
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val; // min heap
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;

        for (int i = 0; i < lists.size(); i++) {
            if(lists[i] != nullptr) {
                pq.push(lists[i]); // pushing the Node [val | nextaddress] in the heap
            }
        }

        // creating the resultant list
        ListNode* start = new ListNode(-1); // initial value is -1 and it's pointing to NULL
        ListNode* end = start;

        while (!pq.empty()) {
            ListNode* curr = pq.top();
            pq.pop();

            // Adding new node (curr) in the end of the resultant list
            end->next = curr;
            end = end->next;

            // pushing back in the heap
            if (curr->next != nullptr) {
                pq.push(curr->next);
            }
        }
        return start->next;
    }
};