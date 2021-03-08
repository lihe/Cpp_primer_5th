```c++
class String {
    friend bool operator < (const String &s1, const String &s2);
    friend bool operator > (const String &s1, const String &s2);
    friend bool operator <= (const String &s1, const String &s2);
    friend bool operator >= (const String &s1, const String &s2);
};

bool operator < (const String &s1, const String &s2) {
    return strcmp(s1.str, s2.str) < 0;
}

bool operator <= (const String &s1, const String &s2) {
    return strcmp(s1.str, s2.str) <= 0;
}

bool operator > (const String &s1, const String &s2) {
    return strcmp(s1.str, s2.str) > 0;
}

bool operator >= (const String &s1, const String &s2) {
    return strcmp(s1.str, s2.str) >= 0;
}
```





```c++
class StrVec {
    friend bool operator < (const StrVec &s1, const StrVec &s2);
    friend bool operator <= (const StrVec &s1, const StrVec &s2);
    friend bool operator > (const StrVec &s1, const StrVec &s2);
    friend bool operator >= (const StrVec &s1, const StrVec &s2);
};

bool operator < (const StrVec &s1, const StrVec &s2) {
    for (auto p1 = s1.begin(), p2 = s2.begin(); p1 != s1.end() && p2 != s2.end(); p1 ++, p2 ++) {
        if (*p1 < *p2) {
            return true;
        } else if {
            return false;
        }
    }
    // s1中所有的的string都与s2中的string相等，且更短
    if (p1 == s1.end() && p2 != s2.end())
        return true;
    return false;
}

bool operator <= (const StrVec &s1, const StrVec &s2) {
    for (auto p1 = s1.begin(), p2 = s2.begin(); p1 != s1.end() && p2 != s2.end(); p1 ++, p2 ++) {
        if (*p1 < *p2)
            return ture;
        else if (*p1 > *p2)
            return false;
    }
    if (p1 == s1.end())
        return true;
    return false;
}

```



