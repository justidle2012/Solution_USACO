/*
ID: your_id_here
PROG: friday
LANG: C++                
*/
//Friday the Thirteenth
//https://train.usaco.org/usacoprob2?a=DzhbErzzOh0&S=friday
/*统计每月13号是星期几*/
#include <bits/stdc++.h>
using namespace std;

//闰年判断
bool leapYear(int n) {
    if ((0==n%4 && 0!=n%100) || (0==n%400)) {
        return true;
    } else {
        return false;
    }
}

int main() {
    freopen("friday.in", "r", stdin);
    freopen("friday.out", "w", stdout);

    //读入n
    int n;
    cin >> n;

    //1900年1月1日（星期一）统计到1900+N-1年12月31日。
    //1900年1月13日为12天，12%7=5，为星期六
    //1 2 3 4 5 6 7
    //8 9 10 11 12 13
    //星期统计，从星期六开始
    const int days[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};//每月有几天
    int ans[7] = {};
    int gap = 12;//从1900年1月1日开始
    for (int i=0; i<n; i++) {
        //年
        for (int j=1; j<=12; j++) {
            //月
            //计算到上月13日，差几天
            gap += days[j-1];
            if (3==j && true==leapYear(1900+i)) {
                //闰年2月多一天
                gap++;
            }
            ans[gap%7]++;
        }
        gap += 31;
    }

    //输出
    cout << ans[5] << " " << ans[6];
    for (int i=0; i<5; i++) {
        cout << " " << ans[i];
    }
    cout << endl;

    fclose(stdin);
    fclose(stdout);

    return 0;
}