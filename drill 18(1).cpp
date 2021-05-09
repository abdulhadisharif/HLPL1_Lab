#include "std_lib_facilities.h"

const int sz_ga = 10;

int ga[sz_ga];

void g()
{
  for(int i = 0; i<10; ++i)
  ga[i] = pow(2,i);
}

void print_array(int a[], int sz)
{
  for(int i = 0; i<sz; ++i)
    cout << a[i] << ' ';
  cout << endl;
}

int f(int arg_arr[], int size)
{

int la[10];

for(int i = 0; i<10; ++i)
  la[i] = ga[i];

print_array(la, 10);

int* p = new int[size];

for(int i = 0; i<10; ++i)
  p[i] = arg_arr[i];

print_array(p,10);

delete[] p;
}

int main()
{
g();

f(ga,sz_ga);

int aa[10];
aa[0] = 1;
for (int i = 1; i<10; ++i) {
  aa[i] = aa[i-1] * (i+1);
}

f(aa,10);

return 0;
}
