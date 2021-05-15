//
// Created by Knight on 2021/3/30.
//

#ifndef POINTER_H
#define POINTER_H

#include <iostream>

using namespace std;

template<class T>
class Pointer{
public:
    static T* pArray(int size){
        if(size == 0)   return nullptr;

        return (T*)malloc(sizeof(T)*size);
    }

    static T* pArray(int size, T defValue){
        if(size == 0)   return nullptr;

        T* array = (T*)malloc(sizeof(T)*size);

        for(int i = 0; i<size; i++){
            array[i] = defValue;
        }

        return array;
    }

    static T** pMatrix(int row, int column){
        T** matrix = (T**)malloc(sizeof(T*)*row);

        for(int i = 0; i<row; i++){
            matrix[i] = pArray(column);
        }
        return matrix;
    }

    static T** pMatrix(int row, int column, T defValue){
        T** matrix = (T**)malloc(sizeof(T*)*row);

        for(int i = 0; i<row; i++){
            matrix[i] = pArray(column, defValue);
        }
        return matrix;
    }
};

#endif //POINTER_H
