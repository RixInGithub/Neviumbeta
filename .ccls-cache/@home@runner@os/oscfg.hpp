#include <stdlib.h>
#include <iostream>
#include <string>
#include <fstream>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

using namespace std;
using std::string;
string isOwner = getenv("isOwner");
string cmd = "";
char answer1 = '?';
char answer2 = '?';
string version = "0.0.0Beta";
string fullname = "Nevium Beta";
string pcname = "Nevium Beta";
string codename = "unknown";
string cmdargs = "?";

void start() {
  cout << "\x1B[0m\x1B[44m";
  cout << pcname << "\x1B[0m\n";
}

void forevercode() {
  while (true) {
    cout << "\033[0;32m" << ") [";
    std::getline(std::cin, cmd);
    cmd = "[" + cmd;
    bool cmdContainsDisplay = (cmd.find("[display=") != string::npos) && (cmd.find("]") != string::npos);
    bool cmdContainsNecmd = (cmd.find("[necmd=") != string::npos) && (cmd.find("]") != string::npos);
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
    } else if (cmd == "[about]") {
      cout << "Version: " << version << ";\n";
      cout << "Full Name: " << fullname << ";\n";
      cout << "Codenamed As: " << codename << "\n";
    } else if (cmd == "[exit]") {
      system("clear");
      return 0;
    } else if (cmd == "[pcexit]") {
      system("clear");
      return 0;
    }/* else if ((cmd.find("[rename=") != string::npos) && (cmd.find("]") != string::npos)) {
      string::size_type pos = 0;
      cmdargs = cmd;
      cmdargs.replace("[rename=", 1, "");
      cmdargs.replace("]", cmdargs.length(), "");
      cout << "Are you sure you want to rename \"" << pcname << "\" to \"" << cmdargs << "\"? [y/n] ";
      cin >> answer2;
      if (answer2 == 'y') {
        pcname = cmdargs;
        cout << "Successfully renamed PC to \"" << pcname << "\".";
      } else if (answer2 == 'n') {
        cout << "";
      } else {
        cout << "\nCan't compare answer. Please try again later.\n";
      }
    }*/ else if (cmd == "[login]") {
      // Later...
    } else if (cmdContainsDisplay == true) {
      cmdargs = cmd;
      int pos1 = cmdargs.find("=");
      cmdargs = cmdargs.substr(pos1 + 1);
      cmdargs = cmdargs.substr(0, (cmdargs.size() - 1));
      std::cout << "\x1B[0m" << cmdargs;
    } else if (cmdContainsNecmd == true) {
      cmdargs = cmd;
      int pos1 = cmdargs.find("=");
      cmdargs = cmdargs.substr(pos1 + 1);
      cmdargs = cmdargs.substr(0, (cmdargs.size() - 1));
      system("cd nevium_drive");
      ifstream appF;
      appF.open(cmdargs, ios::in);
      string appContent;
      system("cd ..");
    } else {
      cout << "No command \"" << cmd << "\" found.\n\n";
    }
  }
}
