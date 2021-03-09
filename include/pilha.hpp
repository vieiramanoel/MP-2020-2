#include <vector>
#include <memory>

#define VECTOR_TYPE 0
#define LINKED_TYPE 1
#include <stdexcept>

class Pilha
{
public:
    virtual void push(int) = 0;
    virtual int pop() = 0;
    virtual int top() = 0;
};

class VecPilha : public Pilha
{
private:
    std::vector<int> data;
    int last();

public:
    VecPilha();
    virtual void push(int) override;
    virtual int pop() override;
    virtual int top() override;
};

struct Encadeada
{
    int value = 0;
    std::shared_ptr<Encadeada> previous;
};

class EncPilha : public Pilha
{
private:
    std::shared_ptr<Encadeada> data;

public:
    EncPilha();
    virtual void push(int) override;
    virtual int pop() override;
    virtual int top() override;
};

void push(Pilha *p, int value);

int top(Pilha *p);
int pop(Pilha *p);