#include <assert.h>

using namespace std;

struct ListElement
{
	// tuve que cambiar "element" por "val"  o en cada uno de las lineas de codigo de los test
	int val;
	ListElement *next;
};
class CircularList
{
public:
	CircularList();// constructor
	~CircularList(); // destructor
	ListElement *pushFront(int elemVal);// coloca un elemento al inicio de las lista
	ListElement *pushBack(int elemVal);// coloca un elemento al final de la lista
	void erase(ListElement*element);// borra un elemento de la lista
	void clear(); // borra todo 
	ListElement*getFirst();// devuelve el primer elemento de la lista
	ListElement*getLast(); // devuelve el ultimo elemento de la lista
	size_t getElementCount(); // devuelve la cantidad de elementos de una lista

private:
	ListElement * root;
	ListElement * last;
	ListElement * first;
	int element;

};
CircularList::CircularList()
{
	root = first = last = NULL;
};

CircularList::~CircularList()
{
	//delete[]
};

ListElement*CircularList::pushFront(int elemVal)
{
	element = elemVal;
	ListElement*next;
	ListElement * newElement = new ListElement();// puntero que vaya a nuevo elemento
	newElement->val = elemVal; // nuevo elemento apunta a elemento

	if (root == NULL)
	{
		newElement->next = newElement;
		first = last = newElement;
	}
	else
	{
		newElement->next = next;
	}
}

ListElement*CircularList::pushBack(int elemVal)
{
	element = elemVal;
	ListElement*next;
	ListElement * newElement = new ListElement();// puntero que vaya a nuevo elemento
	newElement->val = elemVal; // nuevo elemento apunta a elemento

	if (root == NULL)
	{
		newElement->next = newElement;
		first = last = newElement;
	}
	else
		newElement->next = next;
}

void CircularList::erase(ListElement* element)
{
	if (first == last)
	{
		first, last, root = NULL;
	}
	else
	{
		ListElement* itr = first;
		ListElement* prev = last;

		do {
			prev->next = itr->next;
			if (itr == first)
				first = itr->next;
			if (itr == last)
				last = prev;
			delete itr;
			prev = itr;
			itr = itr->next;

		} while (itr != first);
	}
}

ListElement*CircularList::getLast()
{
	return last;
}
ListElement*CircularList::getFirst()
{
	return first;
}
size_t CircularList::getElementCount()
{
	size_t count = 0;
	if (root != NULL) {
		ListElement* itr = first;
		do {
			count++;
			itr = itr->next;

		} while (itr != first);
		return count;
	}
}

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