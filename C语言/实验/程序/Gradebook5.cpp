#include<iostream>

using namespace std;
#include "GradeBook.h"
int main()
{
	GradeBook book1("CS1");
	GradeBook book2("CS2");
	cout << "book1 created for course: " << book1.getCourseName()
	<< "\nbook2 created for course : " << book2.getCourseName() << endl;
	
	
	return 0;
}
