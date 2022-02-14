#ifndef PRINCIPLES_AND_PRACTICE_USING_CPP_NAME_PAIRS_H
#define PRINCIPLES_AND_PRACTICE_USING_CPP_NAME_PAIRS_H
#include<string>
#include<vector>

using namespace std;

class Name_pairs {
public:

    void read_names(const vector<string>& n);
    void read_ages();
    void sort();

    vector<string> get_names() const { return names; }
    vector<double> get_ages() const { return ages; }
private:
    vector<string> names;
    vector<double> ages;

    static void swap(double& a, double& b);

    inline static bool should_not_swap_twice(const int &index1, const int &index2);
};

std::ostream& operator<<(std::ostream& os, const Name_pairs& np);
#endif //PRINCIPLES_AND_PRACTICE_USING_CPP_NAME_PAIRS_H
