//
// Created by Ibrahima tely Barry on 13/04/24.
//
#include "list.hpp"
#include <iostream>

int main (){
    List_int a;
    List_int b;

    std::cout<<"Inizio l'inserimento"<<std::endl;
    for(int i = 0; i< 1000000000; i++)
        a.pop_back();
    b = a; // deep copy
    std::cout<<"Fine dell'inserimento"<<std::endl;
}