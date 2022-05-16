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
    int array2[] = {1,2,3,'-','-',4,'-','-',5,7,'-','-','-'}; 
    Tree<int> tree(array, '-');
    Tree<int> tree2(array2, '-', "RSL");
    tree.Traversal();
    tree2.Traversal();
    tree.Map(rdElem);
    tree.Traversal();
    return 0;
}