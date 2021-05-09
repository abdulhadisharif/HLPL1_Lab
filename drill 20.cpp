#include "std_lib_facilities.h"

vector<int> gv;

void gv_init()
{
  for(int i = 0; i < 10; ++i)
    gv.push_back(pow(2,i));
}

void print_vector(vector<int> v)
{
  for(int i = 0; i<v.size(); ++i)
    cout << v[i] << ' ';
  cout << endl;
}

int f(vector<int> arg_vec)
{

vector<int> lv(arg_vec.size());

lv = gv;

print_vector(lv);

vector<int> lv2;

lv2 = arg_vec;

print_vector(lv2);
}

int main()
{
gv_init();

f(gv);

vector<int> vv;

vv.push_back(1);
for(int i = 1; i < 10; ++i)
  vv.push_back(vv[i-1] * (i+1));

f(vv);

return 0;
}
