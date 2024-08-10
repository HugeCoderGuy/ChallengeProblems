
/*
71. Simplify Path
Medium
Topics
Companies
Given an absolute path for a Unix-style file system, which begins with a slash '/', transform this path into its simplified canonical path.

In Unix-style file system context, a single period '.' signifies the current directory, a double period ".." denotes moving up one directory level, and multiple slashes such as "//" are interpreted as a single slash. In this problem, treat sequences of periods not covered by the previous rules (like "...") as valid names for files or directories.

The simplified canonical path should adhere to the following rules:

It must start with a single slash '/'.
Directories within the path should be separated by only one slash '/'.
It should not end with a slash '/', unless it's the root directory.
It should exclude any single or double periods used to denote current or parent directories.
Return the new path.

 

Example 1:

Input: path = "/home/"

Output: "/home"

Explanation:

The trailing slash should be removed.


Example 2:

Input: path = "/home//foo/"

Output: "/home/foo"

Explanation:

Multiple consecutive slashes are replaced by a single one.

Example 3:

Input: path = "/home/user/Documents/../Pictures"

Output: "/home/user/Pictures"

Explanation:

A double period ".." refers to the directory up a level.

Example 4:

Input: path = "/../"

Output: "/"

Explanation:

Going one level up from the root directory is not possible.

Example 5:

Input: path = "/.../a/../b/c/../d/./"

Output: "/.../b/d"

Explanation:

"..." is a valid name for a directory in this problem.

My test cases:
"/home/"
"/home//foo/"
"/home/user/Documents/../Pictures"
"/.../a/../b/c/../d/./"
"/../"
*/ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG 0

struct Stack {
    int top;
    int capacity;
    char* array[3000];
};

struct Stack* createStack() {
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->capacity = 3000;
    stack->top = -1;
    return stack;
}

int isFull(struct Stack* stack) {
    if (stack->top == stack->capacity - 1) {
        return 1;
    }
    else {
        return 0;
        
    }
}

int isEmpty(struct Stack* stack) {
    if (stack->top == -1) {
        return 1;
    }
    else {
        return 0;
    }
}

void push(struct Stack* stack, char* item) {
    // Check if the stack is full
    if (isFull(stack)) {
        if (DEBUG) {
            printf("Stack is full!\n");
        }
        return;
    }
    if (DEBUG) {
        printf("%c Added to stack\n", *item);
    }
    stack->array[++stack->top] = item;
}

char* pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("The stack is empty. Can't pop\n");
    }
    char* popped = stack->array[stack->top--];

    if (DEBUG) {
        printf("%c Popped\n", *popped);
    }

    return popped; 
}

char* peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        return NULL;
    }
    else{
        char* char_ptr = stack->array[stack->top];
        if (DEBUG) {
            printf("%c peeped\n", *char_ptr);
        }
        return char_ptr;
    }

}

char* returnTheStack(struct Stack* stack) {

    char* final_out = (char*) malloc(stack->top * sizeof(stack->array[0]));


    char* original_addr = final_out;
    if (DEBUG) {
        printf("Here is the state of array %s", stack->array[0]);
    }

    for (int i=0; i<=stack->top; i++){
        *final_out = *stack->array[i];
        if (DEBUG) {
            printf("Added %c to final\n", *stack->array[i]);
        }
        final_out++;
    }
    for (int i=0; i<=stack->top; i++){
        final_out--;
    }
    if (DEBUG) {
        printf("%c is final\n", *final_out);
    }

    return final_out;
}

char* simplifyPath(char* path) {
    if (DEBUG) {
        printf("Testing against %s\n", path);
    }
    char *ptr;
    ptr = path;
    struct Stack* stack;
    stack = createStack();
    int dot_sequence = 0;

    // begin main alg
    while (*ptr != '\0') {
        if (DEBUG) {
            printf("PROCESSING: %c\n", *ptr);
        }

        if (peek(stack) != NULL) {
            if (*ptr == '/') {
                dot_sequence = 0;
                if (*peek(stack) == '/') {
                    if (DEBUG) {
                        printf("Found a non parathesis\n");
                    }
                    ptr++;
                    continue;
                    // push(stack, ptr);
                }
                // skip the double '/'
            }
            if ((*ptr == '.') & (*peek(stack) == '.') & !dot_sequence) {
                if (DEBUG) {
                    printf("Found a . on stack and . on pointer");
                }
                ptr++;
                if (*ptr != '.') {  // Check if this is a '..'
                    if (DEBUG) {
                        printf("Moving up a directory because of ..");
                    }
                    // We appear to have a .. up directory
                    char pop_val = 'a';
                    while (!isEmpty(stack) & (pop_val != '/')) {
                        pop_val = *pop(stack);
                    } // need one more pop cycle to get up
                    pop_val = 'a';
                    while (!isEmpty(stack) & (pop_val != '/')) {
                        pop_val = *pop(stack);
                    }
                }
                // Here we keep the dots in the name
                else {
                    ptr--;
                    dot_sequence = 1;  // lets add these dots to the path
                }
            }
        }

        push(stack, ptr);
        ptr++;
    }
    while (((*peek(stack) == '/') | (*peek(stack) == '.')) & (stack->top > 1)) {
        pop(stack);  // pop \0
    }
    if (isEmpty(stack)) {
        char* temp;
        *temp = '/';
        push(stack, temp);
    }
    push(stack, ptr);  // add the final \0 charecter
    if (DEBUG) {
        printf("The end val for stack is %d\n", (*stack->array[stack->top] == '\0'));
    }

    return returnTheStack(stack);

}

void test(char* input) {
    char* output = simplifyPath(input);
    printf("TEST RESULT\n\tInput: %s\n\tOutput: %s\n", input, output);
}

int main() {

    char *path_ptr = simplifyPath("/home/");
    test("/home/");
    test("/home//foo/");
    test("/home/user/Documents/../Pictures");
    test("/.../a/../b/c/../d/./");
    test("/../");
    test("/");
    test("/..../af/eeeefefefe/../hello");
    test("/a/./b/../../c/");  // "/c"

    return 0;
}
