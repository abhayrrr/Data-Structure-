struct TreeNode* newTreeNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct TreeNode* sortedListToBST(struct ListNode* head) {
    
    if (head == NULL)
        return NULL;

    
    if (head->next == NULL)
        return newTreeNode(head->val);

    
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    struct ListNode* prev = NULL;

    while (fast != NULL && fast->next != NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    
    if (prev != NULL)
        prev->next = NULL;

    
    struct TreeNode* root = newTreeNode(slow->val);

    
    root->left = sortedListToBST(head);
    root->right = sortedListToBST(slow->next);

    return root;
}