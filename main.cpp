#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

using Interval = pair<int, int>;

bool cmp(const Interval &a, const Interval &b) {
    return a.second < b.second;
}

int main(){

}