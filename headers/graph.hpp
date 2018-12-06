#ifndef GraphClass

#define GraphClass

#include <vector>
#include <stdexcept>
#include <iostream>
#include <algorithm>
#include "SparseMatrix_headers/SparseMatrix.hpp"

using namespace std;

template <class T>
class Graph {
  private:
    SparseMatrix<int> matrix;
    std::vector<T> vet;
  
  public:
    Graph()
    {
      this->matrix = *new SparseMatrix<int>(0);
    };

    std::vector<T> getArray() const
    {
      return this->vet;
    };

    void addVertex(T vertex)
    {
      if(std::find(this->vet.begin(), this->vet.end(), vertex) != this->vet.end())
        throw new std::invalid_argument("Vertice ja existe no grafo");

      this->vet.push_back(vertex);
    };

    void addEdge(const T& source, const T& destination, int weight)
    {
      int indexSrc;
      int indexDest;
      try
      {
        indexSrc = findIndexOf(source);
        indexDest = findIndexOf(destination);
      }
      catch(std::exception e)
      {
        throw new std::exception(e);
      }

      if(indexSrc == indexDest)
        throw new std::invalid_argument("Destino nao pode ser igual a origem");

      this->matrix.addElement(weight, indexSrc, indexDest);
      this->matrix.addElement(weight, indexDest, indexSrc);
    }

    void deleteVertex(T vertex)
    {
      auto it = std::find(this->vet.begin(), this->vet.end(), vertex);
      if(it == this->vet.end())
        throw new std::invalid_argument("Vertice nao existe no grafo");

      int index = std::distance(this->vet.begin(), it);

      for(int i=0; i<this->vet.size(); i++)
      {
        if(getWeight(vertex, this->vet[i]) != 0)
          deleteEdge(vertex, this->vet[i]);
      }

      this->vet.erase(it);
    }
    
    void deleteEdge(const T& source, const T& destination)
    {
      int indexSrc;
      int indexDest;
      try
      {
        indexSrc = findIndexOf(source);
        indexDest = findIndexOf(destination);
      }
      catch(std::exception e)
      {
        throw new std::exception(e);
      }

      if(indexSrc == indexDest)
        throw new std::invalid_argument("Destino nao pode ser igual a origem");

      this->matrix.addElement(0, indexSrc, indexDest);
      this->matrix.addElement(0, indexDest, indexSrc);
    }

    int getWeight(const T& source, const T& destination) const
    {
      int indexSrc;
      int indexDest;
      try
      {
        indexSrc = findIndexOf(source);
        indexDest = findIndexOf(destination);
      }
      catch(std::exception e)
      {
        throw new std::exception(e);
      }

      return this->matrix.getInfo(indexSrc, indexDest);
    }

    int findIndexOf(const T& elem) const
    {
      auto it = std::find(this->vet.begin(), this->vet.end(), elem);
      if(it == this->vet.end())
        throw new std::invalid_argument("Vertice nao existe no grafo");

      return std::distance(this->vet.begin(), it);
    }
    
    friend std::ostream &operator<<(std::ostream &stream, const Graph &graph)
    {
      stream << "Vertices: [";
      for(int i=0; i<graph.getArray().size()-1; i++)
      {
        stream << graph.getArray()[i] << "; ";
      }
      stream << graph.getArray()[graph.getArray().size()-1] << "]" << endl;

      for(int j=0; j<graph.getArray().size(); j++)
      {
        for(int i=j+1; i<graph.getArray().size(); i++)
        {
          int weight = graph.getWeight(graph.getArray()[j], graph.getArray()[i]);
          if(weight != 0)
            stream << graph.getArray()[j] << " -> " << graph.getArray()[i] << ": " << weight << endl;
        }
      }
      return stream;
    }
};

#endif
