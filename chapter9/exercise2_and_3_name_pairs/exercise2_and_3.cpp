#include "../lib/std_lib_facilities.h"

#include "name_pairs.h"

int main() {
    vector<string> names{"d", "b", "c", "a"};
    Name_pairs np;
    np.read_names(names);
    np.read_ages();
    cout << np << endl;

    np.sort();
    cout << np << endl;

    keep_window_open();
    return 0;
}