#include <iostream>
#include <fstream>
#include <cstdio>
#include "myarray.h"




int main() {

    ARRAY arr(10);
    arr.add(new INT(-5));
    arr.add(new CHAR('g'));
    arr.add(new STRING("hallo"));
    arr.add(new DOUBLE(3.14));
    ARRAY arr1(arr);
    arr1.add(&arr);
    std::cout << arr1 ;






    return 0;
}
