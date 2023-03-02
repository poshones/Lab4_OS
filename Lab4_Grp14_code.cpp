#include <iostream>
#include <cmath>
using namespace std;

int mult(int mul_1, int mul_2);
int shft(int s, int n);

int main(){
    int mul_1, mul_2;
    cout << "Enter two integers to multiply!\n";
    cout << "Num1: ";
    cin >> mul_1;
    cout << "Num2: ";
    cin >> mul_2;

    cout << "Product: " << mult(mul_1, mul_2) << endl;

    return 0;
}

int shft(int s, int n){
    int z;
    z = pow(2,n); 
    s *= z;
    return s;
}

int mult(int mul_1, int mul_2){
    int temp = 0, count = mul_2;

    if (mul_2 > 0){
        while (count != 0){
            if (count >= 8){
                temp += shft(mul_1, 3);
                count -= 8;
            } else if(count >= 4){
                temp += shft(mul_1, 2);
                count -= 4;
            } else if(count >= 2){
                temp += shft(mul_1, 1);
                count -= 2;
            } else{
                temp += mul_1;
                count -= 1;
            }
        }  
    } else if (mul_2 < 0) {
        while (count != 0){
            if (count <= -8){
                temp -= shft(mul_1, 3);
                count += 8;
            } else if(count <= -4){
                temp -= shft(mul_1, 2);
                count += 4;
            } else if(count <= -2){
                temp -= shft(mul_1, 1);
                count += 2;
            } else{
                temp -= mul_1;
                count += 1;
            }
        } 
    } else {
        temp = 0;
    }
    return temp;
}