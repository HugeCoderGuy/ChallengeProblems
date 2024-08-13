/**
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

 

Example 1:


Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: list1 = [], list2 = []
Output: []
Example 3:

Input: list1 = [], list2 = [0]
Output: [0]
 

Constraints:

The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both list1 and list2 are sorted in non-decreasing order.

 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdio.h>
#include <stdlib.h>

#define DEBUG 1
int MAX_VAL = 101;


struct ListNode* addToList(struct ListNode* list, int numb) {
    struct ListNode* next_node = (struct ListNode*)malloc(sizeof(struct ListNode));;
    next_node->val = numb; 
    next_node->next = NULL;  
    list->next = next_node;
    return next_node;
}



struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* result = (struct ListNode*)malloc(sizeof(struct ListNode));;
    struct ListNode* head = result;
    int comp1;
    int comp2;
    if (list1 == NULL) {
        result = list2;
        return result;
    }
    else if (list2 == NULL) {
        result = list1;
        return result;
    }

    // while ((list1->next != NULL) | (list2->next != NULL)) {
    while (list1 != NULL || list2 != NULL) {
        int comp1 = (list1 != NULL) ? list1->val : MAX_VAL;
        int comp2 = (list2 != NULL) ? list2->val : MAX_VAL;

        if ((comp1 < comp2) | ((comp1 != MAX_VAL) & (comp2 == MAX_VAL))) {
            head = addToList(head, comp1);
            list1 = list1->next;
        }
        else if ((comp1 > comp2) | ((comp2 != MAX_VAL) & (comp1 == MAX_VAL))) {
            head = addToList(head, comp2);
            list2 = list2->next;
        }
        else {
            if (comp1 == comp2) {
                head = addToList(head, comp1);
                list1 = list1->next;
            }
        }
    }
    result = result->next;  // skip the head
    return result;
}
