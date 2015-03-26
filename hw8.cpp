#include <iostream>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable: 4996)
using namespace std;

/****************** Forward Declarations ******************/
class container;
class person;

void branching(char c, container** pointerToHead);  // given
char* get_name();           // given
//void printFirst(container* root);         // given

int insertion(container** pointerToHead);     // Question 2
class person* search(container* root, char* sname);     // Question 3
void deleteAll(container** pointerToHead);    // Question 4
//void printAll(container* root);       // Question 5



// A class for nodes of the linked list. 
class container {
public:
  person *plink;  // points to a person object
  container *next;

  container(){
    plink = NULL;
    next = NULL;
  }
};


// A class to hold attributes of a person
class person {
public:
  char *name;
  char *email;
  int phone;
  // constructor that uses the parameters to initialize the class properties
  person(char *cName, char *cEmail, int iPhone) {     
    name = new (char[32]);  // acquiring memory for storing name
    email = new (char[32]);   // acquiring memory for storing email
    strcpy(name, cName);    // initialize name
    strcpy(email, cEmail);  // initialize email
    phone = iPhone;     // initialize phone
  };

  /* deletes memory created in constructor */
  virtual ~person() {       
    delete name;
    delete email;
  }
};

int insertion(container** pointerToHead) {
  container** head;
  head = pointerToHead;
  container* c = new container();  
  char nName[32], nEmail[32];
  int nPhone;

  cout << "Enter name, phone, email:\n";
  cin >> nName >> nEmail >> nPhone;
  person* p = new person(nName, nEmail, nPhone); 
  

  // put person in container
  c->plink = p;
  // check if list is empty
  if(!*head) {
    *head = c;
    cout << "yarr!\n";
  }
  else {
    container *current, *previous;
    current = previous = *head;
    while (current) {
      if (strcmp(c->plink->name, current->plink->name) >= 0) {
        if (current == *head) {
          *head = c;
          cout << "ye made it matey\n";
        } else {
          previous->next = c;
        }
        c->next = current;
        break;
      } else if (!current->next) {
        current->next = c;
        c->next = NULL;
        break;
      }

      previous = current;
      current = current->next;
     
    }
  }
}

/*Find's a person based on their name */
class person* search(container* root, char* sname) {
   
  container* c = new container();  
  c = root;
  
  while(c) {
    if(strcmp(sname, c->plink->name) == 0) {
    cout << "mission complete, person found";
      break;  
    
    }
  c = c->next;
  }
  return c->plink;
}

int main()
{
  container* head = NULL; // Declare head as a local variable of main function
  // Print a menu for selection
  char ch = 'i';
  do {
    cout<< "Enter your selection" << endl;
    cout<< "\ti: insert a new entry" << endl;
    cout<< "\tr: delete all entries" << endl;
    cout<< "\ts: search an entry" << endl;
    cout<< "\tp: print all entries" << endl;
    cout<< "\tq: quit" << endl;
    cin >> ch;
    ch = tolower(ch); // Convert any uppercase char to lowercase.
    branching(ch, &head);
    cout << endl;
  } while (ch != 'q');
  return 0;
}
// Branch to different tasks: insert a person, search for a person, delete a person
// print all added persons.
void branching(char c, container** pointerToHead)
{
  class person *pp; 
  char *p;
  switch (c) {
  case 'i':
    insertion(pointerToHead);
    break;
  case 's':
    p = get_name();
    pp = search(*pointerToHead, p);
    break;
  case 'r':
    deleteAll(pointerToHead);
    break;
  case 'p':
   // printAll(*pointerToHead);
    break;
  case 'q':
    deleteAll(pointerToHead); // free all memory
    break;
  default:
    cout <<"Invalid input\n";
  }
}
// Read the input from the user.
char * get_name()
{
  char *p = new(char[32]); // Use dynamic memory which does not go out of scope
  cout << "Please enter a name for the search: " <<endl;
  cin >> p;
  return p;
};
void printFirst(container* root)
{
  if (root != NULL)
  {
    cout << "\n\nname = " << root->plink->name << endl;
    cout << "email = " << root->plink->email << endl;
    cout << "phone = " << root->plink->phone << endl;
  }
}
