/*
ID: your_id_here
PROG: gift1
LANG: C++                
*/
//Greedy Gift Givers
//https://train.usaco.org/usacoprob2?a=950pAjF03W0&S=gift1
#include <bits/stdc++.h>
using namespace std;

struct PAIR {
    string name;//名字
    int deposit;//钱
};
const int MAXN = 10;
PAIR data[MAXN] = {};

int main() {
    //freopen("gift1.in", "r", stdin);
    //freopen("gift1.out", "w", stdout);

    int np;
    cin >> np;

    for (int i=0; i<np; i++) {
        cin >> data[i].name;
        data[i].deposit = 0;
    }

    string tmp;
    int money, num;
    while (cin >> tmp) {
        cin >> money >> num;
        if (0!=money && 0!=num) {
            int quotient = money / num;//商
            int remainder = money % num;//余数

            //找到位置
            for (int pos=0; pos<np; pos++) {
                if (tmp==data[pos].name) {
                    data[pos].deposit = data[pos].deposit - money + remainder;
                    break;
                }
            }
            for (int j=0; j<num; j++) {
                cin >> tmp;
                for (int pos=0; pos<np; pos++) {
                    if (tmp==data[pos].name) {
                        data[pos].deposit += quotient;
                        break;
                    }
                }
            }
        } else if (0==money && 0!=num) {
            for (int j=0; j<num; j++) {
                cin >> tmp;
            }
        }
    }

    //遍历
    for (int i=0; i<np; i++) {
        cout << data[i].name << " " << data[i].deposit << endl;
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}