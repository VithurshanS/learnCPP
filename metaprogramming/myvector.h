#ifndef myvector_h
#define myvector_h


#include <iostream>
#include <algorithm>

template <typename T>
class myvector{
private:
	T* data;
	int size;
	int capacity;
public:
	myvector(){
		data = new T[2]; //array defining and initialization
		size = 0;
		capacity = 2;
		std::cout<<"size is "<<size<<" capacity is "<<capacity<<std::endl;
	}

	
	
	void add(T ele){
		if(size==capacity){
			T* temp = new T[size*2]{};
			std::copy(data, data + size,temp);
			capacity = size*2;
			data = temp;
			delete[] data;
		}
		data[size] = ele;
		size++;
		std::cout<< "size  is "<< size <<"capacity is "<< capacity<<std::endl;
	}

	T* retdata(){
		return data;
	}
	void print(){
		for(int i = 0; i<size ;i++){
			std::cout << " " << data[i] <<" ";
		}
		std::cout<<std::endl;
	}
	void getcompletememorymap(){
		//std::cout<<" *& of data  : "<< *&data <<std::endl;
		std::cout<<" & of data  : "<< &data <<std::endl;
		std::cout<<"  data  : "<< data <<std::endl;
		std::cout<<"  &(data[0]) : "<< &(data[0]) <<std::endl;
		std::cout<<" * of data  : "<< *data <<std::endl;
	}
};


#endif
