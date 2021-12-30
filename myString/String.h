#ifndef STRING_H_
#define STRING_H_
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class String {
//헤더에는 함수들 외부선언만 해준다.
protected:
    void init(const char* s);
public:
    String();
    String(const char* str);
    String(const String& str);
    virtual ~String();
    const char* print(bool show);
    int size();
    int length();
    int capacity();
    //2단계
    String& assign(const String& str);
    String& assign(const char* s);
    String& operator=(const String& str);
    String& operator=(const char* s);

    String& append(const String& str);
    String& append(const char* s);
    String& operator+=(const String& str);
    String& operator+=(const char* s);

    char& operator[](int index);
    void shrink_to_fit();

    //3단계
    String operator+(const String& str);
    String operator+(const char* s);

    friend std::ostream& operator<<(std::ostream& os, const String& str);
    friend std::istream& operator>>(std::istream& is, String& str);
    
protected:
    int len_;
    char* str_;
    int capa_; //for capacity()    
};

#endif /*STRING_H_*/