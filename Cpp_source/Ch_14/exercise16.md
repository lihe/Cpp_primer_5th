```c++
class StrBlob {
    friend bool operator == (const StrBlob &lhs, const StrBlob &rhs);
    friend bool operator != (const StrBlob &lhs, const StrBlob &rhs);
    
};

bool operator == (const StrBlob &lhs, const StrBlob &rhs) {
    return lhs.data ==  rhs.data;
}

bool operator != (const StrBlob &lhs, const StrBlob &rhs) {
    return !(lhs == rhs);
}

class StrBlobPtr {
    friend bool operator == (const StrBlobPtr &lhs, const StrBlobPtr &rhs);
    friend bool operator != (const StrBlobPtr &lhs, cosnt StrBlobPtr &rhs);
};

bool operator == (const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
    auto l = lhs.wptr.lock(), r = rhs.wptr.lock();
    // 两个指针都为空，或指向相同的vector且curr指向相同元素时，相等，否则不等。
    if (l == r) {
        return (!r || lhs.curr == rhs.curr);
    }
    else {
        return false;
    }
}

bool operator != (const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
    return !(lhs == rhs);
}

class StrVec {
    friend bool operator == (const StrVec &lhs, const StrVec &rhs);
    friend bool operator != (const StrVec &lhs, const StrVec &rhs);
};

bool operator == (const StrVec &lhs, const StrVec &rhs) {
    if (lhs.size() != rhs.size()) {
        return false;
    }
    for (auto itr1 = lhs.begin(), itr2 = rhs.begin(); itr1 != lhs.end() && itr2 != rhs.end(); itr1++, itr2++) {
        if (*itr1 != *itr2) {
            return false;
        }
    }
    return true;
}

bool operator != (const StrVec &lhs, const StrVec &rhs) {
    return !(lhs == rhs);
}


class String {
    friend bool operator == (const String &lhs, const String &rhs);
    friend bool operator != (const String &lhs, const String &rhs);
};

bool operator == (const String &lhs, const String &rhs) {
    return strcmp(lhs.str, rhs.str);
}

bool operator != (const String &lhs, const String &rhs) {
    return !(lhs == rhs);
}
```

