Node tree(3);
    tree.left = new TreeNode(4);
    tree.right = new TreeNode(5);
    tree.left->left = new TreeNode(1);
    tree.left->right = new TreeNode(2);
    tree.left->right->left = new TreeNode(0);

    TreeNode subtree(4);
    subtree.left = new TreeNode(1);
    subtree.right = new TreeNode(2);