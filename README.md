Pokémon Battle

Projeto em linguagem C que simula batalhas entre dois jogadores utilizando listas encadeadas para armazenar as equipes de Pokémon.


Funcionamento

Cada jogador possui 6 Pokémon.
Os jogadores escolhem um Pokémon para cada batalha.
O Pokémon com maior velocidade (SP) começa atacando.
O dano é calculado com base no ataque (AT) e na defesa (DF).
Os ataques acontecem alternadamente até um Pokémon ser derrotado.
O Pokémon derrotado é removido da equipe.
A batalha continua até um jogador ficar sem Pokémon.



🧩 Principais conceitos

| Função                | Responsabilidade         |
| --------------------- | ------------------------ |
| `CriarLista()`        | Cria a lista             |
| `InserirNoFim()`      | Adiciona Pokémon         |
| `ExibirLista()`       | Exibe os Pokémon         |
| `QuantidadeNaLista()` | Conta Pokémon            |
| `SelecionarPokemon()` | Busca um Pokémon         |
| `RemoverPokemon()`    | Remove Pokémon derrotado |
| `DestruirLista()`     | Libera a memória         |
| `GerarListas()`       | Monta os times           |
| `ExibirTimes()`       | Mostra os dois times     |
| `EscolherPokemon()`   | Permite escolher         |
| `Atacar()`            | Calcula e aplica dano    |
| `Batalha()`           | Controla a luta          |

O projeto utiliza:
Linguagem C;
struct;
Ponteiros;
Listas encadeadas;
malloc() e free();
Funções;
Inserção e remoção de elementos;
Busca em listas;
Gerenciamento de memória.
