#include "pilha.hpp"
#include <iostream>

// Usar VECTOR_TYPE ou LINKED_TYPE para alternar
// entre pilha de vetor ou de lista encadeada

#define PILHA_TIPO LINKED_TYPE

// #define PILHA_TIPO VECTOR_TYPE

int main(int argc, char const *argv[])
{
    Pilha *p;
    switch (PILHA_TIPO)
    {
    case VECTOR_TYPE:
        p = new VecPilha();
        break;
    case LINKED_TYPE:
        p = new EncPilha();
        break;
    default:
        std::cerr << "Tipo não registrado, favor mudar o define para ou VECTOR_TYPE ou LINKED_TYPE" << std::endl;
        return 2;
        break;
    }

    push(p, 10);
    push(p, 20);
    push(p, 40);

    std::cout << "TOP: " << top(p) << std::endl;
    std::cout << "POP: " << pop(p) << std::endl;

    std::cout << "TOP: " << top(p) << std::endl;
    std::cout << "POP: " << pop(p) << std::endl;

    std::cout << "TOP: " << top(p) << std::endl;
    std::cout << "POP: " << pop(p) << std::endl;

    // tentativa de dar pop em pilha vazia
    try
    {
        std::cout << "TOP: " << top(p) << std::endl;
        std::cout << "POP: " << pop(p) << std::endl;
    }
    catch (std::length_error &e)
    {
        std::cerr << "ERRO NA PILHA" << std::endl;
        std::cerr << e.what() << std::endl;
    }

    delete p;
    return 0;
}
