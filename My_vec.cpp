#include "My_vec.h"

#include <iostream>
#include <stdexcept>

using namespace std;

/*
	Implement me:
	[X]My_vec();
	[X]~My_vec();
	[]My_vec(const My_vec& vec);
	[]My_vec& operator=(const My_vec& vec);
	[X]int get_size() const;
	[X]int get_capacity() const;
	[]char& operator[](int i) const;
	[]char& operator[](int i);
	[X]bool is_empty() const;
	[]char& elem_at_rank(int r) const;
	[]void insert_at_rank(int r, const char& elem);
	[]void replace_at_rank(int r, const char& elem);
	[]void remove_at_rank(int r);
*/

//Constructor
//Can be implemented like this, or simply in the header file
My_vec::My_vec(){
	size     = 0;
	capacity = 10;
	ptr = new char[10];
	return;
}

//Destructor
My_vec::~My_vec(){
	//delete stuff here
	cout << "Destructor called" << endl;
	delete[] ptr;
	return;
}
//Copy constructor
My_vec::My_vec(const My_vec& vec){
	size     = vec.get_size();
	capacity = vec.get_capacity();
	ptr = new char[capacity];
	for(int i = 0; i < size; i++){
		ptr[i] = vec.elem_at_rank(i);
	}
	return;
}
//Copy assignment
My_vec& My_vec::operator=(const My_vec& vec){
	cout << "Assignment operator called" << endl;
	delete ptr;
	size = vec.get_size();
	capacity = vec.get_capacity();
	ptr = new char[vec.get_capacity()];
	for(int i = 0; i < size; i++){
		ptr[i] = vec.elem_at_rank(i);
	}
	
	return *this;
}
//Size getter
int My_vec::get_size() const{
	return this->size;
}
//Capacity getter
int My_vec::get_capacity() const{
	return this->capacity;
}
//Enables the user to access the vector class as if an array, rather than using vec.at()
char& My_vec::operator[](int i) const{
	return ptr[i];
}
//Non-constant version of the above function
char& My_vec::operator[](int i){	
	return ptr[i];
}
//Checks if the vector class is empty
bool My_vec::is_empty() const{
	return this->size == 0;
}
//Returns the element at a specified rank
char& My_vec::elem_at_rank(int r) const{
	//If it is within the capacity, return the element
	//If it is not, throw an error
	if(r >= 0 && r < this->size){
		return this->ptr[r];
	}
	else{
		throw runtime_error("You've requested access to a memory address out of range.");
	}
}
void My_vec::insert_at_rank(int r, const char& elem){
	//Check if the rank is within the existing ranks
	//check if the capacity has room for one more
		//if capacity doesn't have room, create a new integer, delete the old integer, and set the pointer to the new one.	
		if(r >= 0 && r <= size){//move everything right, increment size, increment capacity if necessary.
			size++;
			if (size > capacity) {
				cout << "The size was creater than the capacity, increasing capacity from: " << capacity << "." << endl;
				increase_capacity();    //Doubles the array capacity
				cout << "Capacity increased to: " << capacity << "." << endl;
			}
			if(size == 1){ptr[0] = elem;}
			else{
				for(int i = size - 1; i >= r; i--){
					if(size > 0){ptr[i] = ptr[i-1];} //Moves all array values one to the right, leaving the previous r'th rank the same.
				}
				ptr[r] = elem;
				return;
			}
		}
		else{
			throw runtime_error("Attempted rank out of bounds.");
		}
}
//Self-written helper function to double size if the capacity is reached
void My_vec::increase_capacity() {
	this->capacity *= 2;            //Doubles the capacity
	char *temp = new char[capacity];//Allocates memory for a new character array of size capacity
	for(int i = 0; i < this->get_size();i++){
		temp[i] = ptr[i];         //Transfers all values from ptr to temp
	}
	delete ptr;              //Deletes the memory pointed to by ptr
    *ptr = *temp;             //Points the My_vec's dangling pointer to the newly allocated and initialized array.
    delete temp;                    //Is supposed to delete just the pointer temp, not the memory held at temp CHECK THIS IF PROBLEMS
	return;                         //Returns after handling all array doubling tasks
}
void My_vec::replace_at_rank(int r, const char& elem){
	if(r >= 0 && r <= this->size){
		this->ptr[r] = elem;
		return;
	}
	else{
		throw runtime_error("You've requested to replace a rank that does not exist within the vector.");
	}
}
void My_vec::remove_at_rank(int r){
	if(r >= 0 && r <= this->size){
		//move everything left, decrement size
		this->size--;                        
		for(int i = r; i < this->size; i++){ //Or equal to? Check for problems.
			ptr[i] = ptr[i + 1];           //Moves all values left
		}
	}
	else{
		throw runtime_error("You've requested to remove a rank that does not exist within the vector.");
	}
	return;
}
ostream& operator<<(ostream& out, const My_vec& vec){
	out << "Vector contents: ";
	for(int i = 0; i < vec.get_size(); i++){
		out << vec.elem_at_rank(i) << " ";
	}
	out << endl;
	return out;
}
//Findmax assumes unsorted, and is in linear time
int find_max_index(const My_vec& v,int size){
	int max = 0;
	for(int i = 1; i < size; i++){
		if(v.elem_at_rank(i) > v.elem_at_rank(max)){
			max = i;
		}
	}
	return max;
}
void sort_max_nlogn(My_vec& vec){
	char temp;         //Change to variable of T for templated
	for(int i = vec.get_size() - 1; i > 0; i /= 2){
		for(int j = 0; j + i < vec.get_size(); j++){
			if(vec[j] > vec[j + i]){
				cout << vec[j] << " was greater than " << vec[j + i] << "." << endl;
				temp = vec[j];
				vec.replace_at_rank(j, vec[j + i]);
				vec.replace_at_rank(j + i, temp);
			} 
		}
	}
	cout << "Sorted!" << endl;
}
///
void sort_max(My_vec& vec){
	char temp[vec.get_size()];
	char temp_hold;
	int max_index = find_max_index(vec, vec.get_size());
	int ns = 0; //Number sorted
	
	for(int i = 0; i < vec.get_size(); i++){
		temp[i] = vec[i]; //Set temp equal to all values of vec.
	}
	for(int j = vec.get_size() - 1; j >= 0; --j){
		vec[j] = temp[max_index];                  //Puts the greatest element at the rightmost array slot 
		temp_hold = temp[vec.get_size() - ns];      //Holds the rightmost, non-sorted value of the temporary array.
		temp[vec.get_size() - ns] = temp[max_index];//Puts the maximum index into a sorted position
		temp[max_index] = temp_hold;               //Sets the temp at the maximum index to the previous rightmost slot.
		max_index = find_max_index(vec, j);
		ns++;
	}
}

