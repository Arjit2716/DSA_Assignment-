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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int>vals;
        for(auto l : lists){
            while(l){
                vals.push_back(l->val);
                l=l->next;
            }
        }
        sort(vals.begin(),vals.end());
        ListNode*dummy=new ListNode(0);
        ListNode*tail=dummy;
        for(int val : vals) {
            tail->next = new ListNode(val);
            tail = tail->next;
        }
        return dummy->next;
    }
};