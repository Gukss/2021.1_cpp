#ifndef TEXT_H_
#define TEXT_H_
#include "String.h"
#pragma once

class Text : public String {
private:
    void init();
public:
    Text();
    Text(const char* str);
    Text(const String& str);
    Text(const Text& str);
    ~Text();

    int lines();

    Text& append(const char* str);
    Text& append(const String& str);
    Text& append(const Text& text);

    //friend ostream& operator<<(ostream& out, Text& txt);
    //위 함수는 String.cpp에 전역으로 정의되어 있고 Text 타입은 String 타입으로 사용할 수 있으므로 따로 정의해주지 않아도 위 형식으로 Text형을 << 연산 가능하다.
private:
    int line_;
};

#endif /*TEXT_H_*/