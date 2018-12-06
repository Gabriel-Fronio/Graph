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

    bool addVertex(T vertex)
    {
      if(std::find(this->vet.begin(), this->vet.end(), vertex) != this->vet.end())
        return false;

      this->vet.push_back(vertex);
      return true;
    };

    bool addEdge(const T& source, const T& destination, int weight)
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
        return false;
      }

      if(indexSrc == indexDest)
        return false;

      this->matrix.addElement(weight, indexSrc, indexDest);
      this->matrix.addElement(weight, indexDest, indexSrc);

      return true;
    }

    bool deleteVertex(T vertex)
    {
      auto it = std::find(this->vet.begin(), this->vet.end(), vertex);
      if(it == this->vet.end())
        return false;

      int index = std::distance(this->vet.begin(), it);

      for(int i=0; i<this->vet.size(); i++)
      {
        if(getWeight(vertex, this->vet[i]) != 0)
          deleteEdge(vertex, this->vet[i]);
      }

      this->vet.erase(it);
      return true;
    }
    
    bool deleteEdge(const T& source, const T& destination)
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
        return false;
      }

      if(indexSrc == indexDest)
        return false;

      this->matrix.addElement(0, indexSrc, indexDest);
      this->matrix.addElement(0, indexDest, indexSrc);

      return true;
    }

    int getWeight(const T& source, const T& destination) const
    {
      int indexSrc = findIndexOf(source);
      int indexDest = findIndexOf(destination);

      if(indexSrc < 0 || indexDest < 0)
        return -1;

      return this->matrix.getInfo(indexSrc, indexDest);
    }

    int findIndexOf(const T& elem) const
    {
      auto it = std::find(this->vet.begin(), this->vet.end(), elem);
      if(it == this->vet.end())
        return -1;

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
