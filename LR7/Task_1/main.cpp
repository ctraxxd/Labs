#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> buildSuffixArray(const string &str) {
    int n = str.size();
    vector<int> suffixArray(n), rank(n), tempRank(n);

    for (int i = 0; i < n; ++i) {
        suffixArray[i] = i;
        rank[i] = str[i];
    }

    sort(suffixArray.begin(), suffixArray.end(), [&](int a, int b) {
        return rank[a] < rank[b];
    });

    for (int k = 1; k < n; k *= 2) {
        auto cmp = [&](int a, int b) {
            if (rank[a] != rank[b]) return rank[a] < rank[b];
            int ra = (a + k < n) ? rank[a + k] : -1;
            int rb = (b + k < n) ? rank[b + k] : -1;
            return ra < rb;
        };
        sort(suffixArray.begin(), suffixArray.end(), cmp);

        tempRank[suffixArray[0]] = 0;
        for (int i = 1; i < n; ++i) {
            tempRank[suffixArray[i]] = tempRank[suffixArray[i - 1]];
            if (cmp(suffixArray[i - 1], suffixArray[i])) {
                tempRank[suffixArray[i]]++;
            }
        }
        swap(rank, tempRank);
    }

    return suffixArray;
}

vector<int> buildLCP(const string &str, const vector<int> &suffixArray) {
    int n = str.size();
    vector<int> rank(n), lcp(n);

    for (int i = 0; i < n; ++i) {
        rank[suffixArray[i]] = i;
    }

    int h = 0;
    for (int i = 0; i < n; ++i) {
        if (rank[i] > 0) {
            int j = suffixArray[rank[i] - 1];
            while (i + h < n && j + h < n && str[i + h] == str[j + h]) {
                h++;
            }
            lcp[rank[i]] = h;
            if (h > 0) h--;
        }
    }

    return lcp;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        vector<int> suffixArray = buildSuffixArray(s);
        vector<int> a = buildLCP(s, suffixArray);
        long long ans = 0;
        int n = a.size();
        vector<int> stack_of_min;
        vector<int> pr_l(n, -1); // closest smaller to the left
        vector<int> pr_r(n, n); // closest smaller or equal to the right
        for (int i = 0; i < n; i++) {
            while (!stack_of_min.empty() && a[stack_of_min.back()] >= a[i]) {
                pr_r[stack_of_min.back()] = i;
                stack_of_min.pop_back();
            }
            if (!stack_of_min.empty()) {
                pr_l[i] = stack_of_min.back();
            }
            stack_of_min.push_back(i);
        }
        for(int i = 0; i < n; i++)
            ans += 1LL * (pr_r[i] - i) * (i - pr_l[i]) * a[i];
        cout << ans << '\n';
    }
    return 0;
}
