// - CMDLINE/TERMINAL PROGRESSBAR, INSTANCE OWNER: *****, LICENSEHOLDER: JAVAKOTLINUSER@GMAIL.COM, LICENSE: MIT - //
#include <iostream>
#include <string>
#include <chrono>
#include <thread>

using std::string, std::cout;

int main() {
  
    int reiterations = 0;
    const int totaliterations = 100;
    const int pgbarwidth = 20;
    const int millisecs = 100;

    string CLR_COMPL = "\u001B[32m";
    string CLR_NOTCOMPL = "\u001B[37m";
    string RESET = "\u001B[0m";

    bool doInitlMsg = true;
    string initMsg = "Progress: "; 
    bool doEndMsg = true;
    string endMsg = "Task Completed";
    bool doProgressbar = true;
    bool doPercent = true;
    bool doEndless = false;

    while (true) {
      int percentage = (reiterations * 100) / totaliterations;
      int hashnumber = (percentage * pgbarwidth) / 100;
      reiterations++;

      if (doInitlMsg == true) cout << "\r" << initMsg;
      if (doProgressbar == true) {
          cout << "(" << CLR_COMPL; for (int i = 0; i < hashnumber; ++i) { cout << "#"; } cout << CLR_NOTCOMPL;
          for (int i = hashnumber; i < pgbarwidth; ++i) {cout << "#";} cout << RESET << ")" << " "; }
      if (doPercent == true) cout << percentage << "%";
        
      std::this_thread::sleep_for(std::chrono::milliseconds(millisecs));
      if (doEndless == false) { if (reiterations >= totaliterations + 1) break;}
      else if (doEndless == true) if (hashnumber >= 100) break;
    }
  if (doEndMsg == true) cout << "\n" << endMsg << "\n";
  return 0;
}
