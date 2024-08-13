// - CMDLINE/TERMINAL PROGRESSBAR, INSTANCE OWNER: *****, LICENSEHOLDER: JAVAKOTLINUSER@GMAIL.COM, LICENSE: MIT - //
// - Try setting doEndless to true, you wont regret it! - //
#include <iostream>
#include <string>
#include <chrono>
#include <thread>

using std::string, std::cout;
int main() {

    int reiterations = 0; // - Reiteration start value, dont change unless you want to start at a certain percent. Default = 0; - //

    // - CONSTANTS - //
    const int totaliterations = 100; // - Reiterations total, totaliterations/100. Default = 100; - //
    const int pgbarwidth = 20; // - Width of progressbar in hashtags. Default = 20; - //
    const int millisecs = 100; // - Progressbar speed, 1 hashtag per ? millisecs. Default = 100; - //

    // - ANSI COLORS - //
    string CLR_COMPL = "\u001B[32m"; // - Progressbar completed color. Default: Green = "\u001B[32m"; //
    string CLR_NOTCOMPL = "\u001B[37m"; // - Progressbar non-completed color. Default: White = "\u001B[37m"; - //
    string RESET = "\u001B[0m"; // - Reset value, dont change - //

    // - ADVANCED - //
    bool doInitlMsg = true; // - If message that states purpose of progressbar is on. Default = true; - //
    string initMsg = "Progress: "; // - Message that states purpose of progressbar. Default = "Progress: "; - //
    bool doEndMsg = true; // - If message that ends progressbar is on. Default = true; - //
    string endMsg = "Task Completed"; // - Message that ends progressbar. Default = "Task Completed"; - //
    bool doProgressbar = true; // - Enables progressbar. Default = true; - //
    bool doPercent = true; // - Enables percentage. Default = true; - //
    bool doEndless = false; // - Decides whether the progressbar does or does not continue. Default = false; - //

    // - MAGIC - //
    while (true) {
      int percentage = (reiterations * 100) / totaliterations; // - Math Systems - //
      int hashnumber = (percentage * pgbarwidth) / 100; // - Math Systems - //
      reiterations++; // - While Loop Execution System - //

      if (doInitlMsg == true) cout << "\r" << initMsg; // - Initial Message System - //
      if (doProgressbar == true) { // - Progressbar System - //
          cout << "(" << CLR_COMPL; for (int i = 0; i < hashnumber; ++i) { cout << "#"; } cout << CLR_NOTCOMPL;
          for (int i = hashnumber; i < pgbarwidth; ++i) {cout << "#";} cout << RESET << ")" << " "; }
      if (doPercent == true) cout << percentage << "%"; // - Percent System - //
        
      std::this_thread::sleep_for(std::chrono::milliseconds(millisecs)); // - Load Time System - //
      if (doEndless == false) { if (reiterations >= totaliterations + 1) break;} // - Progressbar Continuation Systems - //
      else if (doEndless == true) if (hashnumber >= 100) break; // - Progressbar Continuation Systems - //
    }
  if (doEndMsg == true) cout << "\n" << endMsg << "\n"; // - End Message System - //
  return 0;
}