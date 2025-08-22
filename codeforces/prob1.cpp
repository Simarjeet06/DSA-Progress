#include <iostream>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n;
        string a;
        cin >> a;

        cin >> m;
        string b, c;
        cin >> b >> c;

        for (int i = 0; i < m; i++) {
            if (c[i] == 'V') {
                a.insert(a.begin(), b[i]);  // Vlad adds at front
            } else {
                a.push_back(b[i]);          // Dima adds at back
            }
        }

        cout << a << endl;
    }

    return 0;
}



