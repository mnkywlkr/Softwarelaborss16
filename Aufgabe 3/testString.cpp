
#include "String.h"

ostream& operator<< (ostream &out, String &s) {
  for(int i=0; i<s.size; i++) {
    out << s.str[i];
  }

  return out;
}


int main() {
    char test[] = {'a','b','c','\0'};
  String s;
  cout << s << endl;
  String s2("Halllllllloooooo");
  cout << s2<< endl;
  String s3(&test[1]);
  cout << s3 << endl;
  
  s += s2;
  cout << s << endl;
  s2 = s3;
  cout << s2<< endl;
  s2 += s3;

  
  cout << s2<< endl;
  cout << s3 << endl;

}
