class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans={-1,-1};
        if (head==nullptr||head->next==nullptr|| head->next->next==nullptr)
            return ans;

        ListNode* prev=head;
        ListNode* curr=head->next;
        int pos=1, f=-1,l=-1,minDist=INT_MAX;

        while (curr->next!=nullptr) {
            if ((curr->val>prev->val &&curr->val>curr->next->val)||(curr->val<prev->val&&curr->val<curr->next->val)) {
                if (f==-1)
                    f=pos;
                else 
                    minDist=min(minDist,pos-l);

                l=pos;
            }
            prev=curr;
            curr=curr->next;
            pos++;
        }
        if (f==l)
            return ans;

        ans[0]=minDist;ans[1]=l-f;

        return ans;
    }
};