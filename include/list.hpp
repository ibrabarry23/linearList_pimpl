class List_int{
    public:

        List_int();
        List_int(const List_int& l);
        ~List_int();
        void prepend(int el);
        void append(int el);
        void stampa() const;

    private :
        struct Impl;
        Impl * pimpl;

};