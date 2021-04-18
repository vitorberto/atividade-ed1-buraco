#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <bits/stdc++.h>

using namespace std;

#define BARALHOS 2
#define NAIPES 4
#define NUMEROS 13

#define JOGADORES 4
#define CARTAS_POR_MAO 11

class Carta
{
public:
  int baralho;
  int naipe;
  int carta;
};

int main()
{
  int x;
  int y;
  int z;

  /* --------------------- declarando e iniciando o array --------------------- */
  int ***cartas;
  cartas = new int **[BARALHOS];

  for (x = 0; x < BARALHOS; ++x)
  {
    cartas[x] = new int *[NAIPES];
    for (y = 0; y < NAIPES; ++y)
    {
      cartas[x][y] = new int[NUMEROS];
    }
  }

  /* --------------- adicionando valores a cada posição do array -------------- */
  for (x = 0; x < BARALHOS; ++x)
  {
    for (y = 0; y < NAIPES; ++y)
    {
      for (z = 0; z < NUMEROS; ++z)
      {
        cartas[x][y][z] = z + 1;
      }
    }
  }

  /* ---------------------------- mostrando cartas ---------------------------- */

  int **todascartas = new int *[CARTAS_POR_MAO * 4]; // <- array que contem os ponteiros dos valores das cartas

  srand(time(NULL)); // <- Gera uma seed de numeros aleatorios para a função rand() posteriormente
  z = 0;
  for (x = 0; x < JOGADORES; ++x)
  {
    cout << "Jogador " << x + 1 << ":" << endl;
    for (y = 0; y < CARTAS_POR_MAO; ++y)
    {
      int baralho = rand() % 2;
      int naipe = rand() % 4;
      int numeroCarta = rand() % 13;

      // guardando o ponteiro do valor da carta para comparação
      int *carta = &cartas[baralho][naipe][numeroCarta];
      ;
      sort(todascartas, todascartas + z);

      // verifica se o ponteiro da carta já foi armazenado no array
      int repeticoes = 0;
      for (int i = 0; i < z; i++)
        if (carta == todascartas[i])
          ++repeticoes;

      if (repeticoes > 0)
        --y;
      else
      {

        /* ------------------------- define o texto do naipe ------------------------ */
        string naipeTxt;
        string numeroTxt;

        switch (naipe)
        {
        case 0:
          naipeTxt = "Copas";
          break;
        case 1:
          naipeTxt = "Paus";
          break;
        case 2:
          naipeTxt = "Ouro";
          break;
        case 3:
          naipeTxt = "Espada";
          break;
        }

        /* -------------------- define o texto do numero da carta ------------------- */
        switch (*carta)
        {
        case 1:
          numeroTxt = "Ás";
          break;
        case 11:
          numeroTxt = "Valete";
          break;
        case 12:
          numeroTxt = "Rainha";
          break;
        case 13:
          numeroTxt = "Rei";
          break;
        default:
          numeroTxt = to_string(*carta);
        }

        // adicionando o ponteiro da carta ao array
        todascartas[z] = carta;
        z++;

        // apresentando a mão dos jogadores
        cout << numeroTxt << " de " << naipeTxt << " baralho " << baralho + 1 << endl;
      }
    }
    cout << endl;
  }
}
