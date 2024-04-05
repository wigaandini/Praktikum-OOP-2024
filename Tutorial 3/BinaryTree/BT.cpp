#include "BinaryTree.hpp"

int main(){
//     BinaryTree<int> tree;
//     tree.setValue(5);
//     tree.addChild(7);
//     tree.addChild(6);
//     cout << tree << endl;
//     BinaryTree<int> tree2 = tree;
//     cout << tree2 << endl;
// }
// 5(7()())(6()())
// 5(7()())(6()())


    BinaryTree<int> tree;
    
    // Set the value of the root node
    tree.setValue(5);

    // Add two children nodes
    try {
        tree.addChild(7);
        tree.addChild(6);
    } catch (const char* msg) {
        std::cerr << "Exception caught: " << msg << std::endl;
    }

    // Print the binary tree
    std::cout << "Binary Tree: " << tree << std::endl;

    return 0;
}