#include "Classes.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <cstdlib>
#include <iomanip>
using namespace std;

static int uid = 0;
static int num = 0;

istream& Classes::read(istream &inf)
{

  cout << "Enter the number of students: ";
  cin >> numstud;
  cout <<  "Enter the number of rows: ";
  cin >> rows;
  cout << "Enter the number of columns: ";
  cin >> columns;

  array = new Student[numstud];
  //arrangement = new int[rows][columns];
  arrangement = new int*[rows];
  for(int i=0; i < rows; i++)
    arrangement[i] = new int[columns];
  string s;
  Student temp;

  while(getline(inf, s, ','))
  {
    temp.name = s;
    //cout << s << endl;
    getline(inf, s, ',');
    temp.grade = s.at(0); 
    maps.insert(Map::value_type(temp.name, ++uid));
    this->array[num++] = temp;
  } //reading every line


  if((rows*columns) < numstud)
   exit (0);

  string str = "Patty Li";
  if(maps.find(str) != maps.end())
    cout << "Name found\n";
  else
    cout << "Name not found\n";

  cout << "Any physical disabilities?\n";
  cout << " 1 - Yes\n";
  cout << " 2 - No\n";
  int n;
  cout << "Enter the choice: ";
  cin >> n;

  physical(inf, n);

  sorting();
  print();

  return inf;
} //read()

istream& Classes::physical(istream& inf, int n)
{

  //istream in;
  if(n==1)
  {
    string s;
    cout << "Enter the student's name: ";
    cin>>s;
    getline(cin, s,'\n'); 
    cout << "Seating choice: \n";
    cout << "1 - First row required\n";
    cout << "2 - Aisle seat required\n";
    cout << "3 - Empty seat required\n";
    cout << "Enter the choice of seating: ";
    cin >> n;
    s.resize(s.size()-1);
    //getline(in, s);
    switch (n)
    {
      case 1: firstrow(s);
              break;
      case 2: aisleseat(s);
              break;
      case 3: emptyseat(s);
              break;
      default: cout << "No available seating\n";
               break;
    }
    cout << "Any physical disabilities?\n";
    cout << " 1 - Yes\n";
    cout << " 2 - No\n";
    cout << "Enter the choice: ";
    cin >> n;

    if(n==1)
      physical(inf, 1);
  }
  else
    ;

  return inf;
}//physical()

void Classes::firstrow(string s)
{
  if(maps.find(s) != maps.end())
  {
    for(int i=0; i < columns; i++)
    {
      if(!arrangement[0][i])
      {  //   cout << maps.find(s)->second << endl;
        arrangement[0][i] = maps.find(s)->second;
        break;
      }
    }
  }
  else
  {
    cout << "No student with the name\n";
    //break; 
  }
}//aisleseat()

void Classes::aisleseat(string s)
{
  int flag = 0;
  if(maps.find(s) != maps.end())
  {
    for(int i=0; i < rows; i++)
    {
      if(!arrangement[i][0])
      {//cout << maps.find(s)->second << endl;

        arrangement[i][0] = maps.find(s)->second; flag = 1;
        break;
      }

    }
    if(flag == 0)
    {
      for(int i = 0; i < rows; i++)
      {
         if(!arrangement[i][columns-1])
         {//cout << maps.find(s)->second << endl;

           arrangement[i][columns-1] = maps.find(s)->second;

           exit (0);
         }
      }
    }
  }
  else
    cout << "No student with this name\n";

}//aisleseat()

void Classes::emptyseat(string s)
{
  if(!arrangement[0][0])
  {//cout << maps.find(s)->second << endl;

    arrangement[0][0] = maps.find(s)->second;
    return;
  }  
  if(!arrangement[0][columns-1])
  {//cout << maps.find(s)->second << endl;

    arrangement[0][columns-1] = maps.find(s)->second;
    return;
  }
  if(!arrangement[rows-1][0])
   {//cout << maps.find(s)->second << endl;

    arrangement[rows-1][0] = maps.find(s)->second;
    return;
  }
  if(!arrangement[rows-1][columns-1])
 {//cout << maps.find(s)->second << endl;

    arrangement[rows-1][columns-1] = maps.find(s)->second;
    return;
  }

  else
    cout << "No empty seating available\n";

}//emptyseat()

void Classes::sorting()
{
  int i, j, k, flag = 0;
  Student temp;
  for(i = 0; i < numstud; i++)
  {
    temp = array[i]; flag = 0;
    if(temp.grade == 'F')
    {
      for(j = 0; j <  rows; j++)
      {
        for(k = 0; k < columns; k++)
        {
          if(!arrangement[j][k]){
            flag = 1;
            arrangement[j][k] = maps.find(temp.name)->second;
            break;
          }
        }
        if(flag == 1)
          break;
      }
    }
  }

  for(i = 0; i < numstud; i++)
  {
    temp = array[i];
    if(temp.grade == 'C')
    {
      for(j = 0; j <  rows; j++)
      {
        for(k = 0; k < columns; k++)
        {
          if(!arrangement[j][k])
            arrangement[j][k] = maps.find(temp.name)->second;
        }
      }
    }
  }

  for(i = 0; i < numstud; i++)
  {
    temp = array[i];
    if(temp.grade == 'B')
    {
      for(j = 0; j <  rows; j++)
      {
        for(k = 0; k < columns; k++)
        {
          if(!arrangement[j][k])
            arrangement[j][k] = maps.find(temp.name)->second;
        }
      }
    }
  }

  for(i = 0; i < numstud; i++)
  {
    temp = array[i];
    if(temp.grade == 'A')
    {
      for(j = 0; j <  rows; j++)
      {
        for(k = 0; k < columns; k++)
        {
          if(!arrangement[j][k])
            arrangement[j][k] = maps.find(temp.name)->second;
        }
      }
    }
  }

}//sorting()

void Classes::print()
{
  int i,j;
  for(i = 0; i< rows; i++)
  {
    for(j = 0; j < columns; j++)
      cout << setw(4) << right << arrangement[i][j];

    cout << endl;
  }

} //print()
