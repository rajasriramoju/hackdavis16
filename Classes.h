#ifndef CLASSES_H
#define CLASSES_H

#include <iostream>
#include "Student.h"
#include <map>
#include <string>
#include <cstdlib>
using namespace std;

typedef map<string, int> Map;
typedef multimap<int, int> Relation;


class Classes : public Student
{  
   public:
   int numstud;
   int rows;
   int columns;

   Student *array;
   int **arrangement;
   Map maps;   
   Relation relation;
    
   istream& read(istream &inf);
   istream& physical(istream &inf, int n);
   void firstrow(string s);
   void aisleseat(string s);
   void emptyseat(string s);
   void sorting();
   void print();
    
};

#endif


