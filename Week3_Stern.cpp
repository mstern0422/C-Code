#include <iostream>

using namespace std;

class Node
{
public:
    int value;
    Node* left;
    Node* right;
    // Node constructor
    Node (int num)
    {
        value = num;
        left = nullptr;
        right = nullptr;
    }
};

class BinaryTree
{
public:
// Creates a binary tree object with a null/empty root 
    Node* root;
    BinaryTree():root(nullptr){}
// Function to add a new value to a binary tree object
    void AddValueToTree(int key)
    {
        root = AddValueToTreeHelper(root, key);
    }
// AddValueToTreeHelper keeps function from looping forever
    Node* AddValueToTreeHelper(Node* root, int key)
    {
        // If root is null (empty), the assigns given value as the root
        if(root == nullptr)
        {
          root = new Node(key);
          return root;
        }
        // If tree has a root, adds value to the left or right of the tree
        if(key < root -> value)
        {
          root -> left = AddValueToTreeHelper(root -> left, key);
        } 
        else 
        {
          root -> right = AddValueToTreeHelper(root -> right, key);
        }
        return root;
    }
// Function to dispaly tree in order
  void DisplayTree_LNR(Node *n)
  {
    if (n->left != nullptr)
      DisplayTree_LNR(n->left);
    cout << n->value;
    if (n->right != nullptr)
      DisplayTree_LNR(n->right);
  }
// Function to display tree in pre-order
  void DisplayTree_NLR(Node *n)
  {
  cout << n->value;
  if (n->left != nullptr)
      DisplayTree_NLR(n->left);
  if (n->right != nullptr)
      DisplayTree_NLR(n->right);
  }
// Function to display tree in post-order
  void DisplayTree_LRN(Node *n)
  {
  if (n->left != nullptr)
      DisplayTree_LRN(n->left);
  if (n->right != nullptr)
      DisplayTree_LRN(n->right);
  cout << n->value;
  }
};

int main()
{
    BinaryTree T;
    T.AddValueToTree(100);
    T.AddValueToTree(50);
    T.AddValueToTree(150);
    T.DisplayTree_LNR(T.root); // this should display 50 100 15
    T.DisplayTree_NLR(T.root); // this should display 100 50 150
    T.DisplayTree_LRN(T.root); // this should display 50 150 100

    return 0;
}