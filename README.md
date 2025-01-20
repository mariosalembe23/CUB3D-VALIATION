# Análise e validação de mapas

## Um arquivo de mapa/configuração válido obedece às seguintes regras:

- O mapa deve ser composto de apenas 6 caracteres possíveis: 0 para um espaço vazio,
- 1 para uma parede e N, S, E ou O para a posição inicial do jogador e
- orientação de surgimento.
- O mapa deve ser fechado/cercado por paredes
- Com exceção do conteúdo do mapa, cada tipo de elemento pode ser separado por uma ou mais linhas vazias.
- Com exceção do conteúdo do mapa, que sempre deve ser o último, cada tipo de elemento pode ser definido em qualquer ordem no arquivo.
- Com exceção do mapa, cada tipo de informação de um elemento pode ser separado
- por um ou mais espaços.
- O mapa deve ser analisado como ele aparece no arquivo. Espaços são uma parte válida do
- mapa e cabe a você lidar com eles. Você deve ser capaz de analisar qualquer tipo de mapa,
- desde que ele respeite as regras do mapa.

### Um mapa válido:

```c

WE ./walls3.xpm
NO ./walls.xpm

SO ./walls2.xpm


F 220,100,0
EA ./walls3.xpm


C 225,30,0


    1111111111111111111111111
    1000000000110000000000001
    1011000001110000000011111
1111000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10000000000000001100000010001
10000000000000001101010010001
11000001110101011111011110N0111
11110111 1110101 101111010001
11111111 1111111 111111111111

```

### Um mapa inválido:

WE ./walls3.xpm
NO ./walls.xpm

SO ./walls2.xpm

F 220,100,0
EA ./walls3.xpm

C 225,30,0

  1111111111111111111111111 <br>
  1000000000110000000000001 <br>
  1011000001110000000011111 <br>
1111000000000000000000001 <br>
**111111111011000001110000000000001** <br>
100000000011000001110111111111111 <br>
11110111111111011100000010001 <br>
11110111111111011101010010001 <br>
11000000110101011100000010001 <br>
10000000000000001100000010001 <br>
10000000000000001101010010001 <br>
11000001110101011111011110N0111 <br>
11110111 1110101 101111010001 <br>
11111111 1111111 111111111111 <br>

Observe que na linha marcada tem 0 com espaço por cima, isso é uma mapa inválido!

**Entretanto, 0's não podem estar antecedidos ou acompanhados por espaços, em todas as direções**
