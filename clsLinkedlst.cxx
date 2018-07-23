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
	while (cur != NULL) {
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
//Inserts nodes into the end of linked list.
//and increments the size of the list by one.
void clslinkedlst::insertEnd(int inval)
{
	//If...The headnode is NULL insert the inval into the headnode and set the tail equal to the headnode.
	if (this->headnode == NULL) {
		cout << " List is empty inserting at the head.\n";
		this->headnode = newNode(inval);
		this->tailnode = this->headnode;
	}
	//else...Create a new node and set tailnode equal to the new node.
	else { 
		this->tailnode->nextNode = newNode(inval);
		this->tailnode = this->tailnode->nextNode;
	};
	this->lstsize++;
};


//Deletes items from linked list and adjusts the tail and decrements the size of list.
void clslinkedlst::delval(int inval)
{
	lstnodes *cur = this->headnode;
	lstnodes *prev = cur;
	cout << "Searching for the value to delete: " << inval << "\n";

	while (cur != NULL) {
		//If...the current nodes value in the list does NOT equal inval
		//traverse to the next node...else...the value was found in the current node.
		if (cur->val != inval) {
			cout << "\n Value Not found. Traversing to next node\n";
			prev = cur;
			cur = cur->nextNode;
		} else {
			cout << " Value: " << inval << " found.\n";
			/*if...The lst nodes position with the value is in the front of the list
			  move the headnode to the next node.
			  else if...The value eqauls the value in the tailnode
			  set the tailnode to NULL and reset the tails location.
			  else...The value is in the middle of the list
			  so shorten the list by removing the cur node from the list.*/
			if (cur == this->headnode)
				this->headnode = this->headnode->nextNode;
			else if (cur == this->tailnode) {
				this->tailnode = prev;
				this->tailnode->nextNode = NULL;
			} else
				prev->nextNode = cur->nextNode;
			cout << " Value deleted\n";
			this->lstsize--;
			delete cur;
			cur = NULL;
		};
	};
};

// Inserts inval into the linked list by position.
void clslinkedlst::insValByPos(int inval)
{
	cout << "Searching for the correct position to insert the value: " << inval << "\n";
	lstnodes *cur = this->headnode;
	lstnodes *prev = cur;
	//The list is empty insert inval at end of list.
	if (cur == NULL)
		insertEnd(inval);
	// Traverse list with cur while list is NOT empty and determine where to insert new node.
	while (cur != NULL) {
		if (inval < cur->val) {
				/*The list size is equal to 1 and the inval is less then the cur val.
				   so the inval needs to become the head.*/
				if (cur == this->headnode) { 
					lstnodes *temp = newNode(inval);
					temp->nextNode = cur;
					this->headnode = temp;
					cur = this->tailnode->nextNode;
					this->lstsize++;
				}
				//The inval needs to be inserted somewhere in the middle of the list.
				else {
					cout << "\n  inval less then list value\n";
					lstnodes *temp = newNode(inval);
					prev->nextNode = temp;
					temp->nextNode = cur;
					cur = this->tailnode->nextNode;
					this->lstsize++;
				};
		} else if (inval > cur->val) {
				/*cur is at the end of the list and greater then the tailnode
				  so inval needs to beinserted at the end of the list.
				  inval is greater then cur val so continue traversing the list.*/
				if (cur == this->tailnode) {
					insertEnd(inval);
					cur = this->tailnode->nextNode;
				} else {
					prev = cur;
					cur = cur->nextNode;
				};
		};
	};
};

void clslinkedlst::setTail()
{
	lstnodes *cur;
	cur = this->headnode;
	while (cur->nextNode != NULL)
		cur = cur->nextNode;
	this->tailnode = cur;
};
//Prints all items in linked list.
void clslinkedlst::lstprint()
{
	lstnodes *cur;
	cur = this->headnode;
	cout << "Printing the values within the linked list.\n";
	while (cur != NULL) {
		cout << "Value in Node is:" << cur->val << '\n';
		cur = cur->nextNode;
	};
	delete cur;
	cur = NULL;
	cout << "\n The head value is:" << this->headnode->val
		<< "\n The tail value is:" << this->tailnode->val
		<< "\n The list holds " << this->lstsize << " elements.\n";
};
