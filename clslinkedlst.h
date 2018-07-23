#pragma once

struct lstnodes {
	int val;
	lstnodes *nextNode;
};


class clslinkedlst
{

private:
	lstnodes * headnode;
	lstnodes *tailnode;
	int lstsize;

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

