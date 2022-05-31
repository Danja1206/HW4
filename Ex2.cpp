#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
    ex2();
}

void ex2()
{
    vector<int> vct = { 1,2,3,4,5,6,7,8,9,1,2,66,8,6,4,2 };
    set<int> st(vct.begin(), vct.end());
    cout << st.size();
}

