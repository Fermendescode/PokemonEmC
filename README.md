# Pokémon Battle

Sistema desenvolvido em linguagem C para simulação de batalhas entre dois times de Pokémon.

O programa permite criar duas equipes, visualizar os Pokémon disponíveis, escolher os Pokémon para cada batalha e realizar combates utilizando atributos como ataque, defesa, HP e velocidade.

O Pokémon derrotado é removido da equipe e as batalhas continuam até que um dos jogadores fique sem Pokémon.

## Funcionamento

O sistema possui o seguinte fluxo:

| **Etapa** | **Funcionalidade** |
| --------- | ------------------ |
| 1 | Criar as equipes |
| 2 | Exibir os times |
| 3 | Escolher um Pokémon |
| 4 | Iniciar a batalha |
| 5 | Realizar os ataques |
| 6 | Remover o Pokémon derrotado |
| 7 | Verificar o time vencedor |

### 1. Criar equipes

A função `GerarListas()` cria os dois times de Pokémon.

Cada jogador recebe **6 Pokémon**, que são armazenados em listas encadeadas.

Os Pokémon são adicionados utilizando a função `InserirNoFim()`.

### 2. Exibir times

A função `ExibirTimes()` apresenta na tela os Pokémon pertencentes a cada jogador.

São exibidas informações como:

- Nome do Pokémon;
- HP;
- Ataque (`AT`);
- Defesa (`DF`);
- Velocidade (`SP`).

### 3. Escolher Pokémon

A função `EscolherPokemon()` permite que cada jogador escolha um Pokémon da sua equipe.

O jogador informa a posição do Pokémon na lista.

Caso a posição seja inválida, o programa solicita uma nova escolha.

### 4. Iniciar batalha

A função `Batalha()` é responsável por controlar o combate entre os dois Pokémon escolhidos.

O Pokémon com maior velocidade (`SP`) começa atacando.

Os ataques acontecem de forma alternada até que um dos Pokémon fique sem HP.

### 5. Realizar ataque

A função `Atacar()` calcula o dano causado por um Pokémon ao outro.

O cálculo utiliza os atributos de ataque e defesa:

```c
dano = atacante->AT - defensor->DF / 2;
```

O dano mínimo aplicado é de 1.

O HP do Pokémon defensor é reduzido de acordo com o dano recebido.

6. Remover Pokémon derrotado

Quando um Pokémon chega a 0 de HP, ele é considerado derrotado.

A função RemoverPokemon() remove esse Pokémon da lista do jogador e libera sua memória utilizando free().

7. Verificar vencedor

Após cada batalha, a função QuantidadeNaLista() verifica quantos Pokémon ainda existem em cada equipe.

O jogador que ficar sem Pokémon perde a partida.

Estrutura dos dados

As informações dos Pokémon são armazenadas utilizando a estrutura Pokemon.

Cada Pokémon possui atributos como:

Nome → nome do Pokémon;
HP → pontos de vida;
AT → poder de ataque;
DF → poder de defesa;
SP → velocidade.

Os Pokémon são armazenados em uma lista encadeada através da estrutura TLista.

Cada elemento da lista possui:

os dados de um Pokémon;
um ponteiro para o próximo elemento da lista.
Estrutura do projeto

O projeto é dividido nos seguintes arquivos:

Pokemon-Battle/
├── main.c
├── lista.c
├── lista.h
├── pokemon.c
├── pokemon.h
└── README.md

main.c

Contém a lógica principal do programa, incluindo:

criação dos times;
escolha dos Pokémon;
controle das batalhas;
cálculo do vencedor.
lista.c

Contém as funções responsáveis pelo gerenciamento da lista encadeada.

lista.h

Contém as estruturas e os protótipos das funções utilizadas no projeto.

pokemon.c

Contém os dados dos pokemons e a função para gerar os times.

pokemon.h

Contém as estruturas e os protótipos das funções utilizadas no pokemon.c.

Principais funções
CriarLista()

Cria uma nova lista encadeada e reserva memória para sua estrutura inicial.

InserirNoFim()

Adiciona um novo Pokémon no final da lista.

ExibirLista()

Percorre a lista e exibe os dados de todos os Pokémon.

QuantidadeNaLista()

Conta a quantidade de Pokémon existentes na lista.

SelecionarPokemon()

Procura um Pokémon de acordo com sua posição na lista e retorna um ponteiro para ele.

RemoverPokemon()

Remove um Pokémon da lista e libera a memória ocupada pelo elemento.

DestruirLista()

Libera toda a memória utilizada pela lista.

GerarListas()

Cria e adiciona os Pokémon dos dois jogadores às suas respectivas equipes.

ExibirTimes()

Exibe as equipes dos dois jogadores.

EscolherPokemon()

Permite que o jogador escolha qual Pokémon participará da batalha.

Atacar()

Calcula o dano causado pelo Pokémon atacante e reduz o HP do defensor.

Batalha()

Controla toda a batalha entre os dois Pokémon, determinando a ordem dos ataques e o vencedor.

Conceitos de programação utilizados

O projeto utiliza diversos conceitos fundamentais da linguagem C:

struct;
ponteiros;
listas encadeadas;
funções;
passagem de parâmetros;
alocação dinâmica de memória;
malloc();
free();
busca em listas;
inserção de elementos;
remoção de elementos;
estruturas de repetição;
estruturas condicionais;
manipulação de dados através de ponteiros;
gerenciamento de memória.
