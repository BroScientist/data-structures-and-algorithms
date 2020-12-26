class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int a1, a2, b1, b2;
        sscanf(a.c_str(), "%d+%di", &a1, &b1);
        sscanf(b.c_str(), "%d+%di", &a2, &b2);

        int re = a1 * a2 + (b1 * b2) * (-1);
        int im = a1 * b2 + a2 * b1;
        
        return to_string(re) + "+" + to_string(im) + "i";
    }
};