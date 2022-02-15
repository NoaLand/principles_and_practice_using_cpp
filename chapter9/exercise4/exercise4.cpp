struct X {
    // this function will never end
    void f(int x) {
        struct Y {
            int f() { return 1; }

            int m;
        };
        // m and x will never use
        int m;
        m = x;
        Y m2;
        return f(m2.f());
    }

    int m;

    void g(int m) {
        if(m)
            f(m + 2);
        else{
            g(m + 2);
        }
    }

    X() {}

    // never used
    void m3() {
    }

    void main() {
        X a;
        a.f(2);
    }
};