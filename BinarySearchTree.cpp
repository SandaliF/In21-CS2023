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
struct node *insertNode(struct node *root, int key) {
    // Returning a new node if the tree is empty
    if (root == NULL) {
        struct node* newNode = new struct node;
        newNode->key = key;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }

    // Recurring down the tree if the tree is not empty
    else if (key <= root->key)
        root->left = insertNode(root->left, key);
    else 
        root->right = insertNode(root->right, key);
    return root;
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
    if (root == NULL) {
      return NULL;
    }

    if (key < root->key)
        root->left = deleteNode(root->left, key);

    else if (key > root->key)
        root->right = deleteNode(root->right, key);

    else {
        if (root->left == NULL && root->right == NULL) {
            //If Node has no children
            delete root;
            return NULL;
        } else if (root->right == NULL || root->right == NULL) {
            //If Node has one child
            struct node *temp = root->left ? root->left : root->right;
            delete root;
            return temp;
        }
        else{
          //If node has two children
          struct node* temp = root->right;

          while (temp->left != NULL){
            temp =temp->left;
          }

          root->key = temp->key;
          root->right = deleteNode(root->right,temp->key);
        }
    
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