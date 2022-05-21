#include <cassert>
#include <iostream>
#include <math.h>
#include "complex.h"
#include "Tree.h"
#include "SearchTree.h"
/// testing Complex

void test_creating_complex() {
    Complex a(1, 0);
    Complex b = 1;
    Complex c;
    c.SetRe(1);
    c.SetIm(0);
    assert(a == b);
    assert(c == b);
}

void test_operations() {
    Complex a(1, 1);
    Complex b(-2, 4);
    Complex d(-1, 5);
    assert((a + b) == d);
    Complex e(3, -3);
    assert((a - b) == e);
    Complex f(-6, 2);
    assert((a * b) == f);
}

/// testing Tree
template <class T>
T rdElem(T item) {
    return item * 2;
}

void test_creating_tree() {
    int array[] = {1,2,3,'-','-',4,'-','-',5,6,'-','-','-'}; 
    int array2[] = {2,4,6,'-','-',8,'-','-',10,12,'-','-','-'}; 
    Tree<int> tree(array, '-');
    Tree<int> tree2(array2, '-');
    tree.Traversal();
    Tree<int> tree3(tree);
    assert(tree == tree3);
    assert(tree3.Size() == 6);
    /// testing map
    tree.Map(rdElem);
    assert(tree == tree2);
    /// testing travel
    tree.Traversal("LSR");
    tree.Traversal("SLR");
    /// testing size
    assert(tree.Size() == 6);
    assert(tree2.Size() == 6);
 
}

void test_creating_search_tree() {
    int array[] = {8,3,1,'-','-',6,4,'-','-', 7,'-','-',10,'-',14,'-','-'}; 
    int array2[] = {8,3,1,'-','-',6,4,'-','-', 7,'-','-',10,'-',14,'-','-'}; 
    int array3[] = {3,1,'-','-',6,4,'-','-', 7,'-','-'}; 
    int array4[] = {3,2,'-','-',6,4,'-','-', 7,'-','-'}; 
    int array5[] = {9,1,'-','-','-'}; 
    int array6[] = {8,4,1,'-','-',6,'-',7,'-','-',10,'-',14,'-','-'}; 
    SearchTree<int> searchtree(array, '-');
    SearchTree<int> searchtree2(searchtree);
    SearchTree<int> searchtree3(array3, '-');
    SearchTree<int> searchtree4(array4, '-');
    SearchTree<int> searchtree5(array5, '-');
    SearchTree<int> searchtree6(array6, '-');
    assert(searchtree == searchtree2);
    /// testing size and add
    assert(searchtree.Size() == 8);
    searchtree.AddNode(15);
    searchtree.Traversal();
    assert(searchtree.Size() == 9);
    /// testing extracting subtree
    SearchTree<int>* searchtreePtr = searchtree.ExtractSubtree(3);
    assert(*(searchtreePtr) == searchtree3);
    /// testing find item (bool)
    assert(searchtree.FindItemBool(6) == true);
    assert(searchtree.FindItemBool(15) == true);
    assert(searchtree.FindItemBool(9) == false);
    /// testing find subtree (bool)
    assert(searchtree.FindTreeBool(*searchtreePtr) == true);
    assert(searchtree.FindTreeBool(searchtree4) == false);
    assert(searchtree.FindTreeBool(searchtree5) == false);
    delete searchtreePtr;
     /// testing delete subtree (bool)
    searchtree2.DeleteNode(3);
    assert(searchtree2 == searchtree6);
    /// testing 
    searchtree2.SetHeight();
}