#include <assert.h>

using namespace std;

/typedef unsigned int size_t; // Si usan visual studio (probablemente) no necesitan este typedef

struct ListElement {
	int val;
	ListElement* next;
};

class CircularList {
public:
	CircularList(); // constructor
    	~CircularList(); // destructor
    
	ListElement* pushFront(int elemVal); //agrega un elemento al principio
	ListElement* pushBack(int elemVal); // agrega un elemento al final
	
	void insertNextTo(ListElement* element, int elemVal); // ignorar
	void erase(ListElement* element); // elimina un elemento
	
	void clear(); // borra todo
	
	ListElement* getFirst(); // devuelve el primer elemento
	ListElement* getLast(); // devjelve el ultimo elemento

	size_t getElementCount(); // cantidad de elementos
private:
        // TODO: Complete
	ListElement * root; 
	ListElement * last;
	int element;
	
	
	CircularList::CircularList()
	{
		root->element = NULL;
	// la lista inicia con root apuntando a null	
	};

	CircularList::~CircularList()
	{
		delete[] element;
	};


	ListElement*pushFront(ListElement*&elemVal)
		// evaluo la cantidad de elementos y agrego uno nuevo
	{
	if (root->element =NULL)
		ListElement*newElement = new ListElement();
		this -> newElement= newElement;
	else 
		

	private:
		int newelement;
	}


	ListElement*pushBack(ListElement*&elemVal)
	{
		
	}

};
};
void erase() 
{
	
}
//  TODO: Complete

void testPushBack() {
	CircularList listA;
	assert(listA.getElementCount() == 0);
	assert(listA.getLast() == listA.getFirst());

	listA.pushBack(100);
	assert(listA.getElementCount() == 1);
	assert(listA.getFirst()->val == 100);
	assert(listA.getLast()->val == 100);
	assert(listA.getLast()->next == listA.getFirst());

	listA.pushBack(200);
	assert(listA.getElementCount() == 2);
	assert(listA.getFirst()->val == 100);
	assert(listA.getLast()->val == 200);
	assert(listA.getLast()->next == listA.getFirst());

	listA.pushBack(300);
	assert(listA.getElementCount() == 3);
	assert(listA.getFirst()->val == 100);
	assert(listA.getLast()->val == 300);
	assert(listA.getLast()->next == listA.getFirst());


	size_t sum = 0;
	ListElement* itr = listA.getFirst();
	do {
		sum += itr->val;
		itr = itr->next;
	} while (itr != listA.getFirst()); // Because this is a circular list
	assert(sum == 600); // 100 + 200 + 300 = 600
}

void testErase() {
    CircularList list;
    ListElement* one = list.pushBack(1);
    ListElement* two = list.pushBack(2);
    ListElement* three = list.pushBack(3);
    ListElement* four = list.pushBack(4);
    ListElement* five = list.pushBack(5);
    assert(list.getElementCount() == 5);
    assert(list.getLast()->next == list.getFirst());
    
    list.erase(three);
    assert(list.getElementCount() == 4);
    assert(list.getLast()->next == list.getFirst());

    list.erase(one);
    assert(list.getElementCount() == 3);
    assert(list.getFirst()->val != 1);
    assert(list.getLast()->next == list.getFirst());
    
    list.erase(five);
    assert(list.getElementCount() == 2);
    assert(list.getLast()->val != 5);
    assert(list.getLast()->next == list.getFirst());

    list.erase(two);
    list.erase(four);
    assert(list.getElementCount() == 0);
}

void testPushFront() {
    CircularList list;
    list.pushFront(1);
    list.pushFront(2);
    list.pushFront(3);
    assert(list.getElementCount() == 3);
    assert(list.getFirst()->val == 3);
    assert(list.getLast()->val == 1);
}

int main() {
    testPushBack();	
	testErase();
	testPushFront();

	return 0;
}
