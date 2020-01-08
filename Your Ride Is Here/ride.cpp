/*
ID: your_id_here
PROG: ride
LANG: C++                
*/
#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    freopen("ride.in", "r", stdin);
    freopen("ride.out", "w", stdout);
    
    char str1[8] = {};
    unsigned long long ans1 = 1;
    
    char str2[8] = {};
    unsigned long long ans2 = 1;

    scanf("%s %s", &str1, &str2);
    
    int i;
    for (i=0; str1[i]!=0; i++) {
    	ans1 *= (str1[i]-'A'+1);
    }
    for (i=0; str2[i]!=0; i++) {
    	ans2 *= (str2[i]-'A'+1);
    }
    
    if (ans1%47 == ans2%47) {
    	printf("GO\n");
    } else {
    	printf("STAY\n");
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}