#include <iostream>
using namespace std;

// Definition of a Tree Node
struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

// Function to create a new node
TreeNode* createNode(int value) {
    return new TreeNode(value);
}

// Function to build a tree
TreeNode* buildTree() {
    int value;
    cout << "Enter value (-1 for no node): ";
    cin >> value;

    if (value == -1) {
        return nullptr; // No node to create
    }

    TreeNode* node = createNode(value);
    cout << "Enter left child of " << value << ":\n";
    node->left = buildTree();
    cout << "Enter right child of " << value << ":\n";
    node->right = buildTree();

    return node;
}

// Inorder Traversal (Left -> Root -> Right)
void inorderTraversal(TreeNode* root) {
    if (root == nullptr) return;
    inorderTraversal(root->left);
    cout << root->value << " ";
    inorderTraversal(root->right);
}

// Preorder Traversal (Root -> Left -> Right)
void preorderTraversal(TreeNode* root) {
    if (root == nullptr) return;
    cout << root->value << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Postorder Traversal (Left -> Right -> Root)
void postorderTraversal(TreeNode* root) {
    if (root == nullptr) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->value << " ";
}

int main() {
    cout << "Create the binary tree:\n";
    TreeNode* root = buildTree();

    cout << "\nInorder Traversal: ";
    inorderTraversal(root);
    cout << "\nPreorder Traversal: ";
    preorderTraversal(root);
    cout << "\nPostorder Traversal: ";
    postorderTraversal(root);
    cout << endl;

    return 0;
}
