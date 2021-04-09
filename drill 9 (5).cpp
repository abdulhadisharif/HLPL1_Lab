#include "std_lib_facilities.h"

//version5 - 9.7.4

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
     Month operator++(Month& m) {
       m = (m == Month::dec) ? Month::jan : Month(int(m)+1);
        return m;
      };
      Month operator+(Month& m, int n) {
       if(m == Month::dec) {m = Month::jan; --n; }
       return Month(int(m)+n);
      }

      class Date {
      public;
       Date() : y(2001), m(Month::jan), d(1) {}
       Date(int y, Month m, int d)
       : y(y), m(m), d(d)
       {
        if(y < 0) error("Invalid year!");
         if(m < Month::jan || m > Month::dec) error("Invalid month!");
          if(d < 0 || d > 31) error("Invalid day!");
         }
         void add_day(int n);
         void add_month(int n);
         void add_year(int n);
         int day() const {return d; }
         Month month() const {return m; }
         int year() const {return y; }
        private:
        int y;
        Month m;
        int d;
       };

       void Date::add_day(int n) {
       d+=n;
       if(d > 31) {
       ++m;
       d -= 31;
       if (m==Month::jan)
       {++y; }
       }
       if(d>31) error("add_day() results in invalid date!");
      };

      void Date::add_month(int n) {
       while(n>12) {++y; n -=12; }
         if(n==12) {++y; n -=11; }
         m = m + n;
        };

        void Date::add_year(int n) {
         y+=n;
        };

        ostream& operator << (ostream& os, Month m) {
         return os << months[int(m)];
       }
       ostream& operator << (ostream& os. Date& date) {
        return os << date.year() << "."
                  << date.month() << ","
                  << date.day() << "\n";
        }

        }

        void version5() {
        using namespace Version5;
        cout << "\tversion5 - 9.7.4" << endl;
        Date d_default;
        cout << "Default date: " << d_default << endl;
        Date today {1978, Month::jun, 25};
        cout << "Today:" << today << endl;
        cout << "Month: " << today.month() << endl;
        Date tomorrow = today;
        tomorrow.add_day(1);
        cout << "\nTomorrow: " << tomorrow << endl;
        Date next_month = today;
        next_month.add_month(1);
        cout << "Next month: " << next_mouth << endl;
        Date next_year = today;
        next_year.add_year(1);
        cout << "Next year: " << next_year << endl;
        Date check {1997, Month::jan, 22};
        check.add_day(5);
        cout << check << endl;
     }

     int main()
     try {
      version5();

   return 0;
 } catch(exception& e){
    cerr << e.what() << endl;
    return 1;
 }
