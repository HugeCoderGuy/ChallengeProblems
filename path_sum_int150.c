/**
Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.

A leaf is a node with no children.

 

Example 1:


Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
Output: true
Explanation: The root-to-leaf path with the target sum is shown.
Example 2:


Input: root = [1,2,3], targetSum = 5
Output: false
Explanation: There two root-to-leaf paths in the tree:
(1 --> 2): The sum is 3.
(1 --> 3): The sum is 4.
There is no root-to-leaf path with sum = 5.
Example 3:

Input: root = [], targetSum = 0
Output: false
Explanation: Since the tree is empty, there are no root-to-leaf paths.
 

Constraints:

The number of nodes in the tree is in the range [0, 5000].
-1000 <= Node.val <= 1000
-1000 <= targetSum <= 1000

 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct StackNode {
    struct TreeNode* treeNode;
    int pathLength;
    struct StackNode* next;
};

struct Stack {
    struct StackNode* top;
};

void push(struct Stack* stack, struct TreeNode* treeNode, int pathLength) {
    struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    newNode->pathLength = pathLength + treeNode->val;
    newNode->treeNode = treeNode;
    newNode->next = stack->top;
    stack->top = newNode;
}

struct StackNode* pop(struct Stack* stack) {
    if (stack->top == NULL) {
        return NULL;
    }
    struct StackNode* temp = stack->top;
    if (temp->next != NULL) {
        stack->top = stack->top->next;
    }
    else {
        stack->top = NULL;
    }
    return temp;
}

bool isLeaf(struct TreeNode* treeNode) {
    if (treeNode->left == NULL && treeNode->right == NULL) {
        return true;
    }
    return false;
}

bool hasPathSum(struct TreeNode* root, int targetSum) {
    if (root == NULL) {
        return false;
    }
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = NULL;
    push(stack, root, 0);
    while (stack->top != NULL) {
        printf("%d", stack->top==NULL);
        struct StackNode* stackSpot = pop(stack);
        struct TreeNode* currentNode = stackSpot->treeNode;
        printf("Checking node %d. This node is leaf: %d. Path is %d\n", currentNode->val, isLeaf(currentNode), stackSpot->pathLength);

        if (isLeaf(currentNode)) {
            if (stackSpot->pathLength == targetSum) {
                return true;
            }
            else {
                printf("This is not the leaf we're looking for");
                continue;
            }
        }
        printf("about to hvae error");

        if (currentNode->right != NULL) {
            push(stack, currentNode->right, stackSpot->pathLength);
        }
        if (currentNode->left != NULL) {
            push(stack, currentNode->left, stackSpot->pathLength);
        }
    }

    return false;
}
