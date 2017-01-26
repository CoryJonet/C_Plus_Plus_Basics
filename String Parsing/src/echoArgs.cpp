#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    cout << "Echoing command line arguments (one per line):" << endl;
    for (int i = 0; i < argc; i++)
        cout << argv[i] << endl;
    return 0;
}
