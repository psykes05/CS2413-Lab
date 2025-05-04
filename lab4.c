/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isMirror(struct TreeNode* leftTree, struct TreeNode* rightTree) {
    if (leftTree == NULL && rightTree == NULL) {
        return true;
    }
    if (leftTree == NULL || rightTree == NULL) {
        return false;
    }
    return (leftTree->val == rightTree->val) &&
           isMirror(leftTree->left, rightTree->right) &&
           isMirror(leftTree->right, rightTree->left);
}

bool isSymmetric(struct TreeNode* root) {
    if (root == NULL) {
        return true;
    }
    return isMirror(root->left, root->right);
}






void dfs(char** grid, int gridSize, int* gridColSize, int i, int j) {
    if (i < 0 || i >= gridSize || j < 0 || j >= gridColSize[i] ||
    grid[i]       [j]    == '0') {
        return;
    }

    grid[i][j] = '0'; 

    dfs(grid, gridSize, gridColSize, i + 1, j);
    dfs(grid, gridSize, gridColSize, i - 1, j);
    dfs(grid, gridSize, gridColSize, i, j + 1);
    dfs(grid, gridSize, gridColSize, i, j - 1);
}

int numIslands(char** grid, int gridSize, int* gridColSize) {
    if (gridSize == 0) {
        return 0;
    }

    int num_islands = 0;
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {
            if (grid[i][j] == '1') {
                dfs(grid, gridSize, gridColSize, i, j);
                num_islands++;
            }
        }
    }
    return num_islands;
}
