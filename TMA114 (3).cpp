///////////////////////////////////////////////////
//
// ΕΡΓΑΣΙΑ 2
// File: TMA114ii.cpp
// Name: Christos Vyzantios
// Student number:P06179
//
//
///////////////////////////////////////////////////




#include <iostream>
#include <cassert>
#include <cstdlib>
#include "tree.h"
#include <string.h>
#include <stdlib.h>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;

struct tm {
  int tm_min;   // minutes (λεπτα), 0-59 
  int tm_hour;  // hours (ωρες), 0-23 
};

const int SIZE = 100;

struct inv_type {
  char Kωδικος_πτησης[40]; // κωδικος πτησης
  Αν=tm_hour;
  Αφ=tm_hour;
  Μεγ_Αφ=tm_hour;

  
}  invtry[SIZE];


void enter(), init_list(), display();
void update(), input(int i), delete();
int menu();

int main()
{
  char choice;

  init_list();

  for(;;) {
    choice = menu();
    switch(choice) {
      case 'e': enter();
        break;
      case 'a': display();
        break;
      case 'u': update();
        break;
      case 'd': delete();
        break;
      case 'q': return 0;
      

    }
  }
}

// Initialize the inv_type_info array.
void init_list()
{
  int t;

  // a zero length name signifies empty
  for(t=0; t<SIZE; t++) *invtry[t].item = '\0';
}

// Get a menu selection.
int menu()
{
  char ch;

  cout << '\n';
  do {
    cout << "(E)nter\n";
    cout << "(A)isplay\n";
    cout << "(U)pdate\n";
    cout << "(D)elete\n";
    cout << "(Q)uit\n\n";
    cout << "choose one: ";
    cin >> ch;
  } while(!strchr("eduq", tolower(ch)));
  return tolower(ch);
}

// Εισαγωγή κωδικών στην λίστα .
void enter()
{
  int i;

  // find the first free structure
  for(i=0; i<SIZE; i++)
    if(!*invtry[i].item) break;

  // i will equal SIZE if the list is full
  if(i==SIZE) {
    cout << "List full.\n";
    return;
  }

  input(i);
}

// Input the information.
void input(int i)
{
  // Εισαγωγη Στοιχειων(Δεδομένων)
  cout << "Kωδικος_πτησης: ";
  cin >> invtry[i].Κωδικος;

  cout << "Αν: ";
  cin >> invtry[i].Αν;

  cout << "Αφ: ";
  cin >> invtry[i].Αφ;

  cout << "Μεγ_ΑΦ: ";
  cin >> invtry[i].Μεγ_ΑΦ;

}

// Modify an existing item.
void update()
{
  int i;
  char Kωδικος_πτησης[80];

  cout << "Kωδικος_πτησης: ";
  cin >> Kωδικος_πτησης;

  for(i=0; i<SIZE; i++)
    if(!strcmp(name, invtry[i].item)) break;

  if(i==SIZE) {
    cout << "Ο Κωδικος πτησης δεν βρεθηκε.\n";
    return;
  }

  cout << "Εισαγωγή νέας πληροφοριας.\n";
  input(i);
}

// Display the list.
void display()
{
  int t;

  for(t=0; t<SIZE; t++) {
    if(*invtry[t].Αν) {
      cout << invtry[t].Kωδικος_πτησης << '\n';
      cout << "Αν: $" << invtry[t].Αν;
      cout << invtry[t].Αφ << '\n';
      cout << "Αφ: " << invtry[t].Αφ;
      cout << invtry[t].Αφ << '\n';
      cout << invtry[t].Μεγ_Αφ << '\n';
    }
 ///////////////////////////////////////////////////
//
// Δημιουργία Constructor για την κλάση του δένδρου
// Η αρχή γίνεται με κενό δενδρο (δηλαδή χωρίς πτήσεις.
//

class Node {
private:
int data;
Node *left;
Node *right;
Node *parent;
public:
// Constructor
Node(int data)
{
this?>Data = Αν;
left = 0;
right = 0;
parent = 0;
}
int getData() { return data; }
Node *getLeft() { return left; }
Node *getRight() { return right; }
Node *getParent() { return parent; }
void setLeft(Node *left)
{
this?>left = left;
}
void setRight(Node *right)
{
this?>right = right;
}
void setParent(Node *parent)
{
this?>parent = parent;
}
};
class Tree {
private:
Node *root;
Node *search(int data)
{
Node *n = root;
while (n != 0)
{
if (Αν < n?>getΑν())
n = n?>getLeft();
else if (Data > n?>getData())
n = n?>getRight();
else
return n; // n == n?>getData()
}
return 0; // not found
}
public:
// Constructor
Tree()
{
root = 0;
}

// Αναζητηση στοιχειων πτήσης βασει κωδικου
bool contains(int Αν)
{
Node *n = search(data);
return (n != 0);
}
// Insert element
void add(int data)
{
Node *parent = 0;
Node *n = root;
while (n != 0)
{
parent = n;
if (data < n?>getData())
n = n?>getLeft();
else if (data > n?>getData())
n = n?>getRight();
else
break; // data == n?>getData()
}
Node *newNode = new Node(data);
newNode?>setParent(parent);
if (parent == 0)
{
root = newNode;
}
else if (data < parent?>getData())
{
parent?>setLeft(newNode);
}
else if (data > parent?>getData())
{
parent?>setRight(newNode);
}
else
{
// Already in tree
delete newNode;
	}

return 0;


 
}







  