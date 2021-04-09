#include "std_lib_facilities.h"

//version2 - 9.4.2
 namespace Version2 {
 struct Date {
   int y, m, d;
   Date(int y, int m, int d)
     :y(y), m(m), d(d)
    {
      if(y < 0) error("Invalid year!");
       if(m < 0 || m > 12) error("Invalid month!");
        if(d < 0 || d > 31) error("Invalid Day!");

       y = y;
       m = m;
       d = d;
     };

     void add_day(int n) {
     d+=n;
     if(d>31) {
       ++m;
       d -= 31;
      }
      if(m>12)
      { ++y; m-=12;}
      }
    };


    ostream& operator<<(ostream& os, const Date& date) {
     return os << date.y << "."
               << date.m << "."
               << date.d << "\n";
      };
    }

    void version2() {
      using namespace Version2;
      cout << "\nVersion2 - 9.4.2\n";
      Date today {1978, 6, 25};
      cout << "Today: " << today << endl;
      Date tomorrow = today;
      tomorrow.add_day(1);
      cout << "Tomorrow: " << tomorrow << endl;
      Date check {1997, 6, 22};
      check.add_day(5);
      cout << check << endl;
     }

     int main()
     try {
         version2();

   return 0;
 } catch(exception& e){
  cerr << e.what() << endl;
  return 1;
 }
