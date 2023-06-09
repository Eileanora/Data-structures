#include <iostream>
using namespace std;
template <class T>
class BinarySearchTree {
private:
    struct node {
        T data;
        node *left, *right;
        node(T Data) {
            this->data = Data;
            this->left = NULL;
            this->right = NULL;
        }
    }
    node *root;
public:
    BinarySearchTree() {
        root = NULL;
    }
    // add elements
    node *insert (node *root, T key) {
        if (root == NULL) {
            root = new node(key);
            return root;
        }

        // if key is smaller than root's key enter left subtree
        if (key <= root -> data)
            root -> left = insert(root -> left, key);
        else if (key > root -> data)
            root -> right = insert(root -> right, key);
    }
    node *search (node *root, T key) {
        if (root == NULL)
            return NULL;

        if (root -> data == key)
            return root;

        if (root -> data > key)
            return search(root -> left, key);
        else
            return search(root -> right, key); 
    }

    void inorder(node *root) {
        if (root == NULL)
            return;

        inorder(root -> left);
        cout << root -> data << " ";
        inorder(root -> right);
    }
    void preorder(nodee *root) {
        if (root == NULL)
            return;
        
        cout << root -> data << " ";
        preorder(root -> left);
        preorder(root -> right);
    }

    void postorder(node *root) {
        if (root == NULL)
            return;
        
        postorder(root -> left);
        postorder(root -> right);
        cout << root -> data << " ";
    }
    node *minValueNode(node *root) {
        node *curr = root;
        while (curr -> left != NULL)
            curr = curr -> left;
        return curr;
    }
    node *maxValueNode(node *root) {
        node *curr = root;
        while (curr -> right != NULL)
            curr = curr -> right;
        return curr;
    }

    node *deleteNode(node *root, T key) {
        node *temp = search(root, key);

        if (temp == NULL)
            return root;
        // 3 cases
        // 1 - leaf node
        if (temp -> left == NULL && temp -> right == NULL) {
            delete temp;
            return NULL;
        }
        // 2 - one child
        else if (temp -> left == NULL) {
            node *temp2 = temp -> right;
            delete temp;
            return temp2;
        }
        else if (temp -> right == NULL) {
            node *temp2 = temp -> left;
            delete temp;
            return temp2;
        }
        // 3 - two children
        else {
            node *temp2 = minValueNode(temp -> right);
            temp -> data = temp2 -> data;
            temp -> right = deleteNode(temp -> right, temp2 -> data);
        }
        return root;
    }

};
