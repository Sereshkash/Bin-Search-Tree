#include <iostream>
#include <math.h>
#include "complex.h"
#include "Tree.h"
#include "SearchTree.h"

#define INVALID -9999999

template <class T>
T rdElem(T item) {
    return item * 2;
}

template <class T>
bool divisionElem(T item) {
    return (item % 2) == 0;
}

int main() {
    int array[] = {1,2,3,INVALID,INVALID,4,INVALID,INVALID,5,6,INVALID,INVALID,INVALID}; 
   //// int array2[] = {INVALID, INVALID, 3, INVALID, INVALID, 4, 2, INVALID, INVALID, 6, INVALID, 5, 1}; 
    
    int array3[] = {8,3,1,INVALID,INVALID,6,4,INVALID,INVALID, 7,INVALID,INVALID,10,INVALID,14,INVALID,INVALID}; 
    Tree<int> tree(array3, INVALID);
    tree.Traversal("LSR");
    int* array5 = tree.GetStr("LSR", INVALID);
    int i = 0;
   /// Tree<int> tree3(array5, INVALID);
   /// tree3.Traversal("LSR");
    while (array5[i]) {
        std::cout << array5[i] << " ";
        i++;
    }
    delete [] array5;
    std::cout << "\n";
    SearchTree<int> searchtree(array3, INVALID);
    SearchTree<int> searchtree2(array3, INVALID);
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
    SearchTree<int> searchtree3;
    for (int i = 1; i < 10; i++) {
        searchtree3.AddNode(i);
    }
    int* array6 = searchtree3.GetStr("LSR", INVALID);
    int j = 0;
   /// Tree<int> tree3(array5, INVALID);
   /// tree3.Traversal("LSR");
    while (array6[j]) {
        std::cout << array6[j] << " ";
        j++;
    }
    std::cout << "\n";
    searchtree2.BalanceTree();
    delete [] array6;
    int array7[] = {1,INVALID,2,INVALID,3,INVALID,4,INVALID,5,INVALID,6,INVALID,INVALID}; 
    SearchTree<int> searchtree7(array7, INVALID);
    searchtree7.BalanceTree();
    searchtree7.Traversal("SLR");
    /// testing where
    searchtree7.Where(divisionElem);
    searchtree7.Traversal("SLR");
    SearchTree<int> searchtree10(array7, INVALID);
    SearchTree<int> searchtree9(array3, INVALID);
    searchtree9.Merger(searchtree10);
    std::cout << "SSSS\n";
    searchtree9.Traversal("LSR");
    searchtree9.Traversal("SLR");
    int* array9 = searchtree9.GetStr("SLR", INVALID);
    j = 0;
    while (array6[j]) {
        std::cout << array6[j] << " ";
        j++;
    }
    std::cout << "\n";
    delete [] array9;
    return 0;
}