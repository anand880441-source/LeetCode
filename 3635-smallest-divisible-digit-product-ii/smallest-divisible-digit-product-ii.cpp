class Solution {
private:

    struct Factors {
        int c2 = 0, c3 = 0, c5 = 0, c7 = 0;
    };

    bool getFactors(long long t, Factors& f) {
        while (t % 2 == 0) { f.c2++; t /= 2; }
        while (t % 3 == 0) { f.c3++; t /= 3; }
        while (t % 5 == 0) { f.c5++; t /= 5; }
        while (t % 7 == 0) { f.c7++; t /= 7; }
        return t == 1;
    }

    int minDigits(Factors f) {
        int count = f.c5 + f.c7;
        int n3 = f.c3 / 2;
        int r3 = f.c3 % 2;
        int n2 = f.c2 / 3;
        int r2 = f.c2 % 3;
        
        count += n3 + n2;
        if (r3 && r2) {
            count += 1; // 2 * 3 = 6
            r2--; r3--;
        }
        if (r3) count += 1;
        if (r2) {

            count += 1; 
        }
        return count;
    }

    string makeSuffix(Factors f, int len) {
        string s = "";
        while (f.c7 > 0) { s += '7'; f.c7--; }
        while (f.c5 > 0) { s += '5'; f.c5--; }
        while (f.c3 >= 2) { s += '9'; f.c3 -= 2; }
        while (f.c2 >= 3) { s += '8'; f.c2 -= 3; }
        
        if (f.c3 == 1 && f.c2 == 1) { s += '6'; f.c3--; f.c2--; }
        else if (f.c3 == 1 && f.c2 == 2) { s += '6'; s += '2'; f.c3--; f.c2 -= 2; } 
        
        if (f.c3 == 1) { s += '3'; f.c3--; }
        if (f.c2 == 2) { s += '4'; f.c2 -= 2; }
        if (f.c2 == 1) { s += '2'; f.c2--; }

        while ((int)s.size() < len) s += '1';
        sort(s.begin(), s.end());
        return s;
    }

    void removeDigitFactors(int d, Factors& f) {
        if (d == 2) f.c2 = max(0, f.c2 - 1);
        if (d == 3) f.c3 = max(0, f.c3 - 1);
        if (d == 4) f.c2 = max(0, f.c2 - 2);
        if (d == 5) f.c5 = max(0, f.c5 - 1);
        if (d == 6) { f.c2 = max(0, f.c2 - 1); f.c3 = max(0, f.c3 - 1); }
        if (d == 7) f.c7 = max(0, f.c7 - 1);
        if (d == 8) f.c2 = max(0, f.c2 - 3);
        if (d == 9) f.c3 = max(0, f.c3 - 2);
    }

public:
    string smallestNumber(string num, long long t) {
        Factors targetF;
        if (!getFactors(t, targetF)) return "-1";

        int n = num.size();
        vector<Factors> pref(n + 1);
        pref[0] = targetF;

        int firstZero = -1;
        for (int i = 0; i < n; i++) {
            if (num[i] == '0') {
                firstZero = i;
                break;
            }
            pref[i + 1] = pref[i];
            removeDigitFactors(num[i] - '0', pref[i + 1]);
        }

        if (firstZero == -1 && minDigits(pref[n]) == 0) {
            return num;
        }

        int limit = (firstZero == -1) ? n - 1 : firstZero;
        for (int i = limit; i >= 0; i--) {
            int remLen = n - 1 - i;
            for (int d = (num[i] - '0') + 1; d <= 9; d++) {
                Factors nextF = pref[i];
                removeDigitFactors(d, nextF);
                if (minDigits(nextF) <= remLen) {
                    string ans = num.substr(0, i) + to_string(d);
                    ans += makeSuffix(nextF, remLen);
                    return ans;
                }
            }
        }

        int newLen = max(n + 1, minDigits(targetF));
        return makeSuffix(targetF, newLen);
    }
};
