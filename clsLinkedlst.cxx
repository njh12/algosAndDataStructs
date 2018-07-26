#include "clslinkedlst.hxx"
#include <iostream>

using namespace std;



//Consructor
clslinkedlst::clslinkedlst()
{
	this->ptr_headnode = NULL;
	this->ptr_tailnode = NULL;
	this->int_lstsize = 0;
};

//Destructor
clslinkedlst::~clslinkedlst()
{
	lstnodes *ptr_cur = this->ptr_headnode;
	lstnodes *ptr_next = ptr_cur;
	while (ptr_cur != NULL) {
		ptr_next = ptr_cur->ptr_nextNode;
		delete ptr_cur;
		ptr_cur = ptr_next;
	};
	this->ptr_headnode = NULL;
	this->ptr_tailnode = NULL;
	int_lstsize = 0;
};

//Creates a new node and sets its data to int_inval.

lstnodes* clslinkedlst::newNode(int int_inval)
{
	lstnodes *ptr_newNode = new lstnodes();
	ptr_newNode->int_val = int_inval;
	ptr_newNode->ptr_nextNode = NULL;
	return(ptr_newNode);
};

/*Inserts nodes into the end of linked list and increment the size of the list by one.
  If the ptr_headnode is NULL insert int_inval into ptr_headnode and set the tailnode equal to ptr_headnode.
  else...Create a new node and set ptr_tailnode equal to the new node.*/

void clslinkedlst::insertEnd(int int_inval)
{
	if (this->ptr_headnode == NULL) {
		cout << " List is empty inserting at the head.\n";
		this->ptr_headnode = newNode(int_inval);
		this->ptr_tailnode = this->ptr_headnode;
	}else { 
		this->ptr_tailnode->ptr_nextNode = newNode(int_inval);
		this->ptr_tailnode = this->ptr_tailnode->ptr_nextNode;
	};

	this->int_lstsize++;
};


/* Deletes items from linked list and decrements the size of list.
	If the ptr_current nodes value in the list does NOT equal int_inval
	traverse to the next node...else the value was found in the ptr_cur node.
	If the lst nodes position with the value is in the front of the list
	move the ptr_headnode to the next node...else if he value eqauls the value in the ptr_tailnode
	set the ptr_tailnode to NULL and reset the tails location...else the value is in the middle of the list
	so shorten the list by removing the ptr_cur node from the list.*/

void clslinkedlst::delval(int int_inval)
{
	lstnodes *ptr_cur = this->ptr_headnode;
	lstnodes *ptr_prev = ptr_cur;
	cout << "Searching for the value to delete: " << int_inval << "\n";

	while (ptr_cur != NULL) {
		if (ptr_cur->int_val != int_inval) {
			ptr_prev = ptr_cur;
			ptr_cur = ptr_cur->ptr_nextNode;
		} else {
			cout << " Value: " << int_inval << " found.\n";
			if (ptr_cur == this->ptr_headnode)
				this->ptr_headnode = this->ptr_headnode->ptr_nextNode;
			else if (ptr_cur == this->ptr_tailnode) {
				this->ptr_tailnode = ptr_prev;
				this->ptr_tailnode->ptr_nextNode = NULL;
			} else
				ptr_prev->ptr_nextNode = ptr_cur->ptr_nextNode;

			cout << " Value deleted\n";
			this->int_lstsize--;
			delete ptr_cur;
			ptr_cur = NULL;
		};
	};
};

/*	Inserts int_inval into the linked list by position.
	If the list is empty insert int_inval at head/tail of list.
	While the list is NOT empty traverse to determine where to insert new node.
	If the int_inval is less then the ptr_cur-> val and ptr_cur = this->ptr_headnode
	the int_inval needs to become the head...else the int_inval needs to be inserted 
	somewhere in the middle of the list. If the ptr_cur is at the end of the list and greater then the ptr_tailnode
	int_inval needs to be inserted at the end of the list. 
	If the int_inval is greater then ptr_cur val continue traversing the list.*/

void clslinkedlst::insValByPos(int int_inval)
{
	cout << "Searching for the correct position to insert the value: " << int_inval << "\n";
	lstnodes *ptr_cur = this->ptr_headnode;
	lstnodes *prev = ptr_cur;

	if (ptr_cur == NULL)
		insertEnd(int_inval);
	while (ptr_cur != NULL) {
		if (int_inval < ptr_cur->int_val) {

			lstnodes *ptr_temp = newNode(int_inval);

				if (ptr_cur == this->ptr_headnode) { 
					ptr_temp->ptr_nextNode = ptr_cur;
					this->ptr_headnode = ptr_temp;
				} else {
					prev->ptr_nextNode = ptr_temp;
					ptr_temp->ptr_nextNode = ptr_cur;
				};

				ptr_cur = this->ptr_tailnode->ptr_nextNode;
				this->int_lstsize++;

		}
		else if (int_inval > ptr_cur->int_val) {
			if (ptr_cur == this->ptr_tailnode) {
				insertEnd(int_inval);
				ptr_cur = this->ptr_tailnode->ptr_nextNode;
			}
			else {
				prev = ptr_cur;
				ptr_cur = ptr_cur->ptr_nextNode;
			}
		} else {
			cout << "Value already present.\n";
			ptr_cur = this->ptr_tailnode->ptr_nextNode;

		};
	};
};

void clslinkedlst::setTail()
{
	lstnodes *ptr_cur;
	ptr_cur = this->ptr_headnode;
	while (ptr_cur->ptr_nextNode != NULL)
		ptr_cur = ptr_cur->ptr_nextNode;
	this->ptr_tailnode = ptr_cur;
};

//Prints all items in linked list.
void clslinkedlst::lstprint()
{
	lstnodes *ptr_cur;
	ptr_cur = this->ptr_headnode;
	cout << "Printing the values within the linked list.\n";
	while (ptr_cur != NULL) {
		cout << "Value in Node is:" << ptr_cur->int_val << '\n';
		ptr_cur = ptr_cur->ptr_nextNode;
	};
	cout << "\n The head value is:" << this->ptr_headnode->int_val
		<< "\n The tail value is:" << this->ptr_tailnode->int_val
		<< "\n The list holds " << this->int_lstsize << " elements.\n";

	delete ptr_cur;
	ptr_cur = NULL;
};
