#pragma once
#include<iostream>

class ExceptionError {
private:
    int number;
public:
    ExceptionError(int key) {
        number = key;
        switch (number)
        {
        case 1:
            std::cout << "IndexOutOfRange\n";
            break;
        case 2:
            std::cout << "DifferentLengthsOfVectors\n";
            break;
        default:
            break;
        }
    }
};