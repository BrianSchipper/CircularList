struct ListElement
{
	// NODO, 2 campos, int y next el siguiente
	int element;
	ListElement *next;
};
class CircularList 
{
public:
	CircularList();// constructor
	~CircularList(); // destructor
	ListElement *pushfront(int elemVal);
	ListElement *pushback(int elemVal);

private:
	ListElement * root;
	ListElement * last;
	int element;
	
	
	CircularList::CircularList()
	{
		root->element = NULL;
	};


	CircularList::~CircularList()
	{
		delete[] element;
	};


	ListElement*pushFront(ListElement*&elemVal)
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
void erase()
{
	
}

int main() 
{
	
}