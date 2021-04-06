#include <iostream>
using std::cout;
using std::endl;

#include "BinaryTree.h"

typedef std::string ItemType;
typedef void (*FunctionType)(ItemType& anItem);

void PrintNode(ItemType& i) { cout << i << endl; };

int main(int argc, char** argv)
{
    BinaryTree<ItemType, FunctionType> T1("B");
    BinaryTree<ItemType, FunctionType> T2("C");
    BinaryTree<ItemType, FunctionType> T4("D");
    BinaryTree<ItemType, FunctionType> T5("E");
    BinaryTree<ItemType, FunctionType> T6("F");
    BinaryTree<ItemType, FunctionType> T7("G");
    BinaryTree<ItemType, FunctionType> T3("A");
    T1.attachLeftSubtree(T4);
    T2.attachLeftSubtree(T6);
    T1.attachRightSubtree(T5);
    T2.attachRightSubtree(T7);
    T3.attachLeftSubtree(T1);
    T3.attachRightSubtree(T2);
    T3.postorderTraverse(&PrintNode);
    T3.preorderTraverse(&PrintNode);
    T3.inorderTraverse(&PrintNode);

    // now T1 and T2 are no longer trees, but empty objects

    return 0;
};
