using namespace std;

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* currl1 = l1;
        ListNode* currl2 = l2;
        ListNode* firstNode = nullptr;
        ListNode* prevNode = nullptr;
        ListNode* newNode = nullptr;

        int carry = 0;
        while(currl1 != nullptr && currl2 != nullptr){
            int currSum = currl1->val + currl2->val + carry;
            carry = currSum / 10;
            currSum -= (carry * 10);

            newNode = new ListNode(currSum);
            if(!firstNode){
                firstNode = newNode;
            }
            if(prevNode){
                prevNode->next = newNode;
            }
            prevNode = newNode;

            currl1 = currl1->next;
            currl2 = currl2->next;
        }


        if(currl1 == nullptr && currl2 == nullptr){
            if(carry){
                newNode = new ListNode(carry);
                prevNode->next = newNode;
            }
            return firstNode;
        }

        ListNode* curr = currl1 != nullptr ? currl1 : currl2;
        while(curr != nullptr){
            int currSum = curr->val + carry;
            carry = currSum / 10;
            currSum -= (carry*10);

            newNode = new ListNode(currSum);
            if(prevNode){
                prevNode->next = newNode;
            }
            prevNode = newNode;
            curr = curr->next;
        }
        if(carry){
            newNode = new ListNode(carry);
            prevNode->next = newNode;
        }
        return firstNode;
    }
};












