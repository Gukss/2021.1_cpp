#include "String.h"
//1단계

//""=empty string
//빈 문자열 기본생성자
String::String()
{
    /*len_ = 0;
    capa_ = len_ + 1;
    str_ = new char[capa_];
    strcpy_s(str_, capa_, "");*/
    init("");
}
//기본 문자열 생성자
String::String(const char* str)
{
    /*len_ = strlen(str);
    capa_ = len_ + 1;
    str_ = new char[capa_];
    strcpy_s(str_, capa_, str);*/
    init(str);
}
//str문자열 복사생성자
String::String(const String& str)
{
    /*len_ = strlen(str.str_);
    capa_ = len_ + 1;
    str_ = new char[capa_];
    strcpy_s(str_, capa_, str.str_);*/
    init(str.str_);
}
//소멸자
String::~String()
{
    delete[] this->str_;
}
//출력
const char* String::print(bool show = true)
{
    if (show)
    {
        std::cout << this->str_;
    }
    return this->str_;
}
//길이반환
int String::size()
{
    return strlen(str_); //or return len_;
}
//길이반환
int String::length()
{
    return size();
}
//동적할당된 문자열 저장공간크기 반환, 문자열 길이와 다를수 있다.
int String::capacity()
{
    return capa_;
}

//2단계
//초기화 함수
void String::init(const char* s)
{
    len_ = strlen(s);
    capa_ = len_ + 1;
    str_ = new char[capa_];
    strcpy_s(str_, capa_, s);
}
//대입, 할당
String& String::assign(const String& str)
{
    this->assign(str.str_);
    return (*this);
}
String& String::assign(const char* s)
{
    /*if (str_ != NULL)
    {
        delete[] str_;
    }*/
    init(s);
    return (*this);
}
String& String::operator=(const String& str)
{
    this->assign(str);
    return (*this);
}
String& String::operator=(const char* s)
{
    this->assign(s);
    return (*this);
}
//누적, 연결
String& String::append(const String& str)
{
    this->append(str.str_);
    return (*this);
}
String& String::append(const char* s)
{
    int len2_ = strlen(s);
    len_ += len2_;
    capa_ = len_ + 1;
    char* temp = new char[capa_];
    strcpy_s(temp, capa_, str_);
    strcat(temp, s);
    delete[] str_;
    str_ = new char[capa_];
    strcpy_s(str_, capa_, temp);
    delete[] temp;
    return (*this);
}
String& String::operator+=(const String& str)
{
    this->append(str);
    return (*this);
}
String& String::operator+=(const char* s)
{
    this->append(s);
    return (*this);
}
//원소로 접근
char& String::operator[](int index)
{
    if (index < 0)
    {
        index = 0;
    }
    else if (index >= this->len_)
    {
        index = len_-1;
    }
    return this->str_[index];
}
//문자열 저장 공간 정리
void String::shrink_to_fit()
{
    this->assign(this->str_);
}

//3단계
String String::operator+(const String& str)
{
    this->operator+(str.str_);
    return (*this);
}
String String::operator+(const char* s)
{
    init(strcat(this->str_, s));
    return (*this);
}
std::ostream& operator<<(std::ostream& os, const String& str)
{
    os << str.str_;
    return os;
}
std::istream& operator>>(std::istream& is, String& str)
{
    is >> str.str_;
    return is;
}