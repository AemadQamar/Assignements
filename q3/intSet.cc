#include "intSet.h"

intSet::intSet() : data{new int[4]}, size{0}, capacity{4} {}

void intSet::add(int e) {
    if (!(contains(e))){
        if (size == capacity) {
            int newCapacity = 2*capacity;
            int *newData = new int[newCapacity];
            for (int i = 0; i < capacity; ++i){
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
            capacity = newCapacity;
        }
        data[size] = e;
        size += 1;
    }
}

void intSet::remove(int e){
    for (int i = 0; i < size; ++i){
        if (data[i] == e){
            for (int j = i, j < size -1; ++j) {
                data[j] == data[j+1];
            }
            size -= 1;
            break;
        }
    }
}

bool intSet::contains(int e){
    for (int i = 0; i < size; ++i){
        if (data[i] == e){
            return 1;
        }
    }
    return 0;
}