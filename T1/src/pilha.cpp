#include "pilha.hpp"

const auto except = std::length_error("Pilha vazia");

VecPilha::VecPilha()
{
    data = std::vector<int>();
}

void VecPilha::push(int value)
{
    data.push_back(value);
}

int VecPilha::top()
{
    return last();
}

int VecPilha::pop()
{
    auto value = last();
    data.pop_back();

    return value;
}

int VecPilha::last()
{
    if (data.size()) { 
        return data[data.size() - 1];
    }
    throw except;
}

EncPilha::EncPilha()
{
    data = std::shared_ptr<Encadeada>(nullptr);
}

void EncPilha::push(int value)
{
    auto newEntry = std::shared_ptr<Encadeada>(new Encadeada{
        value : value,
        previous : data,
    });
    data = newEntry;
}

int EncPilha::top()
{   
    if (data) { 
        return data->value;
    }
    throw except;
}

int EncPilha::pop()
{
    if (data)
    {
        auto last = data->previous;
        auto value = data->value;
        data = last;
        return value;
    }
    throw except;
}

void push(Pilha *p, int value)
{
    p->push(value);
}

int top(Pilha *p)
{
    return p->top();
}

int pop(Pilha *p)
{
    return p->pop();
}