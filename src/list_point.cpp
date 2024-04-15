//
// Created by Ibrahima tely Barry on 14/04/24.
//

#include "list.hpp"
#include <iostream>
struct List_int::Impl {

    struct Cell{
        int info ;
        Cell* next;
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

void List_int::prepend (int x){
   Impl::Pcell pn = new Impl::Cell {x, pimpl->head};
   pimpl->head = pn;
   if(pimpl->tail == nullptr) pimpl->tail = pn;
}

void List_int::append (int x){
    Impl::Pcell pn = new Impl::Cell{x,nullptr};
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
}