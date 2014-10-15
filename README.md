
Generic linked list ADT
by Julian Camara 2014
    
    This is an implementation of a linked list that will accept as data anything
    from primitives to structs. All it strictly requires for adding, retrieving,
    deleting and finding elements are two functions for your datatypes: a
    comparison between two datatypes that takes two void pointers and returns a
    bool true if the first is greater than the second and bool false otherwise,
    and a function for identifying a data member passed in as a void pointer. In
    this implementation the latter function returns an int, but it may
    theoretically be modified to return anything capable of being compared.

    As might be assumed by the necessity of a comparison function, this linked
    list inserts in sort order. Full advantage of this fact has not yet been
    taken with regard to the traverse functions, so this list is currently
    suboptimal.

    You may find it useful to implement some sort of to_string method or a print
    data method. I would strongly advise implementing a data encapsulator that
    takes any data required and returns a void pointer to it. In other languages
    this would be called a constructor.
        
    Example implementation of these four types of function as relates to an int
    list are provided, as well as a main method that demonstrates their usage and
    usage of the list itself.