//#include <iostream>
//#include <vector>
//
//std::vector<char> A;
//int A_size;
//std::vector<char> B;
//int B_size;
//std::vector<char> C;
//int C_size;
//
//void init()
//{
//    int i, j;
//    char input = 0;
//    while ((input = getchar()) != '\n') {
//        A.push_back(input - '0');
//    }
//    input = 0;
//    while ((input = getchar()) != '\n') {
//        B.push_back(input - '0');
//    }
//
//    A_size = A.size();
//    B_size = B.size();
//    C_size = A_size;
//
//    for (i = 0;i < A_size;i++) {
//        C.push_back(0);
//    }
//}
//
//void minus(int a, int b, int a_size, int b_size)
//{
//    int i;
//    int remove = 0;
//
//    for (i = 0;i < b_size;i++) {
//        A[a + a_size - i - 1] -= B[b + b_size - i - 1] + remove;
//        if (A[a + a_size - i - 1] < 0) {
//            remove = (A[a + a_size - i - 1] + 20) / 10;
//            A[a + a_size - i - 1] = (A[a + a_size - i - 1] + 10) % 10;
//        }
//        else {
//            remove = 0;
//        }
//    }
//    while (remove != 0) {
//        A[a + a_size - i - 1] -= remove;
//        if (A[a + a_size - i - 1] < 0) {
//            remove = (A[a + a_size - i - 1] + 20) / 10;
//            A[a + a_size - i - 1] = (A[a + a_size - i - 1] + 10) % 10;
//        }
//        else {
//            remove = 0;
//        }
//        i--;
//        if (a + a_size - i - 1 < a) {
//            break;
//        }
//    }
//}
//
//int main()
//{
//    init();
//
//
//    minus(0, 0, 5, 4);
//
//    return 0;
//}

//#include <stdio.h> 
//#include <string.h> 
//char a[100002];
//char b[100002];
//char result[100002] = { 0 };
//int lena = 0, lenb = 0, lenres;
//
//int nolowerthan(char a[], char b[]) {
//    int i;
//
//    if ((a[-1] - '0')) {
//        return 1;
//    }
//
//    for (i = 0; i < lenb; i++) {
//        if (a[i] > b[i]) {
//            return 1;
//        }
//        else if (a[i] < b[i])
//        {
//            return 0;
//        }
//    }
//    return 1;
//}
//
//void minues(char a[], char b[]) {
//    int i;
//    for (i = lenb - 1; i >= 0; i--) {
//        if (a[i] < b[i]) {
//            a[i - 1]--;
//            a[i] = a[i] + 10;
//        }
//        a[i] = a[i] - (b[i] - '0');
//    }
//}
//
//int main() {
//    int i = 1, j;
//    int nlflag;
//    char *add = a;
//    char in;
//    add[0] = '0';
//    while (1) {
//        in = getchar();
//        if (in == '\n') {
//            add[i] = 0;
//            if (!lena) {
//                lena = i;
//                add = b;
//                i = 0;
//            }
//            else {
//                lenb = i;
//                break;
//            }
//        }
//        else {
//            add[i++] = in;
//        }
//    }
//    if (2 <= lena && '0' == a[1]) {
//        printf("0\n");
//    }
//    else {
//        for (i = 0, lenres = 0; i < lena && lena - i >= lenb;) {
//            nlflag = nolowerthan(&a[i + 1], b);
//            if (nlflag) {
//                minues(&a[i + 1], b);
//                result[i] ++;
//            }
//            else {
//                i++;
//                lenres++;
//            }
//        }
//        for (i = 0, nlflag = 0; i < lenres - 1; i++)
//        {
//            if (result[i]) {
//                nlflag = 1;
//            }
//            if (nlflag) {
//                printf("%d", result[i]);
//            }
//        }
//        printf("\n");
//    }
//
//    return 0;
//}

#include <iostream>

class Uint128
{
    const static char cnt = 4;

public:
    unsigned int x[cnt];
    Uint128() {
        int i;
        for (i = 0;i < cnt;i++) {
            this->x[i] = 0;
        }
    }

    void operator=(Uint128 y) {
        int i;
        for (i = 0;i < cnt;i++) {
            this->x[i] = y.x[i];
        }
    }

    void operator=(int y) {
        int i;
        for (i = 0;i < cnt;i++) {
            this->x[i] = y % 0xFFFFFFFF;
            y = y / 0xFFFFFFFF;
        }
    }

    void operator+=(Uint128 y) {
        unsigned long long sum = 0;
        int i;
        for (i = 0;i < cnt;i++) {
            sum = this->x[i] + y.x[i];
            this->x[i] = sum % 0xFFFFFFFF;
            if (i + 1 < cnt) {
                this->x[i + 1] += sum / 0xFFFFFFFF;
            }
        }
    }

    Uint128 operator+(Uint128 y) {
        return y;
    }

    Uint128 operator*(Uint128 y) {
        return y;
    }

    friend std::ostream& operator<<(std::ostream& out, Uint128 x) {
        int i;
        for (i = 0;i < cnt;i++) {
            out << x.x[i];
        }
        return out;
    }
};

int main()
{
    Uint128 x;
    Uint128 y;

    x = 128;
    y = 256;

    std::cout << x + y << std::endl;
}