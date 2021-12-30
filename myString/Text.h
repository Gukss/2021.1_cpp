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
    //�� �Լ��� String.cpp�� �������� ���ǵǾ� �ְ� Text Ÿ���� String Ÿ������ ����� �� �����Ƿ� ���� ���������� �ʾƵ� �� �������� Text���� << ���� �����ϴ�.
private:
    int line_;
};

#endif /*TEXT_H_*/