//#include "MY_VEC.H" No longer necessary.

#include <iostream>
#include <stdexcept>

using namespace std;

/*My_vec.h
Carson Hanel
Header file for a vector data structure.
*/



using namespace std;
//Below is header file declarations
template<typename T> 
class Templated_My_vec {
	
	//member variables
	int size, capacity;
	T *ptr;
	
public:	
	//member functions
	Templated_My_vec<T>(){
		size     = 0;
		capacity = 10;
		ptr = new T[10];
		return;
	};
	~Templated_My_vec<T>(){
		cout << "Destructor called" << endl;
		delete[] ptr;
		return;
	};
	Templated_My_vec<T>(const Templated_My_vec<T>& vec){
		size     = vec.get_size();
		capacity = vec.get_capacity();
		ptr = new T[capacity];
		for(int i = 0; i < size; i++){
			ptr[i] = vec.elem_at_rank(i);
		}
		return;
	};
	Templated_My_vec<T>& operator=(const Templated_My_vec<T>& vec){
		delete ptr;
		size = vec.get_size();
		capacity = vec.get_capacity();
		ptr = new T[vec.get_capacity()];
		for(int i = 0; i < size; i++){
			ptr[i] = vec.elem_at_rank(i);
		}
		return *this;
	};
	int get_size() const{return size;};
	int get_capacity() const{return capacity;};
	T& operator[](int i) const{return ptr[i];};
	T& operator[](int i){return ptr[i];};
	bool is_empty() const{return size==0;};
	T& elem_at_rank(int r) const{	
		if(r >= 0 && r < this->size){
			return this->ptr[r];
		}
		else{throw runtime_error("You've requested access to a memory address out of range.");}
	};
	void insert_at_rank(int r, const T& elem){
		if(r >= 0 && r <= size){
			//move everything right, increment size, increment capacity if necessary.
			size++;
			if (size > capacity) {
				cout << "The size was creater than the capacity, increasing capacity from: " << capacity << "." << endl;
				increase_capacity();    //Doubles the array capacity
				cout << "Capacity increased to: " << capacity << "." << endl;
			}
			if(size == 1){
				ptr[0] = elem;
			}
			else{
				for(int i = size - 1; i >= r; i--){
					if(size > 0){ptr[i] = ptr[i-1];} //Moves all array values one to the right, leaving the previous r'th rank the same.
				}
				ptr[r] = elem;
				return;
			}
		}
		else{throw runtime_error("Attempted rank out of bounds.");}
	};
	void replace_at_rank(int r, const T& elem){
		if(r >= 0 && r <= size){
			ptr[r] = elem;
			return;
		}
		else{
			throw runtime_error("You've requested to replace a rank that does not exist within the vector.");
		}
	};
	void remove_at_rank(int r){
		if(r >= 0 && r <= size){
		//move everything left, decrement size
			this->size--;                        
			for(int i = r; i < size; i++){ 
				ptr[i] = ptr[i + 1];           //Moves all values left
			}
		}
		else{
			throw runtime_error("You've requested to remove a rank that does not exist within the vector.");
		}
		return;
	};
	void increase_capacity(){
		capacity *= 2;                  //Doubles the capacity
		T *temp = new T[capacity];//Allocates memory for a new character array of size capacity
		for(int i = 0; i < this->get_size();i++){
			temp[i] = ptr[i];           //Transfers all values from ptr to temp
		}
		delete ptr;                     //Deletes the memory pointed to by ptr
   	 	ptr = temp;                     //Points the My_vec's dangling pointer to the newly allocated and initialized array.
		return;                         //Returns after handling all array doubling tasks
	};
	friend ostream& operator<<(ostream& out, const Templated_My_vec<T>& vec){	
		out << "Vector contents: ";
		for(int i = 0; i < vec.get_size(); i++){
			out << vec.elem_at_rank(i) << " "; //Iteratively outputs vector
		}
		out << endl;
		return out;
	};
};
template<typename T> 	
int find_max_index(const Templated_My_vec<T>& v,int size){
	int max = 0;
	for(int i = 1; i < size; i++){
		if(v.elem_at_rank(i) > v.elem_at_rank(max)){
			max = i;
		}
	}
	return max;
}
template<typename T> 
void sort_max(Templated_My_vec<T>& vec){
	T temp;         //Change to variable of T for templated
	for(int i = vec.get_size() - 1; i > 0; i /= 2){
		for(int j = 0; j + i < vec.get_size(); j++){
			if(vec[j] < vec[j + i]){
				temp = vec[j];
				vec.replace_at_rank(j, vec[j + i]);
				vec.replace_at_rank(j + i, temp);
			} 
		}
	}
	cout << "Sorted!" << endl;
}



