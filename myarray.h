//
// Created by Mohamed Amine  Bellil on 07.04.22.
//

#ifndef DATASTR_ARRAY_H
#define DATASTR_ARRAY_H

#include <iostream>

enum arrtype {ST,IN,DO,CH,AR,BL};

class ARRAY
{
private:
    ARRAY** arr;
    int size;
public:
    ARRAY():arr(nullptr),size(0){}
    ARRAY(int size): size(size){ arr = new ARRAY*[size];}
    ARRAY(const ARRAY& arrcpy);
    ~ARRAY();

public:
    int getsize() const {return size;}
    void add(const ARRAY* obj);
    virtual arrtype getType()const {return AR;}
    virtual void print(std::ostream& stream ) const ;
    ARRAY* operator [](int index)const{ return arr[index];}
    friend std::ostream& operator << (std::ostream& stream , const ARRAY& obj) { obj.print(stream); return stream; }
    int check();



};

class INT : public ARRAY {
private:
    int val;
public:
    INT():val(0){}
    INT(int val):val(val) {}
    INT(const INT& obj){val = obj.val;}
    arrtype getType() const override {return IN;}
    void print(std::ostream& stream)const override { stream << val ;}
};

class DOUBLE : public ARRAY {
private:
    double val;
public:
    DOUBLE():val(0){}
    DOUBLE(double val):val(val) {}
    DOUBLE(const DOUBLE& obj){val = obj.val;}

    arrtype getType() const {return DO;}
    void print(std::ostream& stream)const override { stream << val ;}

};

class STRING : public ARRAY {
private:
    char val[30];
public:
    STRING():val(" "){}
    STRING( const char * val){ strncpy(this->val, val, 30);}
    STRING(const STRING& obj){ strcpy(val,obj.val);}
    arrtype getType() const override {return ST;}
    void print(std::ostream& stream) const override { stream << val ;}

};

class CHAR : public ARRAY {
private:
    char val;
public:
    CHAR():val(0){}
    CHAR(char val):val(val) {}
    CHAR(const CHAR& obj){val = obj.val;}

    arrtype getType() const override {return CH;}
    void print(std::ostream& stream)const override { stream << val ;}

};

class BOOL : public ARRAY {
private:
    bool val;
public:
    BOOL():val(false){}
    BOOL(bool val):val(val) {}
    BOOL(const BOOL& obj){val = obj.val;}

    arrtype getType() const override {return BL;}
    void print(std::ostream& stream) const override { if(val) stream << "true" ; else stream << "false"; }

};





#endif //DATASTR_ARRAY_H
