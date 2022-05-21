#include <iostream>
#include <math.h>
#include "complex.h"
#include "Tree.h"
#include "SearchTree.h"

template <class T>
T rdElem(T item) {
    return item * 2;
}
int main() {
    int array[] = {1,2,3,'-','-',4,'-','-',5,6,'-','-','-'}; 
   //// int array2[] = {'-', '-', 3, '-', '-', 4, 2, '-', '-', 6, '-', 5, 1}; 
    
    int array3[] = {8,3,1,'-','-',6,4,'-','-', 7,'-','-',10,'-',14,'-','-'}; 
    Tree<int> tree(array3, '-');
    tree.Traversal("LSR");
    SearchTree<int> searchtree(array3, '-');
    SearchTree<int> searchtree2(array3, '-');
    ///searchtree.AddNode(15);
    std::cout << searchtree.Size() << "\n";
    searchtree.Traversal("LSR");
   /// (*(searchtree.ExtractSubtree(3)));
    searchtree2.Traversal("LSR");
    searchtree2.DeleteNode(3);
    searchtree2.Traversal("LSR");
   /// searchtree2.Traversal("LSR");
   std::cout << "dd\n";
   searchtree.Traversal("LSR");
    searchtree.SetHeight();
    return 0;
}