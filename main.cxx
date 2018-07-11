#include "clslinkedlst.hxx"
using namespace std;

int main()
{
  clslinkedlst linkedlst; 
  
  for(int x = 0; x < 30; x++){
	  linkedlst.insertEnd(x);
  };
  linkedlst.lstprint();
  linkedlst.delval(3);
  linkedlst.delval(29);
  linkedlst.delval(17);
  linkedlst.lstprint();
  linkedlst.insValByPos(17);
  linkedlst.lstprint();
  linkedlst.insValByPos(3);
  linkedlst.lstprint();
  linkedlst.insValByPos(30);
  linkedlst.lstprint();
  
  clslinkedlst linkedlst2;
  linkedlst2.insertEnd(999);
  linkedlst2.lstprint();

  return 0;
}

