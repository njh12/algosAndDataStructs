#include "clslinkedlst.hxx"
#include <iostream>
using namespace std;

//Consructor
clslinkedlst::clslinkedlst()
{
	this->headnode = NULL;
	this->tailnode = NULL;
	this->lstsize = 0;
};	
//Destructor
clslinkedlst::~clslinkedlst()
{
	lstnodes *cur = this->headnode;
	lstnodes *next;
	while( cur != NULL ) {
		next = cur->nextNode;
		delete cur;
		cur = next;
	};
	this->headnode = NULL;
	this->tailnode = NULL;
	lstsize = 0;
};

//Creates a new node and sets its data to inval.
lstnodes* clslinkedlst::newNode(int inval)
{	
	lstnodes *tempnode = new lstnodes();
	tempnode->val = inval;
	tempnode->nextNode = NULL;
	return(tempnode);	
};
//Inserts items into the end of linked list
void clslinkedlst::insertEnd(int inval)
{	
	if (this->headnode == NULL){
		cout <<" List is empty inserting at the head.\n";
		this->headnode = newNode(inval);
		this->tailnode = this->headnode;		
	}
	else{
		cout <<"Inserting value at the tail.\n";
		this->tailnode->nextNode = newNode(inval);
		this->tailnode = this->tailnode->nextNode; 		
	};
	this->lstsize++;
};
	

//Deletes item from linked list
void clslinkedlst::delval(int inval)
{
	lstnodes *cur = this->headnode;
	lstnodes *prev = cur;
	
	cout << "Searching for the value to delete: "<<inval<< "\n";
	while (cur != NULL){
		if (cur->val != inval){
			cout <<"\n Value Not found. Traversing to next node\n";
			prev = cur;
			cur = cur->nextNode;
		} else{
			cout <<" Value: "<<inval <<" found.\n";
			prev->nextNode = cur->nextNode;
			delete cur;
			cur = NULL;
			this->lstsize--;
			setTail();
			cout <<" Value deleted\n";
		};
	};
};

void clslinkedlst::insValByPos(int inval)
{	
	cout << "Searching for the correct position to insert the value: "<<inval<< "\n";	
	//If the linked list tail value is less then the inval you can just insert at the end of the list.
	if (this->tailnode->val < inval){
		insertEnd(inval);
	}
	else{
		//lstnodes *prev;
		lstnodes *cur = this->headnode;
		lstnodes *prev = cur;
		while (cur != NULL){
			if (cur->val < inval){
				cout <<"\n List value less then inval. Traversing to next node\n";
				prev = cur;
				cur = cur->nextNode;
			} else if(cur->val >= inval){ //cur->val is greater then inval so insert before cur.
				cout <<" Found position for insert.\n";
				prev->nextNode = newNode(inval);
				prev->nextNode->nextNode = cur;
				cout <<" Value inserted.\n";
				delete cur;
				cur = NULL;
			};
		};
		this->lstsize++;
		setTail();	
	};
};

void clslinkedlst::setTail()
{
	lstnodes *cur;
	cur = this->headnode;
	while (cur->nextNode != NULL)
		cur = cur->nextNode;
	this->tailnode = cur;
	delete cur;
	cur = NULL;
};
//Prints all items in linked list.
void clslinkedlst::lstprint()
{
	lstnodes *cur;
	cur = this->headnode;
	cout <<"Printing the values within the linked list.\n";
	while(cur != NULL){
		cout <<"Value in Node is:"<<cur->val<<'\n';
		cur = cur->nextNode;
		};
	delete cur;
	cur = NULL;
	cout <<"\n The head value is:" << this->headnode->val
		 <<"\n The tail value is:" << this->tailnode->val
		 <<"\n The list holds "<<this->lstsize<<" elements.\n";
};
