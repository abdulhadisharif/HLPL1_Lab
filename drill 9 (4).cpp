#include "std_lib_facilities.h"

//version4 - 9.7.1
namespace Version4 {

   vector<string> months {
   "January",
   "February",
   "March",
   "April",
   "May",
   "June",
   "July",
   "August",
   "September",
   "October",
   "November",
   "December"
   };

   enum class Month {
     jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
     };
     month operator++(Month& m) {
       m = (m == Month::dec) ? Month::jan : Month(int(m)+1);
        return m;
       }

       class Date {
       public;
        Date(int y, month m, int d)
        : y(y), m(m), d(d)
        {
         if(y < 0) error("Invalid year!");
          if(m < Month::jan || m > Month::dec) error("Invalid month!");
           if(d < 0 || d > 31) error("Invalid day!");
        }

        void add_day(int n) {
        d+=n;
        if(d>31) {
        ++m;
        d -= 31;
        if (m==Month::jan)
        { ++y; }
     }
     };
     int day() const {return d; }
     Month month() const {return m; }
     int year() const {return y; }
    private:
     int y;
     Month m;
     int d;
   };

   ostream& operator << (ostream& os, Month m) {
     return os << months[int(m)];
    }
    ostream& operator << (ostream& os, Date& date) {
     return os << date.year() << "."
               << date.month() << ","
               << date.day() << "\n";
      }

      }

      void version4() {
       using namespace version4;
       cout << "\tVersion4 - 9.7.1" << endl;
       Date today {1978, Month::jun, 25};
       cout << "Today: " << today << endl;
       cout << "Month: " << today.month() << endl;
       Date tomorrow = today;
       tomorrow.add_day(1);
       cout << "\nTomorrow: " << tomorrow << endl;
       Date check {1997, Month::jan, 22};
       check.add_day(5);
       cout << check << endl;
      }

      int main()
    try {
    version4();

 return 0;
 } catch(exception& e){
  cerr << e.what() << endl;
  return 1;
 }
