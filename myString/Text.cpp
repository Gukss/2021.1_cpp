#include "Text.h"

void Text::init()
{
    line_ = 0;
    if (str_[len_-1] != '\n')
    {
        len_++;
        capa_++;
        char* temp = new char[capa_];
        strcpy(temp, str_);
        strcat(temp, "\n\0");
        delete[] str_;
        str_ = new char[capa_];
        strcpy(str_, temp);
        delete[] temp;
    }
    for (int i = 0; i < capa_; i++)
    {
        if (str_[i] == '\n')
            line_++;
    }
}

Text::Text() : String::String("\n")
{
    init();
}
Text::Text(const char* str) : String(str)
{
    init();
}
Text::Text(const String& str) : String(str)
{
    init();
}
Text::Text(const Text& str) : String(str.str_)
{
    init();
}
Text::~Text(){ }


int Text::lines()
{
    return this->line_;
}

Text& Text::append(const char* str)
{
    String::append(str);
    init();
    return (*this);
}
Text& Text::append(const String& str)
{
    String::append(str);
    init();
    return (*this);
}
Text& Text::append(const Text& text)
{
    this->append(text.str_);
    return (*this);
}
/*
std::ostream& operator<<(std::ostream& os, Text& txt)
{
    os << (String)txt;
    return os;
}
*/