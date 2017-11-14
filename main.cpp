#include <iostream>
#include "Classes.h"
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{

  Classes class1;
  Student student;

  ifstream inf(argv[1]);

//  if((class1.rows * class1.columns) < class1.numstud)
  //{
    //cout << "Incorrect choice of rows and columns\n";
    //return;
 // }

  class1.read(inf);
    





  

}


