//PROBLEM 144
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int* result = malloc(100 * sizeof(int));
    struct TreeNode* stack[100];
    int top = -1;
    *returnSize = 0;

    if (root != NULL) {
        stack[++top] = root;
    }

    while (top >= 0) {
        struct TreeNode* node = stack[top--];

        
        result[(*returnSize)++] = node->val;

        
        if (node->right) {
            stack[++top] = node->right;
        }

        if (node->left) {
            stack[++top] = node->left;
        }
    }
    return result;
}




///PROBLEM 94

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* result = malloc(100 * sizeof(int));
    struct TreeNode* stack[100]; 
    int top = -1;                 
    *returnSize = 0;

    struct TreeNode* current = root;

    while (current != NULL || top >= 0) {
    
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }

        
        current = stack[top--];

       
        result[(*returnSize)++] = current->val;

       
        current = current->right;
    }

    return result;
}









