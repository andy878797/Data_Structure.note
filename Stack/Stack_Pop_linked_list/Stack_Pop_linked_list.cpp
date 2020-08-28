#include<iostream>
class stackList;
class stackNode{
private:
	int data;
	stackNode *next;
public:
	stackNode():data(0){
	next = 0;
	}
	stackNode(int x):data(x){
		next = 0;
	}
	stackNode(int x, stackNode *nextNode):data(x),next(nextNode){
	};
	friend class stackList;
};
class stackList{
private:
	stackNode *top;
	int size;
public:
	stackList():size(0),top(0){};
	void Push(int x);
    void Pop();
    bool IsEmpty();
    int Top();
    int getSize();
};

/*bool stackList::isempty(){
	return (size == 0);
}*/


void stackList::Push(int x){
	if(IsEmpty()){
		top = new stackNode(x);
        size++;
        return;
	}
	stackNode *newnode = new stackNode(x);
	newnode->next = top;
	top = newnode;
	size++; 
}

void stackList::Pop(){
	if(IsEmpty()){
		std::cout<<"Stack is empty.\n";
		return;
	}
	stackNode *deletenode = top;
	top = top->next;
	delete deletenode;
	deletenode = 0;
	size--;
}

bool stackList::IsEmpty(){

    return (size == 0);     // if size==0, return true
}

int stackList::Top(){
	if(IsEmpty()){
		std::cout<<"Stack is empty.\n";
		return -1;
	}
	return top->data;
}

int stackList::getSize(){
	return size;
}

int main(){
	stackList s;
	s.Pop();
    s.Push(32);
    s.Push(4);
    std::cout << "\ntop: " << s.Top() << "\nsize: " << s.getSize() << std::endl;        
    s.Push(15);
    std::cout << "\ntop: " << s.Top() << "\nsize: " << s.getSize() << std::endl;         
    s.Pop();
    s.Pop();
    std::cout << "\ntop: " << s.Top() << "\nsize: " << s.getSize() << std::endl;          
    s.Pop();
    std::cout << "\ntop: " << s.Top() << "\nsize: " << s.getSize() << std::endl;

    return 0;
}







