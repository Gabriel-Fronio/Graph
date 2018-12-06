#include <iostream>
#include <stdlib.h>
#include <stdexcept>

#include "..\headers\graph.hpp"

using namespace std;

int main()
{
  Graph<std::string>* graph = new Graph<std::string>();

  while (true) {

    system("cls");
    cout << "Digite o numero de uma opcao:" << endl;

    cout << "1) Inserir Vertice" << endl;
    cout << "2) Inserir Caminho" << endl;
    cout << "3) Excluir Vertice" <<endl;
    cout << "4) Excluir Caminho" << endl;
    cout << "5) Consultar peso" << endl;
    cout << "6) Ver grafo" << endl;
    cout << "0) Sair" << endl << endl;

    int option;
    cin >> option;

    switch (option) {
      case 0:
        exit(0);

      case 1:
      {
        cout << "Digite o nome do vertice que deseja inserir: ";
        std::string vertex;
        cin >> vertex;
        cout << endl << endl;
        

        if(!graph->addVertex(vertex))
          cout << "Um erro ocorreu" << endl;
        else
        {
          cout << "Valor inserido com sucesso" << endl << endl;
          cout << *graph;
        }
        break;
      }

      case 2:
      {
        cout << "Digite o nome do vertice de origem: ";
        std::string source;
        cin >> source;
        cout << endl;

        cout << "Digite o nome do vertice de destino: ";
        std::string destination;
        cin >> destination;
        cout << endl;

        cout << "Digite o peso desse caminho: ";
        int weight;
        cin >> weight;
        cout << endl;

        if(!graph->addEdge(source, destination, weight))
          cout << "Um erro ocorreu" << endl;
        else
        {
          cout << endl << endl;
          cout << *graph;
        }

        break;
      }

      case 3:
      {
        cout << "Digite o nome do vertice a ser excluido: ";
        std::string vert;
        cin >> vert;
        cout << endl;

        if(!graph->deleteVertex(vert))
          cout << "Um erro ocorreu" << endl;
        else
        {
          cout << endl << endl;
          cout << *graph;
        }

        break;
      }

      case 4:
      {
        cout << "Digite o nome do vertice de origem: ";
        std::string src;
        cin >> src;
        cout << endl;

        cout << "Digite o nome do vertice de destino: ";
        std::string dest;
        cin >> dest;
        cout << endl;


        if(!graph->deleteEdge(src, dest))
          cout << "Um erro ocorreu" << endl;
        else
        {
          cout << endl << endl;
          cout << *graph;
        }

        break;
      }

      case 5:
      {
        cout << "Digite o nome do vertice de origem: ";
        std::string src;
        cin >> src;
        cout << endl;

        cout << "Digite o nome do vertice de destino: ";
        std::string dest;
        cin >> dest;
        cout << endl;

        int weight = graph->getWeight(src, dest);

        if(weight == -1)
          cout << "Um ou ambos os vertices nao exsitem no grafo" << endl;
        else if (weight == 0)
          cout << "Nao ha caminho entre esses vertices" << endl;
        else
          cout << "Peso: " << weight;

        cout << endl << endl;

        break;
      }

      case 6:
        cout << *graph;
        break;

      default:
        cout << "Digite uma opcao valida";
    }
    cout << endl << endl;
    cout << "Pressione [enter] para continuar...";
    cin.sync();
    cin.ignore();
  }
}
