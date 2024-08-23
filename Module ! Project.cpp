#include <iostream>

#include <vector>

#include <algorithm>

using namespace std;

int main() {

    int n, t;

    cin >> n;

    vector<pair<int, int>> users(n);

    for (int i = 0; i < n; i++) {

        cin >> users[i].first >> users[i].second;

    }

    cin >> t;

    for (int i = 0; i < t; i++) {

        int from, to, amount;

        cin >> from >> to >> amount;

        for (auto& user : users) {

            if (user.first == from && user.second >= amount) {

                user.second -= amount;

                for (auto& u : users) {

                    if (u.first == to) {

                        u.second += amount;

                    }

                }

                cout << "Success" << endl;

                goto next;

            }

        }

        cout << "Failure" << endl;

        next:;

    }
    cout<<endl;

    sort(users.begin(), users.end(), [](auto& a, auto& b) {

    return a.second < b.second || (a.second == b.second && a.first < b.first);

});

for (const auto& user : users) {

    cout << user.first << " " << user.second << endl;

}

    return 0;

}

