/*
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
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdio.h>
#include <stdlib.h>

#define DEBUG 1
int MIN_VAL = -101;

struct ListNode {
    int val;
    struct ListNode *next;
};

#include <stdio.h>
#include <stdlib.h>

#define DEBUG 1
int MIN_VAL = -101;


struct ListNode* addToList(struct ListNode* list, int numb) {
    struct ListNode* next_node = (struct ListNode*)malloc(sizeof(struct ListNode));;
    next_node->next = NULL;  // ERROR HERE
    list->val = numb;
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

    while ((list1->next != NULL) & (list2->next != NULL)) {
        if (list1->next != NULL) {
            comp1 = list1->val;
        }
        else {
            comp1 = MIN_VAL;
        }
        if (list2->next != NULL) {
            comp2 = list2->val;
        }
        else{
            comp2 = MIN_VAL;
        }
        if ((comp1 > comp2) | ((comp1 != MIN_VAL) & (comp2 == MIN_VAL))) {
            printf("Adding list 1 val %d\n", comp1);
            head = addToList(head, comp1);
            list1 = list1->next;
        }
        else if ((comp1 < comp2) | ((comp2 != MIN_VAL) & (comp1 == MIN_VAL))) {
            printf("Adding list 2 val %d\n", comp2);
            head = addToList(head, comp2);
            list2 = list2->next;
        }
        else {
            if (comp1 == comp2) {
                printf("Caught a comp=comp. numb1 is %d. numb2 id %d\n", comp1, comp2);
                head = addToList(head, comp1);
                list1 = list1->next;
            }
        }
    }
    return result;
}

void test(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* next_node = list1;
    printf("TESTING\n\tInput1: ");
    while (next_node->next != NULL) {
        printf("%d ", next_node->val);
        next_node = next_node->next;
    }
    printf("\n\tInput 2: ");
    next_node = list2;
    while (next_node->next != NULL) {
        printf("%d ", next_node->val);
        next_node = next_node->next;
    }

    printf("\n\tOutput: ");
    next_node = mergeTwoLists(list1, list2);
    while (next_node->next != NULL) {
        printf("%d ", next_node->val);
        next_node = next_node->next;
    }
    
}

int main() {
    struct ListNode* list1;
    struct ListNode* list2;
    struct ListNode* head;
    int i = 0;

    head = list1;
    for (i=0; i<6; i++) {
        head = addToList(head, i);
    }
    head = list2;
    for (i=0; i<6; i++) {
        head = addToList(head, i);
    }
    test(list1, list2);

    return 0;
}

/*
list1 =
[1,2,4]
list2 =
[1,3,4]
[1,1,2,3,4,4]


list2 =
[]
Output
[]

list1 =
[]
list2 =
[0]
Output
[0]
*/
