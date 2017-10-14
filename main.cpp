// main.cpp
//Tests all functionality of the My_vec class.

#include <iostream>
#include <stdexcept>
#include "My_vec.h"

using namespace std;

int main(){
    
// Some test cases are expected to throw an exception.
// Add more try and catch blocks as necessary for your code to finish execution.
    
try{
    // define an object v of My_vec type
    // insert 'B' at the rank 0 into the vector v
	// use the overloaded operator << to display vector elements
    // display the vector v size
    cout << "Trial 1" << endl;
    cout << "Making an object and inserting 'B' at rank 0" << endl;
	My_vec* v = new My_vec;
    v->insert_at_rank(0, 'B');
    cout << *v << endl;
    cout << "Vector size: " << v->get_size() << endl;
    cout << "Trial 1 successful" << endl << endl;
    
	// insert 'A' at the rank 0  to the vector v
	// use the overloaded operator << to display vector elements
	// display the vector v size
	cout << "Trial 2" << endl;
	cout << "Inserting A at rank 0" << endl;
	v->insert_at_rank(0, 'A');
	cout << *v << endl;
	cout << "Vector size: " << v->get_size() << endl;
	cout << "Trial 2 successful" << endl << endl;

	// insert 'D' at the rank 10 into the vector v
    // use the overloaded operator << to display vector elements
    // display the vector v size
    cout << "Trial 3" << endl;
    cout << "Inserting D at rank 10 (an error is expected)" << endl;
    try{
		cout << "Inserting at rank 10" << endl;
		v->insert_at_rank(10, 'D');
		cout << *v << endl;
		cout << "Vector size: " << v->get_size() << endl;
	}
	catch(const runtime_error &e){
		cout << "Error: " << e.what() << endl;
	}
	cout << "Trial 3 successful" << endl << endl;
	
	// remove a character at the rank 1 from the vector v
	// use the overloaded operator << to display vector elements
	// display the vector v size
	cout << "Trial 4" << endl;
	cout << "Removing the character at rank 1" << endl;
	v->remove_at_rank(1);
	cout << *v << endl;
	cout << "Vector size: " << v->get_size() << endl;
	cout << "Trial 4 successful" << endl << endl;

	// replace a character at the rank 0 by the character 'E'
	// use the overloaded operator << to display vector elements
	// display the vector v size
	cout << "Trial 5" << endl;
	cout << "Replace character of v at rank 0 with 'E'" << endl;
	v->replace_at_rank(0, 'E');
	cout << *v << endl;
	cout << "Vector size: " << v->get_size() << endl;
	cout << "Trial 5 successful" << endl << endl;
	
	// create a copy v1 of the vector v using a copy constructor
	// use the overloaded operator << to display the vector v1
        // replace a character at the rank 2 of the vector v1 with the character 'Y'
	// use the overloaded operator << to display vector v1 elements
	cout << "Trial 6" << endl;
	cout << "Creating a copy of v at v1 with copy constructor, then (unsuccessfully) replacing at rank 2" << endl;
	cout << "Working with vector v1: " << endl;
	My_vec* v1(v);
	cout << *v1 << endl;
	try{
		v1->replace_at_rank(2, 'Y');
	}
	catch(const runtime_error &e){
		cout << "Error: " << e.what() << endl;
	}
	cout << *v1 << endl;
	cout << "Trial 6 successful" << endl << endl;
	// define an object v2 of My_vec type
	// insert 'K' at the rank 0 into the vector v2
	// use the overloaded operator << to display vector elements
    	// display the vector v2 size
	cout << "Trial 7" << endl;
    	My_vec* v2 = new My_vec;
    	cout << "v2 created" << endl;
    	v2->insert_at_rank(0, 'K');
    	cout << *v2 << endl;
	cout << "Trial 7 successful" << endl << endl;

    	// test the assignment operator and copy the vector v1 to v2 
 	// Set v2 to '1','2','3','4','5'
 	// use the overloaded operator << to display vector v2
    	// display the vector v2 size
    	cout << "V2 now:(before copying) " << *v2 << endl;
    	v2 = v1;
    	cout << "V2 after:(copying v1) " << *v2 << endl;
	v2->remove_at_rank(0);
	v2->insert_at_rank(0, '5');
	v2->insert_at_rank(1, '4');
	v2->insert_at_rank(2, '3');
	v2->insert_at_rank(3, '2');
	v2->insert_at_rank(4, '1');
	cout << "v2 is now: " << *v2;


    	// test the function find_max_index using v2
	int max = find_max_index(*v2, v2->get_size());
	cout << "The max index is: " << max << " and holds: " << v2->elem_at_rank(max) << endl;
	// test the function sort_max using v2
	cout << "Sorting v2" << endl;
	sort_max(*v2);
	cout << "Sorted v2: " << *v2;
	// replace in the vector v2 a character at the rank 14 with 'S'
	cout << "Trying to replace rank 14 of v2 with 'S'" << endl;
	try{
	v2->replace_at_rank(14, 'S');
	}
	catch(const runtime_error &e){
		cout << "Error: " << e.what() << endl;
	}
}
catch(exception &error){
	cout << "Error: " << error.what() << endl;
}
}

