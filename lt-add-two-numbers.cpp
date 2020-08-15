#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    Solution() {}
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            int sum = (l1 ? l1 -> val: 0) + (l2 ? l2 -> val: 0);
            int sumAdj = sum % 10;
            int carry = sum >= 10 ? 1 : 0;

            ListNode* solnStart = new ListNode(sumAdj);
            ListNode* soln = solnStart;

            l1 = l1 ?   l1 -> next : l1;
            l2 = l2 ?   l2 -> next : l2;

            while(l1 && l2)
            {
                sum = l1 -> val + l2 -> val + carry;
                l1 = l1 -> next;
                l2 = l2 -> next;
                sumAdj = sum % 10;
                carry = sum / 10;
                solnStart -> next = new ListNode(sumAdj);
                solnStart = solnStart -> next;
            }

            while(l1)
            {
                sum = l1 -> val + carry;
                sumAdj = sum % 10;
                carry = sum / 10;
                solnStart -> next = new ListNode(sumAdj);
                solnStart = solnStart -> next;
                l1 = l1 -> next;
            }

            while(l2)
            {
                sum = l2 -> val + carry;
                sumAdj = sum % 10;
                carry = sum / 10;
                solnStart -> next = new ListNode(sumAdj);
                solnStart = solnStart -> next;
                l2 = l2 -> next;
            }

            if (carry)
            {
                solnStart -> next = new ListNode(carry);
            }
    
            return soln;
    }
};

int main()
{
    ListNode* l1  = new ListNode(2);
    l1 -> next = new ListNode(4);
    l1 -> next -> next = new ListNode(4);


    ListNode* l2  = new ListNode(5);
    l2 -> next = new ListNode(6);
    l2 -> next -> next = new ListNode(4);

    Solution slm;
    ListNode* soln = slm.addTwoNumbers(l1, l2);
    return 0;
}