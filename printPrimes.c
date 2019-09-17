    //given positive integers n,m, find prime numbers between given interval n, m
    
#include <stdio.h>
#include <stdbool.h>

bool isPrime(int x) {
    if (x == 1) {
        return false;
    } else {
        for (int i = 2; i < x; i++) {
            if (x % i == 0) {
                return false;
            }
        }
    }
    return true;
}   

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
        
    for (int i = n; i <= m; i++) {
        if(isPrime(i)) {
            printf("%d ", i);
        }
    }
    return 0;
}   