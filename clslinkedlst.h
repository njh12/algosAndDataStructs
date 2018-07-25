#pragma once

struct lstnodes {
	int int_val;
	lstnodes *ptr_nextNode;
};


class clslinkedlst
{

private:
	lstnodes * ptr_headnode;
	lstnodes *ptr_tailnode;
	int int_lstsize;

public:
	clslinkedlst();
	~clslinkedlst();
	lstnodes* newNode(int inval);
	void insertEnd(int inval);
	void insValByPos(int inval);
	void lstprint();
	void delval(int inval);
	void setTail();
};

