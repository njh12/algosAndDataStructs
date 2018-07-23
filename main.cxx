#include <iostream>
#include "clslinkedlst.hxx"

using namespace std;


int main()
{

	clslinkedlst linkedlst;

	//for (int x = 0; x < 6; x++) {
	//	linkedlst.insertEnd(x);
	//};
	//linkedlst.lstprint();
	//linkedlst.delval(2);
	//linkedlst.delval(0);
	//linkedlst.lstprint();
	linkedlst.insValByPos(5);
	linkedlst.insValByPos(4);
	linkedlst.insValByPos(6);
	linkedlst.insValByPos(8);
	linkedlst.insValByPos(7);
	linkedlst.lstprint();
	linkedlst.insValByPos(50);
	linkedlst.insValByPos(2);
	/*linkedlst.delval(50);
	linkedlst.delval(5);
	linkedlst.delval(1);*/
	linkedlst.lstprint();
	linkedlst.insValByPos(3);
	linkedlst.insValByPos(10);
	linkedlst.insValByPos(51);
	linkedlst.insValByPos(1);
	linkedlst.insValByPos(9);
	linkedlst.insValByPos(100);
	linkedlst.insValByPos(0);
	linkedlst.lstprint();
	linkedlst.delval(100);
	linkedlst.delval(9);
	linkedlst.lstprint();


	cout << "this is a test\n";
	return 0;
};
