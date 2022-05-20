#include <cassert>
#include <iostream>
#include <math.h>
#include "complex.h"
#include "Tree.h"

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
    tree.Map(rdElem);
    assert(tree == tree2);
   
}

