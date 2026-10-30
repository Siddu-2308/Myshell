#include <iostream>
#include <string>
using namespace std;

int main() {

  string command; //what you entered will be stored here.

  while (true) {
    cout << "MyShell> ";

    if (!getline(cin, command)) {
      break; //getline failed
    }
    else{
        if (command == "exit") {
            break;
        }
        if (command.empty()) {
            continue;
        }
    }
    //cout << "You entered: " << command << '\n';
  }

  return 0;
}
