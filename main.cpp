#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int INF = 20000000;

int calc(int);

int main(){
    int N, A, B;
    cin >> N;
    cin >> A;
    cin >> B;
    int counter = 0;

    for (int i = 1; i <= N; i++){
        int tmp = calc(i);

        if (tmp >= A && tmp <= B) counter += i;
    }

    cout << counter << endl;
}

int calc(int a){
    int sum = 0;
    while (a > 0){
        sum += a % 10;
        a = a / 10;
    }
    return sum;
}
