// main.cpp
//Tests all functionality of the My_vec class.

#include <iostream>
#include <stdexcept>
#include <string>
#include "Templated_My_vec.h"

using namespace std;

int main(){
    
// Some test cases are expected to throw an exception.
// Add more try and catch blocks as necessary for your code to finish execution.
    
try{
    // define an object v of My_vec type
    // insert 'B' at the rank 0 into the vector v
	// use the overloaded operator << to display vector elements
    // display the vector v size
    cout << "Trial 1 Character" << endl;
    cout << "Making an object and inserting 'B' at rank 0" << endl;
	Templated_My_vec<char>* v = new Templated_My_vec<char>;
    v->insert_at_rank(0, 'B');
    cout << *v;
    cout << "Vector size: " << v->get_size() << endl;
    cout << "Trial 1 successful" << endl << endl;
    
    ///////////////////////////////////////////////////////////////////////////////////////////////
    cout << "Trial 1 Integer" << endl;
    cout << "Making an object and inserting 2 at rank 0" << endl;
	Templated_My_vec<int>* v_int = new Templated_My_vec<int>;
    v_int->insert_at_rank(0, 2);
    cout << *v_int;
    cout << "Vector size: " << v_int->get_size() << endl;
    cout << "Trial 1 successful" << endl << endl;
    
    ///////////////////////////////////////////////////////////////////////////////////////////////
    cout << "Trial 1 Float" << endl;
    cout << "Making an object and inserting 2.5 at rank 0" << endl;
	Templated_My_vec<float>* v_dub = new Templated_My_vec<float>;
    v_dub->insert_at_rank(0, 2.5);
    cout << *v_dub;
    cout << "Vector size: " << v_dub->get_size() << endl;
    cout << "Trial 1 successful" << endl << endl;
    
	// insert 'A' at the rank 0  to the vector v
	// use the overloaded operator << to display vector elements
	// display the vector v size
	cout << "Trial 2 Character" << endl;
	cout << "Inserting A at rank 0" << endl;
	v->insert_at_rank(0, 'A');
	cout << *v;
	cout << "Vector size: " << v->get_size() << endl;
	cout << "Trial 2 successful" << endl << endl;
	
	///////////////////////////////////////////////////////////////////////////////////////////////
	cout << "Trial 2 Integer" << endl;
	cout << "Inserting 1 at rank 0" << endl;
	v_int->insert_at_rank(0, 1);
	cout << *v_int;
	cout << "Vector size: " << v_int->get_size() << endl;
	cout << "Trial 2 successful" << endl << endl;
	  
	///////////////////////////////////////////////////////////////////////////////////////////////
	cout << "Trial 2 Float" << endl;
	cout << "Inserting 1.0 at rank 0" << endl;
	string a = "ABC";
	v_dub->insert_at_rank(0, 1.5);
	cout << *v_dub;
	cout << "Vector size: " << v_dub->get_size() << endl;
	cout << "Trial 2 successful" << endl << endl;

	// insert 'D' at the rank 10 into the vector v
    // use the overloaded operator << to display vector elements
    // display the vector v size
    cout << "Trial 3 Character" << endl;
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
	
	///////////////////////////////////////////////////////////////////////////////////////////////
	cout << "Trial 3 Integer" << endl;
    cout << "Inserting 11 at rank 10 (an error is expected)" << endl;
    try{
		cout << "Inserting at rank 10" << endl;
		v_int->insert_at_rank(10, 11);
		cout << *v_int << endl;
		cout << "Vector size: " << v_dub->get_size() << endl;
	}
	catch(const runtime_error &e){
		cout << "Error: " << e.what() << endl;
	}
	cout << "Trial 3 successful" << endl << endl;
	
	///////////////////////////////////////////////////////////////////////////////////////////////
	cout << "Trial 3 Float" << endl;
    cout << "Inserting 11.5 at rank 10 (an error is expected)" << endl;
    try{
		cout << "Inserting at rank 10" << endl;
		v_dub->insert_at_rank(10, 11.5);
		cout << *v_dub << endl;
		cout << "Vector size: " << v_dub->get_size() << endl;
	}
	catch(const runtime_error &e){
		cout << "Error: " << e.what() << endl;
	}
	cout << "Trial 3 successful" << endl << endl;
	// remove a character at the rank 1 from the vector v
	// use the overloaded operator << to display vector elements
	// display the vector v size
	cout << "Trial 4 Character" << endl;
	cout << "Removing the character at rank 1" << endl;
	v->remove_at_rank(1);
	cout << *v << endl;
	cout << "Vector size: " << v->get_size() << endl;
	cout << "Trial 4 successful" << endl << endl;
	
	///////////////////////////////////////////////////////////////////////////////////////////////
	cout << "Trial 4 Integer" << endl;
	cout << "Removing the character at rank 1" << endl;
	v_int->remove_at_rank(1);
	cout << *v_int << endl;
	cout << "Vector size: " << v_int->get_size() << endl;
	cout << "Trial 4 successful" << endl << endl;
	
	///////////////////////////////////////////////////////////////////////////////////////////////
	cout << "Trial 4 Float" << endl;
	cout << "Removing the character at rank 1" << endl;
	v_dub->remove_at_rank(1);
	cout << *v_dub << endl;
	cout << "Vector size: " << v_dub->get_size() << endl;
	cout << "Trial 4 successful" << endl << endl;
	
	// replace a character at the rank 0 by the character 'E'
	// use the overloaded operator << to display vector elements
	// display the vector v size
	cout << "Trial 5 Character" << endl;
	cout << "Replace character of v at rank 0 with 'E'" << endl;
	v->replace_at_rank(0, 'E');
	cout << *v << endl;
	cout << "Vector size: " << v->get_size() << endl;
	cout << "Trial 5 successful" << endl << endl;
	
	///////////////////////////////////////////////////////////////////////////////////////////////
	cout << "Trial 5 Integer" << endl;
	cout << "Replace character of v at rank 0 with 5" << endl;
	v_int->replace_at_rank(0, 5);
	cout << *v_int << endl;
	cout << "Vector size: " << v_int->get_size() << endl;
	cout << "Trial 5 successful" << endl << endl;
	
	///////////////////////////////////////////////////////////////////////////////////////////////
	cout << "Trial 5 Float" << endl;
	cout << "Replace character of v at rank 0 with 5.5" << endl;
	v_dub->replace_at_rank(0, 5.5);
	cout << *v_dub << endl;
	cout << "Vector size: " << v_dub->get_size() << endl;
	cout << "Trial 5 successful" << endl << endl;
	
	// create a copy v1 of the vector v using a copy constructor
	// use the overloaded operator << to display the vector v1
        // replace a character at the rank 2 of the vector v1 with the character 'Y'
	// use the overloaded operator << to display vector v1 elements
	cout << "Trial 6 Character" << endl;
	cout << "Creating a copy of v at v1 with copy constructor, then (unsuccessfully) replacing at rank 2" << endl;
	cout << "Working with vector v1: " << endl;
	Templated_My_vec<char>* v1(v);
	cout << *v1 << endl;
	try{
		v1->replace_at_rank(2, 'Y');
	}
	catch(const runtime_error &e){
		cout << "Error: " << e.what() << endl;
	}
	cout << *v1 << endl;
	cout << "Trial 6 successful" << endl << endl;
	
	///////////////////////////////////////////////////////////////////////////////////////////////
	cout << "Trial 6 Integer" << endl;
	cout << "Creating a copy of v_int at v1_int with copy constructor, then (unsuccessfully) replacing at rank 2" << endl;
	cout << "Working with vector v1: " << endl;
	Templated_My_vec<int>* v1_int(v_int);
	cout << *v1_int << endl;
	try{
		v1_int->replace_at_rank(2, 25);
	}
	catch(const runtime_error &e){
		cout << "Error: " << e.what() << endl;
	}
	cout << *v1_int << endl;
	cout << "Trial 6 successful" << endl << endl;
	
	///////////////////////////////////////////////////////////////////////////////////////////////
	cout << "Trial 6 Float" << endl;
	cout << "Creating a copy of v_dub at v1_dub with copy constructor, then (unsuccessfully) replacing at rank 2" << endl;
	cout << "Working with vector v1: " << endl;
	Templated_My_vec<float>* v1_dub(v_dub);
	cout << *v1_dub << endl;
	try{
		v1_dub->replace_at_rank(2, 25.5);
	}
	catch(const runtime_error &e){
		cout << "Error: " << e.what() << endl;
	}
	cout << *v1_dub << endl;
	cout << "Trial 6 successful" << endl << endl;
			
	// define an object v2 of My_vec type
	// insert 'K' at the rank 0 into the vector v2
	// use the overloaded operator << to display vector elements
    // display the vector v2 size
	cout << "Trial 7 Character" << endl;
    	Templated_My_vec<char>* v2 = new Templated_My_vec<char>;
    	cout << "v2 created" << endl;
    	v2->insert_at_rank(0, 'K');
    	cout << *v2 << endl;
	cout << "Trial 7 successful" << endl << endl;
	
	///////////////////////////////////////////////////////////////////////////////////////////////
	cout << "Trial 7 Integer" << endl;
    Templated_My_vec<int>* v2_int = new Templated_My_vec<int>;
    cout << "v2_int created" << endl;
    v2_int->insert_at_rank(0,11);
    cout << *v2_int << endl;
	cout << "Trial 7 successful" << endl << endl;
	
	///////////////////////////////////////////////////////////////////////////////////////////////
	cout << "Trial 7 Float" << endl;
    Templated_My_vec<float>* v2_dub = new Templated_My_vec<float>;
    cout << "v2_dub created" << endl;
    v2_dub->insert_at_rank(0, 11.5);
    cout << *v2_dub << endl;
	cout << "Trial 7 successful" << endl << endl;
	
    // test the assignment operator and copy the vector v1 to v2 
 	// Set v2 to '1','2','3','4','5'
 	// use the overloaded operator << to display vector v2
    // display the vector v2 size
    cout << "Trial 8 Character" << endl;
	cout << "v2 before: " << *v2;
	v2 = v1;
	cout << "v2 after v2 = v1: " << *v2;
	v2->remove_at_rank(0);
	v2->insert_at_rank(0, '1');
	v2->insert_at_rank(1, '2');
	v2->insert_at_rank(2, '3');
	v2->insert_at_rank(3, '4');
	v2->insert_at_rank(4, '5');
	cout << "v2 after insertions: " << *v2;
	
	///////////////////////////////////////////////////////////////////////////////////////////////
	cout << "Trial 8 Integer" << endl;
	cout << "v2_int before: " << *v2_int;
	v2_int = v1_int;
	cout << "v2_int after v2_int = v1_int: " << *v2_int;
	v2_int->remove_at_rank(0);
	v2_int->insert_at_rank(0, 1);
	v2_int->insert_at_rank(1, 2);
	v2_int->insert_at_rank(2, 3);
	v2_int->insert_at_rank(3, 4);
	v2_int->insert_at_rank(4, 5);
	cout << "v2_int after insertions: " << *v2_int;
	
	///////////////////////////////////////////////////////////////////////////////////////////////
	cout << "Trial 8 Float" << endl;
	cout << "v2_dub before: " << *v2_dub;
	v2_dub = v1_dub;
	cout << "v2_dub after v2_dub = v1_dub: " << *v2_dub;
	v2_dub->remove_at_rank(0);
	v2_dub->insert_at_rank(0, 1.5);
	v2_dub->insert_at_rank(1, 2.5);
	v2_dub->insert_at_rank(2, 3.5);
	v2_dub->insert_at_rank(3, 4.5);
	v2_dub->insert_at_rank(4, 5.5);
	cout << "v2_dub after insertions: " << *v2_dub;

    // test the function find_max_index using v2
    int temp = find_max_index(*v2, v2->get_size());
    cout << "Max value of Character v2: " << v2->elem_at_rank(temp) << " at rank: " << temp << endl;
	// test the function sort_max using v2
	cout << "Sorting Character v2" << endl;
	cout << "Before: " << *v2;
	sort_max(*v2);
	cout << "After: " << *v2;
	
	///////////////////////////////////////////////////////////////////////////////////////////////
	temp = find_max_index(*v2_int, v2_int->get_size());
    cout << "Max value of Integer v2: " << v2_int->elem_at_rank(temp) << " at rank: " << temp << endl;
	// test the function sort_max using v2
	cout << "Sorting Integer v2" << endl;
	cout << "Before: " << *v2_int;
	sort_max(*v2_int);
	cout << "After: " << *v2_int;	
		
	///////////////////////////////////////////////////////////////////////////////////////////////
	temp = find_max_index(*v2_dub, v2_dub->get_size());
    cout << "Max value of Float v2: " << v2_dub->elem_at_rank(temp) << " at rank: " << temp << endl;
	// test the function sort_max using v2
	cout << "Sorting Float v2" << endl;
	cout << "Before: " << *v2_dub;
	sort_max(*v2_dub);
	cout << "After: " << *v2_dub;
	
	// replace in the vector v2 a character at the rank 14 with 'S'
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


