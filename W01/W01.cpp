//
// Created by Sobiech on 01.03.2023.
//

#include "W01.h"
#include <iostream>

using namespace std;

int fun1(double, double);
bool isEq(int, int);

int main() {
    //main moze zawierac parametry podobnie jak args[], ake tu sa jakies pontery i chuja rozumiem jak.

    //masz zdjecie typów zmiennych

    cout << 3./10 << endl; //endl konczy linie - nie obowiązkowy.
    string imie = "abc";
    string zm1;
    string zm2;
    string zm3;

    cin >> imie;

    cin >> zm1 >> zm2;
    //nie ma błędów sprawdzanych.

    cout << imie << zm1 << zm2 << zm3<<endl;
    cout << fun1(10,3);


    cout<<"==============";

    int abc = 7;

#define abc 123 // dobre do nazw plików.
    if (isEq(abc, 123))
        cout<<"Działa abc"<<endl;
    else {
        cout << "unset abc" << endl;
    }
#undef abc// dobre do nazw plików.
    if (isEq(abc, 123))
        cout<<"Działa abc!"<<endl;
    else {
        cout << "unset abc" << endl;
    }


    cout << __DATE__ << endl;
    cout << 0.2f << endl;

    if (true==1)
        cout << "rowne" << endl;
    //false jest rowne 0 a wszystko inne true;


    cout << sizeof(long double);

//    delcaretype() stwierdza jakiego typu może być wyrażenie.

    cout<<endl<<"============================"<<endl;
    unsigned int ui = 0b1010; //4 32 bity ale same dodatnie. signed jest tez 32 bity ale pol dodatnich pol ujemnych.
    cout << ui;





    //return nie jest obowiązkowy.
    return 0;
}
bool isEq(int a, int b){
    return a==b;
}


int fun1(double a, double b){
    return (a/b);
}

