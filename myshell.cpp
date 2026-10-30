#include <bits/stdc++.h>
using namespace std;
// convert sectence into word
//like "ls -l" to {"ls","-l"}
// https://www.geeksforgeeks.org/cpp/stringstream-c-applications/
vector<string> parseCommand(string command) {
  vector<string> args;
  string word;

  stringstream ss(command);

  while (ss >> word) {
    args.push_back(word);
  }

  return args;
}

int main() {
  string command; // what you entered will be stored here.

  while (true) {
    cout << "MyShell> ";

    if (!getline(cin, command)) {
      break; // getline failed
    } else {
      // we also need to deal with spaces here will focus on it later
      if (command == "exit") {
        break;
      }
      if (command.empty()) {
        continue;
      }
    }
    // cout << "You entered: " << command << '\n';
    vector<string> args = parseCommand(command);
  }

  return 0;
}
