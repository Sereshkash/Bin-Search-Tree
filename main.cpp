#include <iostream>
#include <math.h>
#include "complex.h"
#include "Tree.h"
#include "SearchTree.h"
#include <ctime> 

int main() {
    std::cout << "Время от 10^4 до 10^5 элементов (в сек):\n";
    for (int j = 10000; j < 100000; j+= 20000) {
        unsigned int start_time =  clock(); // начальное время
        SearchTree<int> searchtree;
        for (int i = 0; i < j; i++) {
            searchtree.AddNode(i);
        }
        searchtree.FindItemBool(501);
        searchtree.FindItemBool(221);
        unsigned int end_time = clock(); // конечное время
        unsigned int search_time = (end_time - start_time) / CLOCKS_PER_SEC;
        std::cout << search_time << "\n";
    }
    std::cout << "Время от 10^6 до 10^8 элементов (в сек):\n";
    for (int j = 1000000; j < 100000000; j+= 25000000) {
        unsigned int start_time =  clock(); // начальное время
        SearchTree<int> searchtree;
        for (int i = 0; i < j; i++) {
            searchtree.AddNode(i);
        }
        searchtree.FindItemBool(501);
        searchtree.FindItemBool(221);
        unsigned int end_time = clock(); // конечное время
        unsigned int search_time = (end_time - start_time) / CLOCKS_PER_SEC;
        std::cout << search_time << "\n";
    }
    return 0;
}