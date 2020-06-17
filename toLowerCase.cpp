#include <iostream>
#include <string>

using namespace std;

string toLowerCase(string str) {
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] >= 65 && str[i] <= 95) str[i] = char(str[i] + 32);
    }
    cout << str << endl;
    return str;
}

int main() {
    toLowerCase("LOVE");
    toLowerCase("name");
    toLowerCase("Hello");
    toLowerCase("ZzzZ");
    toLowerCase("aAAa");
    return 0;
}