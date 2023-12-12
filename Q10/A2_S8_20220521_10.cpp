// File: A2_S8_20220521_10.cpp
// Purpose: Solving Problem no. 10
// Author: بيجاد عبد الغفار عبد الهادي محمود
// Section: S8
// ID: 20220521
// TA: Khaled Ahmed
// Date: 26 Oct 2023
#include <bits/stdc++.h>


int main() {
    std::ifstream fin("A2_S8_20220521_10_in.txt");
    std::ofstream fout("A2_S8_20220521_10_out.txt");
    std::string s;
    std::map<std::string, std::string> cipher{
            {u8"ارهاب", u8"ا.ر.ه.ا.ب"},
            {u8"موت", u8"مـ.ـو.،ت"},
            {u8"قتل", u8"قـ.ـتـ.ـل"},
            {u8"قتيل", u8"ق.ت.ي.ل"},
            {u8"فلسطين", u8"ف.ل.س.ط.ي.ن"},
    };
    while (getline(fin, s)) {
        std::istringstream line(s);
        while (line >> s) {
            for (const auto &[a, b]: cipher) {
                size_t ind = s.find(a);
                if (ind != std::string::npos)
                    s.replace(ind, a.size(), b);
            }
            fout << s << " ";
        }
        fout << std::endl;
    }
    fin.close();
    fout.close();
}