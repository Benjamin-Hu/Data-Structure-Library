#ifndef A3_BINARY_SEARCH_TREE_HPP
#define A3_BINARY_SEARCH_TREE_HPP

class BinarySearchTree {
public:
  struct Node {
    // Sets the left and right children to NULL, and initializes val.
    Node(int new_val);
    
    int val;  // Value of the node.
    Node* left;    // Pointer to the left node.
    Node* right;   // Pointer to the right node.
  };

private:
  friend class BinarySearchTreeTest;

  // Pointer to the root node of the tree.
  Node* root_;
  
  // Number of nodes in the tree.
  unsigned int size_;

  // Optional helper function that recursively gets the maximum depth for a given node. 
  int getNodeDepth(Node* n) const;
  
public:
  // Default constructor to initialize the tree and set root_ to NULL.
  BinarySearchTree();
  // Destructor of the class BinarySearchTree. 
  // It deallocates the memory space allocated for the binary search tree. 
  ~BinarySearchTree();
  
  // Returns the number of nodes in the tree. 
  unsigned int size() const;
  // Returns the maximum value of a node in the tree. 
  // You can assume that this function will never be called on an empty tree.
  int max() const;
  // Returns the minimum value of a node in the tree. 
  // You can assume that this function will never be called on an empty tree.
  int min() const;
  // Returns the maximum depth of the tree. 
  // A tree with only the root node has a depth of 0. 
  // You can assume that this function will never be called on an empty tree.
  unsigned int depth() const;
  // You can print the tree in whatever order you prefer. However, methods such 
  // as in-order or level-order traversal could be the most useful for debugging.
  void print() const;
  // Returns true if a node with the value val exists in the tree; 
  // otherwise, it returns false.
  bool exists(int val) const;
  // Helper function. Returns a pointer to the root node.
  Node* getRootNode();
  // Helper function. Returns the root node pointer address.
  Node** getRootNodeAddress();
  
  // Inserts the value val into the tree. 
  // Returns false if val already exists in the tree, and true otherwise.
  bool insert(int val);
  // Removes the node with the value val from the tree. 
  // Returns true if successful, and false otherwise.
  bool remove(int val);
};
#endif
