#include "binary_search_tree.h"

template <typename KeyType, typename ItemType>
BinarySearchTree<KeyType, ItemType>::BinarySearchTree()
{
    root = 0;
}

template <typename KeyType, typename ItemType>
BinarySearchTree<KeyType, ItemType>::BinarySearchTree(
    const BinarySearchTree<KeyType, ItemType>& rhs)
{
    root = 0;
    clone(rhs.root);
}

// this is an alternative implementation using a stack to simulate the recursion
template <typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::clone(Node<KeyType, ItemType>* rhs)
{
    Node<KeyType, ItemType>** lhs = &root;

    std::stack<stackvar<KeyType, ItemType>> s;

    stackvar<KeyType, ItemType> rootvar;
    rootvar.rhs = rhs;
    rootvar.lhs = lhs;
    s.push(rootvar);

    while (!s.empty()) {
        stackvar<KeyType, ItemType> currentvar = s.top();
        s.pop();

        Node<KeyType, ItemType>* curr_rhs = currentvar.rhs;
        Node<KeyType, ItemType>** curr_lhs = currentvar.lhs;

        if (curr_rhs == 0)
            continue;

        // allocate new node and copy contents
        Node<KeyType, ItemType>* temp = new Node<KeyType, ItemType>;
        temp->key = curr_rhs->key;
        temp->data = curr_rhs->data;
        temp->left = 0;
        temp->right = 0;
        *curr_lhs = temp;

        // push left subtree
        currentvar.rhs = curr_rhs->left;
        currentvar.lhs = &((*curr_lhs)->left);
        s.push(currentvar);

        // push right subtree
        currentvar.rhs = curr_rhs->right;
        currentvar.lhs = &((*curr_lhs)->right);
        s.push(currentvar);
    }
}

template <typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::destroy()
{
    std::stack<Node<KeyType, ItemType>*> s;
    s.push(root);

    while (!s.empty()) {
        Node<KeyType, ItemType>* curr = s.top();
        s.pop();

        if (curr != 0) {
            s.push(curr->left);
            s.push(curr->right);
            delete curr;
        }
    }
    root = 0;
}

template <typename KeyType, typename ItemType>
BinarySearchTree<KeyType, ItemType>& BinarySearchTree<KeyType, ItemType>::
operator=(const BinarySearchTree<KeyType, ItemType>& rhs)
{
    if (&rhs == this)
        return *this;

    destroy();

    root = 0;
    clone(rhs.root);

    return *this;
}

template <typename KeyType, typename ItemType>
BinarySearchTree<KeyType, ItemType>::~BinarySearchTree()
{
    destroy();
}

template <typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType, ItemType>::insert(
    const KeyType& key, const ItemType& item)
{
     if (root == 0){
         root = new Node<KeyType, ItemType>;
         root->key = key;
         root->data = item;
         return true;
     }
    else{
     Node<KeyType, ItemType>* curr;
    Node<KeyType, ItemType>* curr_parent;
    search(key, curr, curr_parent);
    if (curr->key == key)
    return false;
    else if ( key < curr->key){
    curr_parent = new Node<KeyType, ItemType>;
    curr_parent->key = key;
    curr_parent->data = item;
    curr->left = curr_parent;
    return true;
    }
    else{
    curr_parent = new Node<KeyType, ItemType>;
    curr_parent->key = key;
    curr_parent->data = item;
    curr->right = curr_parent;
    return true;
    }
}
}

template <typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType, ItemType>::isEmpty()
{
    return (root == 0);
}

template <typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType, ItemType>::retrieve(
    const KeyType& key, ItemType& item)
{
    Node<KeyType, ItemType>* curr;
    Node<KeyType, ItemType>* curr_parent;
    search(key, curr, curr_parent);

    if (curr == 0)
        return false;

    if (curr->key == key) {
        item = curr->data;
        return true;
    }

    return false;
}

template <typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType, ItemType>::remove(KeyType key)
{
    if (isEmpty())
        return false; // empty tree

    Node<KeyType, ItemType>* curr;
    Node<KeyType, ItemType>* curr_parent;
    search(key, curr, curr_parent);


    // case one thing in the tree
    if (curr == root)
    {
        delete root;
        root = 0;
        return true;
    }
    // case, found deleted item at leaf
    else if ( curr->left == 0 && curr->right == 0)
    {
        if ( curr->key > curr_parent->key)
        {
            delete curr;
            curr_parent->right =  0;
            return true;
        }
        else 
        {
            delete curr;
            curr_parent->left = 0;
            return true; 
        }
    }
    // case, item to delete has only a right child
    else if ( curr->left == 0)
    {
         if ( curr->key > curr_parent->key)
        {
            curr_parent->right =  curr->right;
            delete curr;
            return true;
        }
        else 
        {
            curr_parent->left = curr->right;
            delete curr;
            return true;
        }
    }

    // case, item to delete has only a left child
    else if ( curr->right == 0)
    {
         if ( curr->key > curr_parent->key)
        {
            curr_parent->right =  curr->left;
            delete curr;
            return true;
        }
        else 
        {
            curr_parent->left = curr->left;
            delete curr;
            return true;
        }
    }
    // case, item to delete has two children
    else
    {
        curr_parent = curr->right;
        while (curr_parent->left != 0)
        curr_parent = curr_parent->left;
        curr->data = curr_parent->data;
        delete curr_parent;
        curr_parent = 0;
        return true;
    }
    return false; // default should never get here
}

template <typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::inorder(Node<KeyType, ItemType>* curr,
    Node<KeyType, ItemType>*& in, Node<KeyType, ItemType>*& parent)
{
    if (parent->left != 0)
    {
        in = parent->left;
        while (in->left != 0)
        in = in->left;
    }
    else if (parent->right != 0)
    {
        curr = parent->right;
        in = curr->left;
        while ( in->left != 0)
        in = in->left;
    }
    else 
    in = parent;
}

template <typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::search(KeyType key,
    Node<KeyType, ItemType>*& curr, Node<KeyType, ItemType>*& parent)
{
    curr = root;
    parent = 0;

    if (isEmpty())
        return;

    while (true) {
        if (key == curr->key) {
            break;
        } else if (key < curr->key) {
            if (curr->left != 0) {
                parent = curr;
                curr = curr->left;
            } else
                break;
        } else {
            if (curr->right != 0) {
                parent = curr;
                curr = curr->right;
            } else
                break;
        }
    }
}

template<typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::treeSort(ItemType arr[], int size) {
    // TODO: check for duplicate items in the input array
    int i, j;
    for (i = 0; i < size-1; i ++){
        j = i + 1;
        while( j < size)
        {
            if (arr[i]==arr[j])
            return;
            j++;
        }
    }
    // TODO: use the tree to sort the array items
    for (i = 0 ; i < size ; i++){
    KeyType k = arr[i];
    insert(k,arr[i]);}
    // TODO: overwrite input array values with sorted values
     Node<KeyType, ItemType>* curr = 0;
     Node<KeyType, ItemType>* ino = 0;
    Node<KeyType, ItemType>* curr_parent = root;

    for(i = 0; i < size; i++)
    {
        inorder(curr,ino, curr_parent);
        arr[i] = ino->data;
        remove(ino->key);
    }
    
    
}
