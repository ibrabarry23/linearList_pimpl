//
// Created by Ibrahima tely Barry on 13/04/24.
//
#include "list.hpp"
#inculde <iostream>
#include <vector>
struct List_int:: Impl{
    std::vector <int> v;
    int a;
    void stampa_ric(const std::vector <int> &s, int pos){
        if(pos< s.size()){
            std::cout<<s.at(pos)<<std::endl;
            stampa_ric(s, pos+1);
        }
    }
};

List::int List_int (){
    pimpl = new Impl;
    pimpl->a = 0;
}
List::int List_int (const List_int & l){
    pimpl = new Impl;
    pimpl -> v = l.pimpl-> v; // deep copy
}
List::int~List_int(){
    delete pimpl;
}

void List_int::prepend(int el ){
    pimpl->v.resize(pimpl->v.size()+1);
    for(int i = pimpl->v.size()-1; i> 0; i--)
        pimpl->v.at(0)=el;
}

void List_int::append(int el){
    pimpl->v.push_back(el);
}

const List_int& List_int::operator=(const List_int&){
    pimpl->v = l.pimpl-> ; // sfrutto l'overlanding = sui vector
    return *this;
}