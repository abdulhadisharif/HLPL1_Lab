#include "st#include "std_lib_facilities.h"


struct Point {
  int x;
  int y;
};

bool operator==(const Point& p1, const Point& p2) {
 return p1.x==p2.x && p1.y==p2.y;
}

bool operator!=(const Point& p1, const Point& p2) {
 return !(p1==p2);
}

istream& operator>>(istream& is, Point& p) {
  int x, y;
  char ch1, ch2, ch3;

  is >> ch1>> x >> ch2 >> y >> ch3;
  if (!is) return is;
  if (ch1 != '(' || ch2 != ',' || ch3 != ')') {
    is.clear(ios_base::failbit);
    return is;
  }

  p = Point{x,y};
  return is;
};

ostream& operator<<(ostream& os, const Point& p) {
  return os << '(' << p.x << ',' << p.y << ')';
};

void print_vector(vector<Point> vector) {
  for (int i =0; i < vector.size(); ++i)
    cout << vector[i] << endl;
}

void compare_vectors(const vector<Point>& vector1, const vector<Point>& vector2) {
  if(vector1.size() != vector2.size()) error("Something's wrong!");
  for(int i=0; i<vector1.size(); ++i) {
    if (vector1[i] != vector2[i]) error("Something's wrong!");
  }
}

int main()
try {
    string ofname, ifname;
    vector<Point> original_points;

  cout << "Enter 7 (x,y) pairs: " << endl;
  for (int i =0; i<7; i++) {
    Point op;
    cin >> op;
    if (!cin) error("Incorrect format.");
    original_points.push_back(op);
  }
  cout << "Original points: "<<endl;
   print_vector(original_points);

   ofname = "Mydata.txt";
   ofstream ofs { ofname };
   if (!ofs) error("Cannot open ofs mydata.txt");
   for (const auto& p : original_points)
    ofs << '(' << p.x << ',' <<p.y << ')' << endl;

    ifname = "Mydata.txt";
    ifstream ifs { ifname };
    if (!ifs) error("Cannot open ifs mydata.txt");
    vector<Point> processed_points;
    Point pp;
    while(ifs >> pp)
      processed_points.push_back(pp);

    cout << "Processed points: "<<endl;
    print_vector(processed_points);

    compare_vectors(original_points, processed_points);

return 0;
} catch(exception& e) {
  cerr << e.what() << endl;
  return 1;
}
