#include <cstdlib>
#include <iostream>

int fib (int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return (fib(n-2) + fib(n-1));
    }
}

int main () {
    int n = 0;
    cout << "informe um valor inteiro maior ou igual a 0:";
    cin >> n;

    if (n < 0) {
        cout << "invalido.";
    }

    fib(n);
}