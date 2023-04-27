#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// Inorder traversal
void traverseInOrder(struct node *root) {
  if (root != NULL) {
    traverseInOrder(root->left);
    cout << root->key << " ";
    traverseInOrder(root->right);
  }
  return ;
}

// Insert a node
struct node *insertNode(struct node *node, int key) {
    // If the tree is empty, return a new node
    if (node == NULL) {
        node = new struct node;
        node->key = key;
        node->left = NULL;
        node->right = NULL;
    }

    // Otherwise, recur down the tree
    else if (key < node->key)
        node->left = insertNode(node->left, key);
    else if (key > node->key)
        node->right = insertNode(node->right, key);

    // Return the pointer to the updated node
    return node;
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
    // Base case
    if (root == NULL) return root;

    // Recur down the tree
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct node *temp = root->right;
            delete(root);
            return temp;
        } else if (root->right == NULL) {
            struct node *temp = root->left;
            delete(root);
            return temp;
        }

        // Node with two children
        struct node *temp = root->right;
        while (temp->left != NULL)
            temp = temp->left;

        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);        
    }

    // Return the pointer to the updated node
    return root;
}

// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }
  
  traverseInOrder(root);
}