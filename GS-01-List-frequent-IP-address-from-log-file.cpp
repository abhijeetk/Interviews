#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <sstream>
using namespace std;

string findTopIPAddresses(vector<string> logFiles) {
    unordered_map<string, int> m;
    for (string s : logFiles) {
        istringstream iss(s);
        string ipAddress;
        while (iss) {
            iss >> ipAddress;
            break;
        }

        auto found = m.find(ipAddress);
        if (found != m.end()) {
            // found
            found->second = found->second + 1;
        }
        else {
            // no found
            m.insert(make_pair(ipAddress, 1));
        }
    }

    int max = 0;
    string res;
    for (auto i : m) {
        if (i.second > max) {
            max = i.second;
            res = i.first;
        }
    }

    return res;
}

int main() {
    vector<string> log = {
        "127.0.0.1 - frank [10/Oct/2000:13:55:36 -0700] \"GET / apache_pb.gif HTTP / 1.0\"",
        "128.1.0.1 - frank [10/Oct/2000:13:55:36 -0700] \"GET / apache_pb.gif HTTP / 1.0\"",
        "127.0.0.2 - frank [10/Oct/2000:13:55:36 -0700] \"GET / apache_pb.gif HTTP / 1.0\"",
        "128.1.0.1 - frank [10/Oct/2000:13:55:36 -0700] \"GET / apache_pb.gif HTTP / 1.0\""
    };
    std::cout << findTopIPAddresses(log) << endl;
}