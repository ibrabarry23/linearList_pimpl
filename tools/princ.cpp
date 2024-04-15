//
// Created by Ibrahima tely Barry on 13/04/24.
//
#include "list.hpp"
#include <iostream>

int main (){
    List_int a;
    std::cout<<"Inizio l'inserimento"<<std::endl;
    for(int i = 0; i< 50000; i++)
        a.prepend(i);
    std::cout<<"Fine dell'inserimento"<<std::endl;
}