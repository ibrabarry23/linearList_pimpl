//
// Created by Ibrahima tely Barry on 16/04/24.
//


#include "list.hpp"
#include <iostream>
struct List_int::Impl {

    struct Cell{
        int info ;
        Cell* next;
        Cell* prev;
    };

    typedef Cell* Pcell;

    Pcell head ;
    Pcell tail ;

};

// costruttore
List_int:: List_int(){
    pimpl = new Impl; // devo cosruitre la scatola che terrà traccia dello stato della classe
    pimpl-> head = nullptr;
    pimpl-> tail = nullptr;
}

List_int::List_int(const List_int& l){
    pimpl = new Impl;
    pimpl->head = nullptr;
    pimpl->tail = nullptr;

    Impl::Pcell pc = l.pimpl->head;

        while(pc!= nullptr){
            append(pc->info);
            pc = pc->next;
        }
}

void List_int::prepend (int x){
    // il campo della prima lista nel punto prev punta sempre a nullptr
   Impl::Pcell pn = new Impl::Cell {x, pimpl->head, nullptr};

    if(pimpl->head != nullptr)
        pimpl->head->prev = pn;
    else pimpl->tail = nullptr;
        pimpl->tail = pn;

   pimpl->head = pn;
}

void List_int::append (int x){
    Impl::Pcell pn = new Impl::Cell{x,nullptr, pimpl->tail};

    if(pimpl->tail != nullptr){
        pimpl->tail->next = pn;
        pimpl->tail = pn;
    } else pimpl->head = pimpl->tail = pn;

}

void List_int::stampa() const{
    Impl::Pcell pc = pimpl->head;
    while(pc != nullptr){
        std::cout<<pc->info<<std::endl;
        pc = pc->next;
    }
}
// distruttore
List_int::~List_int(){
     while (pimpl->head){
         Impl::Pcell pc = pimpl->head;
         pimpl->head = pimpl->head->next;
         delete pc;
     }
     delete pimpl;
 }

/*
const List_int& List_int::operator = (const List_int& l){
    // se non faccio un auto assegnamento cancello la lista dell'operando a sx
    if(this != &l) { // protezione auto-assegnamento
        while(pimpl->head){
            Impl_Pcel pc = pimpl->head;
            impl->head = pimpl->head->next;
            delete pc;
        }
        // considero la lista vuota
        pimpl->head = pimpl->tail = nullptrM
    }
    //aggiungo l'elemento per la lista in l
    Impl::Pcell pc = pimpl->head;
    while(pc != nullptr){
        append(pc->info);
        pc= pc->next;
    }
    return *this;
}
*/

const List_int& List_int::operator= (const List_int& l){
    List_int tmp{l};
    Impl* p = pimpl;
    pimpl = tmp.pimpl;
    tmp.pimpl = p;
    return *this;
}
void List_int::pop_back() const {
    if(pimpl->head != nullptr){
    Impl::Pcell pc = pimpl->head;
        if(pimpl->head != pimpl->tail) // la lista non ha una sola cella
        pimpl->tail = pimpl->tail->prev;
        delete pimpl->tail->next;
        pimpl->tail = pc ;
    } else{
        delete pimpl->head;
        pimpl->head = pimpl->tail = nullptr;
    }
}
