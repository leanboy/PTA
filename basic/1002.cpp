#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    int sum = 0;
    string pingying[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
    cin >> s;
    for(int i = 0; i < int(s.size()); i++)
        sum += stoi(s.substr(i, 1));
    string sum_str = to_string(sum);
    for(int i = 0; i < int(sum_str.size()); i++){
        if(i != 0)
            cout << ' ';
        cout << pingying[sum_str[i] - '0'];
    }
    return 0;
}