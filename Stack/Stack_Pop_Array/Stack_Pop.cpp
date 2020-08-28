#include<iostream>
#include<stdlib.h>

class StackArray{
private:
    int top;                 // index of top element
    int capacity;            // allocated memory space of array
    int *stack;              // array representing stack
    void DoubleCapacity();   // double the capacity of stack
public:
    StackArray():top(-1),capacity(1){    // constructor
        stack = new int[capacity];       // initial state: top=-1, capacity=1
    }
    void Push(int x);
    void Pop();
    bool IsEmpty();
    int Top();
    int getSize();
};
/*voidStackArray::DoubleCapacity(){
	capacity *= 2;
	int *newstack = new int[capacity];
	for(int i = 0;i<capacity/2;i++)
		//newStack[i] = stack[i];
		newStack[i] = stack[i];
	delete [] stack;
	stack = newStack;
}*/
void StackArray::DoubleCapacity(){

    capacity *= 2;                            // double capacity
    int *newStack = new int[capacity];        // create newStack

    for (int i = 0 ; i < capacity/2; i++) {   // copy element to newStack
        newStack[i] = stack[i];
    }

    delete [] stack;              // release the memory of stack
    stack = newStack;             // redirect stack to newStack
}

void StackArray::Push(int x){
	if(top == capacity - 1)
		DoubleCapacity();
	stack[++top] = x;
}

void StackArray::Pop(){
	if(IsEmpty()){
		std::cout << "Stack is empty.\n";
		return;
	}
	top--;
}

bool StackArray::IsEmpty(){
	return (top==-1);
}

int StackArray::Top(){
	if(IsEmpty()){
		std::cout<<"Stack is empty.\n";
		return -1;
	}
	return stack[top];
}

int StackArray::getSize(){
	return top+1;
}

int main(){
	StackArray s;
	s.Pop();
	s.Push(14);
	s.Push(3);
	std::cout << "\ntop: "<<s.Top()<<"\nsize: "<<s.getSize()<<std::endl;
	s.Push(12);
	std::cout << "\ntop: "<<s.Top()<<"\nsize: "<<s.getSize()<<std::endl;
	s.Pop();
	s.Pop();
	std::cout << "\ntop: "<<s.Top()<<"\nsize: "<<s.getSize()<<std::endl;
	s.Pop();
	std::cout << "\ntop: "<<s.Top()<<"\nsize: "<<s.getSize()<<std::endl;;
	
	return 0;
}








































