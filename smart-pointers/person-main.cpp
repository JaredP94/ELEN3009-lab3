// Note, specific namespace members are imported into the global namespace which is
// better practice than importing all of the members
// eg: "using std::string;", "using std::unique_ptr;" etc. rather than "using namespace std;"

#include <memory> // required for smart pointers
using std::unique_ptr;
using std::make_unique;
using std::shared_ptr;
using std::make_shared;

#include <string>
#include <iostream>
using std::string;
using std::endl;
using std::cout;

#include "Person.h"

Person printName()
{
	Person thabo{"Thabo",12};
	cout << thabo.name() << endl;
	return thabo;
} //thabo goes out of scope

shared_ptr<Person> printName2()
{
	auto maryanne_ptr = make_shared<Person>("Maryanne",12);
	cout << maryanne_ptr->name() << endl;
	return maryanne_ptr;
} //maryanne_ptr goes out of scope

void printName3(shared_ptr<Person> person_ptr)
{
	cout << person_ptr->name() << endl;
	return;
} //person_ptr goes out of scope


int main()
{
    auto sandile_ptr = make_unique<Person>("Sandile",15);    

    auto thabo_in_main = printName();
    cout << thabo_in_main.name() << endl;

    auto person_ptr_in_main = printName2();
    printName3(person_ptr_in_main);

    sandile_ptr = make_unique<Person>("Sandile2",11);  
    cout << sandile_ptr->age() << endl;

    return 0;
} //sandile_ptr goes out of scope
  //thabo_in_main goes out of scope
  //person_ptr_in_main goes out of scope

  //thabo memory released
  //maryanne memory released
  //sandile_ptr memory release
  
  //maryanne = 2
  //person_ptr = 0
  //sandile_ptr = 0
  //thabo_in_main = 0
  //person_ptr_in_main = 1
  
  //sandile_ptr and thabo_in_main are stored on the stack which follows a LIFO memory release principle. Thus thabo_in_main gets deallocated first

