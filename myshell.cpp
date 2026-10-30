#include <bits/stdc++.h>
#include <sys/types.h>
#include <sys/wait.h>  //waitpid
#include <unistd.h> //fork,execvp
using namespace std;

// convert sectence into word
// like "ls -l" to {"ls","-l"}
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

void cmdexec(vector<string> &args) {
    // Convert vector<string> into char* array
    vector<char*> argv;
    for (string &arg : args) {
        argv.push_back(arg.data()); //arg.data points to char of strings ...as argv needs that we do it
    }
    argv.push_back(nullptr);

    // Create child process
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        return;
    }

    if (pid == 0) {
        // Child process
        execvp(argv[0], argv.data());
        // if execvp fails
        perror("execvp failed");
        exit(1);
    }

    else {

        // Parent process
        if (waitpid(pid, nullptr, 0) == -1) {
            perror("waitpid failed");
        }
    }
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
    vector<string> args = parseCommand(command); // parsing
    cmdexec(args);                               // execution
  }

  return 0;
}
