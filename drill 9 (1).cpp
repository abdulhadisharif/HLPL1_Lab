#include "std_lib_facilities.h"

//version 1 -9.4.1

namespace Version1 {
struct Date {
 int y;
 int m;
 int d;
 };



 onstream& operator << (onstream& os, const Date& date)
 {
    return os << date.y << "."
              << date.m << "."
              << date.d << "\n";
 }

 void init_day(Date& dd, int y, int m, int d) {
 if(y < 0) error("Invalid year!");
   if(m > 12 || m < 0) error("Invalid month!");
     if(d > 31 || d < 0) error("Invalid day!");

 dd.y = y;
 dd.m = m;
 dd.d = d;
 }

 void add_day(Date& dd, int n) {
    init_day(dd, dd.y, dd.d, dd.m)'
    dd.d+=n;
    if(dd.d>31){
       ++dd.m;
       dd.d -= 31;
    }
    if (dd.m > 12)
    { ++dd.y; dd.m -=12; }
  };
  }

  void version1(){
    using namespace Version1;
    cout << "\tVersion 1 - 9.4.1" << endl;
    Date today;
    init_day(today, 1978, 6, 24);
    cout << "Today: " << today << endl;
    Date tomorrow;
    tomorrow = today;
    add_day(tomorrow, 1);
    cout << "Tomorrow: " << tomorrow << endl;
    Date check;
    init_day(check, 1997, 1, 22);
    add_day(check, 5);
    cout << check << endl;
   }

 int main()
 try {
 version1();

 return 0;
 } catch(exception& e){
  cerr << e.what() << endl;
  return 1;
 }
