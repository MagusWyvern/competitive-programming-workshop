#include <iostream>

using namespace std;

/*
 * This code reverses the digits in an integer.
 * For example, rev(123) returns 321, and rev(100) returns 1.
 */

int rev (int a)
{
   int r = 0;
   while ( a != 0 )
   {
      r = r * 10 + ( a % 10 );
      a /= 10;
   }
   return r;
}


int main (void)
{
   int prob, probn;
   cin >> probn;
   for ( prob = 0;  prob < probn;  ++prob )
   {
      int a, b;
      cin >> a >> b;
      cout << rev (rev(a) + rev(b)) << endl;
   }
   return 0;
}