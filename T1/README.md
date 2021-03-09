# TRABALHO 1 MP-2020-2
#### Autor: Manoel Vieira
#### Matrícula: 18/0137816


### Execução 

Para rodar basta executar em seu terminal: 

```bash
make
./T1-MP
```

Durante a compilação será executado também o cppcheck e o valgrind, tenha certeza que eles estão instalados.


### Mudando o tipo de pilha

Para alterar o tipo de pilha basta modificar o `#define` no arquivo `testa_pilha.cpp`:

```c++
// define para pilha do tipo encadeada
#define PILHA_TIPO LINKED_TYPE

// define para a pilha usando vector<int>
#define PILHA_TIPO VECTOR_TYPE
```

use apenas um tipo por vez. A cada mudança é necessário a recompilação do código.