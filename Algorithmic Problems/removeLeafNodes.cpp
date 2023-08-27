TreeNode* removeLeafNodes(TreeNode* root, int target) {
    post(root, target);
    if(root->val == target && root->left == NULL && root->right == NULL) return NULL;
    return root;
}
void post(TreeNode* root, int target) {
    if(root == NULL) return;
    post(root->left, target);
    post(root->right, target);
    if(root->left != NULL && root->left->left == NULL && root->left->right == NULL && root->left->val == target) {
        delete(root->left);
        root->left = NULL;
    }
    if(root->right != NULL && root->right->left == NULL && root->right->right == NULL && root->right->val == target) {
        delete(root->right);
        root->right = NULL;
    }
}
