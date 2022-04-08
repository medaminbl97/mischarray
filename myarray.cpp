//
// Created by Mohamed Amine  Bellil on 07.04.22.
//

#include "myarray.h"


void ARRAY::print(std::ostream& stream ) const {
    if(!size) {std::cout << "! Array is empty !" << std::endl;}
    if(size){
        for(int i = 0; i < size ; i++)
        {
            if(arr[i]) stream << '['<< i << "] " << *(arr[i]) << std::endl;
            else std::cout << '['<< i << "] " << "nullptr" << std::endl;
        }
    }
}

ARRAY::ARRAY(const ARRAY& arrcpy) {
    if(arrcpy.size) {
        size = arrcpy.size;
        arr = new ARRAY *[size];
        for (int i=0; i < size; i++) {
            if (!arrcpy[i]) arr[i] = nullptr;
            else
            {
                switch (arrcpy[i]->getType()) {

                    case ST: arr[i]= new STRING(*((STRING*)arrcpy[i])); break;
                    case CH: arr[i]= new CHAR(*((CHAR*)arrcpy[i])); break;
                    case DO: arr[i]= new DOUBLE(*((DOUBLE*)arrcpy[i])); break;
                    case BL: arr[i]= new BOOL(*((BOOL*)arrcpy[i])); break;
                    case IN: arr[i]= new INT(*((INT*)arrcpy[i])); break;
                    case AR: arr[i]= new ARRAY(*arrcpy[i]); break;

                }
            }


        }
    }
}

ARRAY::~ARRAY(){

    for(int i = 0; i< size ; i++)
    {
        if(arr[i]) delete arr[i];
        std::cout << '['<< i << "] " << " deleted" << std::endl;
    }

    delete arr;
}


void ARRAY::add(const ARRAY *obj) {
    switch (obj->getType()) {

        case ST: if(check()+1) {arr[check()]= new STRING(*((STRING*)obj)); break;}
        case CH: if(check()+1) arr[check()]= new CHAR(*((CHAR*)obj)); break;
        case DO: if(check()+1) arr[check()]= new DOUBLE(*((DOUBLE*)obj)); break;
        case BL: if(check()+1) arr[check()]= new BOOL(*((BOOL*)obj)); break;
        case IN: if(check()+1) arr[check()]= new INT(*((INT*)obj)); break;
        case AR: if(check()+1) arr[check()]= new ARRAY(*obj); break;

    }
}

int ARRAY::check() {
    for(int i=0; i< size ; i++)
    {
        if(!arr[i]) return i;
    }
    return -1;
}