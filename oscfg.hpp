#include <stdlib.h>
#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include <unistd.h>
#include <stdio.h>
using namespace std;
string isOwner = getenv("isOwner");
string cmd = "";
char answer1 = '?';
string version = "0.0.0Beta";

void start() {
  cout << "\x1B[0m\x1B[44m";
  // system("Color 17");
  cout << "Nevium Beta\x1B[0m\n";
}

void forevercode() {
  cout << "\033[0;32m" << ") ";
  cin >> cmd;
  if (cmd == "[migrate]") {
    if (isOwner == "1") {
      cout << "Are you sure? [y/n] ";
      cin >> answer1;
      if (answer1 == 'y') {
        cout << "No new updates\n\n";
      } else if (answer1 == 'n') {
        cout << "\n"; // Do nothing
      } else {
        cout << "\nCan't compare answer. Please try again later.\n";
      }
    } else if (isOwner != "true") {
      cout << "\nCan't migrate, not the owner.\n";
    }
  } else if (cmd == "[ver]") {
    cout << "Version: " << version << "\n";
  } else if (cmd == "[cls]") {
    system("clear");
    main()
  } else {
    cout << "No command found.\n\n";
  }
}
