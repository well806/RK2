#include <iostream>
#include <bitset>
#include <string>
using namespace std;

int main() {
    string A_str = "101101";
    string B_str = "110011";


    int A = stoi(A_str, nullptr, 2); 
    int B = stoi(B_str, nullptr, 2);  

    
    int and_res = A & B;

    int sum = A + B;

 
    cout << "A (d): " << A << ", A (b): " << bitset<6>(A) << endl;
    cout << "B (d): " << B << ", B (b): " << bitset<6>(B) << endl;

    cout << "AND result: " << bitset<6>(and_res) << " (b), " << and_res << " (d)" << endl;
    cout << "Sum result: " << bitset<7>(sum) << " (b), " << sum << " (d)" << endl;

    return 0;
}
