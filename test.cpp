#include <iostream>
#include <math.h>
#include "complex.h"
#include "Tree.h"

template <class T>
T rdElem(T item) {
    return item * 2;
}
int main() {
    int array[] = {1,2,3,'-','-',4,'-','-',5,6,'-','-','-'}; 
    int array2[] = {'-', '-', 3, '-', '-', 4, 2, '-', '-', 6, '-', 5, 1}; 
    Tree<int> tree(array, '-');
    Tree<int> tree3(array, '-');
    tree3.Traversal("LSR");
    if (tree == tree3)
    {
        std::cout << "good\n";
    }
    
    ///Tree<int> tree2(array2, '-');
    tree.Traversal();
   ////Tree tree2(tree)
    tree.Traversal("RSL");
    Tree<int> tree2(tree);
    std::cout << tree.Size() << "\n";
    ////tree2.Traversal();
   ////tree.Map(rdElem);
    ///tree.Traversal();

    return 0;
}