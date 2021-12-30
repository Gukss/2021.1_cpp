
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "String.h"
#include "Text.h"
using namespace std;
int main()
{
    /*
    //1단계
    String str("apple");
    str.print();
    cout << endl;
    cout << str.size() << endl;
    cout << str.length() << endl;
    cout << str.capacity() << endl;
    cout << "---------------------" << endl;
    String a(str);
    a.print();
    cout << endl;
    cout<<a.capacity() << endl;
    cout<<a.length() << endl;
    cout<<a.size() << endl;
    cout << "---------------------" << endl;
    String b;
    b.print();
    cout << endl;
    cout << b.capacity() << endl;
    cout << b.length() << endl;
    cout << b.size() << endl;

    return 0;
    
    //2단계
    String str("apple");
    cout << str.print(false) << endl;
    str.assign("bear");
    cout << str.print(false) << endl;

    cout << str[-1] << endl;
    cout << str[2] << endl;
    cout << str[5] << endl;

    str.shrink_to_fit();
    str.append("apple");
    cout << str.print(false) << endl;
    
    //3단계
    str+"bear";
    cout << str.print(false) << endl;
    
    cin >> str;
    cout << str << endl;
    str=str;
    str+=str;
    cout<<str;
    return 0;
    */
    
    //4단계
    Text text1;
    Text text2("apple");
    String str("bear");
    Text text3(str);
    Text text4(text2);

    cout<<text2.lines();

    text2.append("bear");
    text2.append(str);
    text2.append(text4);

    cout << text3;
}


/*
//string::operator+=
#include <iostream>
#include "String.h"
using namespace std;
int main(void)
{
    String str_1("kim");
    String str_2("dong");
    String str_3("guk");
    str_1 += " ";
    str_1 += str_2;
    str_1.append(str_3);
    str_1.append("\n");

    cout << str_1;
    return 0;
}
*/