#include "std_lib_facilities.h"

//version3 - 9.4.3
  namespace Version3 {
  class Date {
    int y, m, d;
  public:
    Date(int y, int m, int d)
       :y(y), m(m), d(d)
      {
       if(y < 0) error("Invalid year!");
        if(m < 0 || m > 12) error("Invalid month!");
         if(d < 0 || d > 31) error("Invalid day!");
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
       {++y; m-=12; }
       };

       int month() {return m;}
       int day() {return d; }
       int year() {return y; }
     };


     ostream& operator << (ostream& os, Date& date) {
       return os << date.year() << "."
                 << date.month() << "."
                 << date.day() << "\n";
       };
       }

       void version3(){
        using namespace Version3;
        cout << "\tVersion3 - 9.4.3\n";
        Date today {1978, 6, 25};
        cout << "Today: " << today << endl;
        cout << "Month: " << today.month() << endl;
        Date tomorrow = today;
        tomorrow.add_day(1);
        cout << "Tomorrow: " << tomorrow << endl;
        Date check {1997, 6, 22};
        check.add_day(5);
        cout << check << endl;
 }

      int main()
      try {
        version3();

   return 0;
 } catch(exception& e){
  cerr << e.what() << endl;
  return 1;
 }
