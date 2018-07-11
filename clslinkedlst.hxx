struct lstnodes{
	int val;
	lstnodes *nextNode;
};

/*Singularly linked list class utilizing a head and a tail.*/

class clslinkedlst{

private:
	lstnodes *headnode;
	lstnodes *tailnode;
	int lstsize;
	
public:
	
	lstnodes* newNode(int inval);
	void insertEnd(int inval);
	void insValByPos(int inval);
	void lstprint();
	void delval(int inval);
	void setTail();
	clslinkedlst();
	~clslinkedlst();
};




