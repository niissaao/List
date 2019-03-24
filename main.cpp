#include "Nod.h"
#include "List.h"
using namespace std;
int main() {
	List l(4), l2(4, 3), l3;
	cout << "l = " << l << endl << "l2 = " << l2 << endl;
	l2.insertAt(2, 2);
	cout << "l2 = " << l2 << endl;
	l2.insertAt(4, 4);
	cout << "l2 = " << l2 << endl;
	l2.insert(10);
	cout << "l2 = " << l2 << endl;
    cout << "l2 inversat = " << l2.reverse();
	l2.remove(4);
	cout << "l2 = " << l2 << endl;
    cout << "l2[1] = " << l2[1] << endl;
  	cout << "Suma elementelor din l2 este " << l2.sum() << endl;
    l2 = l2 * 2;
    cout << "l2 = " << l2 << endl;
    l3 = l2;
    cout << "l3 = " << l3 << endl;
    cout << "Lungimea lui l2 este " << l2.length() << endl;
    cout << "Minimul din l2 este " << l2.min() << " si maximul este " << l2.max() << endl;
	return 0;
}
