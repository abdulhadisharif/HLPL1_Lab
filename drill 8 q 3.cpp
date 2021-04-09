#include "std_lib_facilities.h"
using namespace std;
namespace X
{
 int var;
 void print()
 {
    cout<<"Namespace X var:"
<<var<<endl<<endl;
 }
}
namespace Y
{
  int var;
  void print()
  {
     cout<<"Namespace Y var:"
<<var<<endl<<endl;
  }
}
namespace Z
{
  int var;
  void print()
  {
    cout<<"Namespace Z var:"
<<var<<endl<<endl;
  }
}
int main()
{
 X::var=7;
 X::print();
 using namespace Y;
 var=9;
 print();
 {
    using Z::var;
    using Z::print;
    var=11;
    print();
 }
 print();
 X::print();
 return 1;
}

