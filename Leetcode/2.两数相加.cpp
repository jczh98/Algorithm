/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

// @lc code=start
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
// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *result = new ListNode();
        ListNode *head = result;
        int advance = 0;
        while (l1 != nullptr && l2 != nullptr)
        {
            int value = l1->val + l2->val;
            if (advance)
            {
                value += 1;
                advance = 0;
            }
            if (value > 9)
            {
                value %= 10;
                advance = 1;
            }
            ListNode *cur = new ListNode(value);
            head->next = cur;
            head = head->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1 != nullptr)
        {
            int value = l1->val;
            if (advance)
            {
                value += 1;
                advance = 0;
            }
            if (value > 9)
            {
                value %= 10;
                advance = 1;
            }
            ListNode *cur = new ListNode(value);
            head->next = cur;
            head = head->next;
            l1 = l1->next;
        }
        while (l2 != nullptr)
        {
            int value = l2->val;
            if (advance)
            {
                value += 1;
                advance = 0;
            }
            if (value > 9)
            {
                value %= 10;
                advance = 1;
            }
            ListNode *cur = new ListNode(value);
            head->next = cur;
            head = head->next;
            l2 = l2->next;
        }
        if (advance) {
            head->next = new ListNode(1);
        }
        return result->next;
    }
};
// @lc code=end
