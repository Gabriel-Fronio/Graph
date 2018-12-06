#include <iostream>
#include <stdlib.h>

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

        try
        {
          graph->addVertex(vertex);
        }
        catch(std::exception e)
        {
          cout << e.what();
        }

        cout << "Valor inserido com sucesso" << endl << endl;
        cout << *graph;
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

        try
        {
          graph->addEdge(source, destination, weight);
        }
        catch(std::exception e)
        {
          cout << e.what();
        }

        cout << endl << endl;
        cout << *graph;

        break;
      }

      case 3:
      {
        cout << "Digite o nome do vertice a ser excluido: ";
        std::string vert;
        cin >> vert;
        cout << endl;

        try
        {
          graph->deleteVertex(vert);
        }
        catch(std::exception e)
        {
          cout << e.what();
        }
        cout << *graph;
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

        try
        {
          graph->deleteEdge(src, dest);
        }
        catch(std::exception e)
        {
          cout << e.what();
        }

        cout << *graph;

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
