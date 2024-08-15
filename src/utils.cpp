// utility functions that are useful
#include <iostream>
#include <map>
#include <string>

#include <vector>
#include <math.h>
#include <numeric>
#include <algorithm>
#include <iterator> 
#include <iomanip>	
#include <filesystem>
#include "utils.h"

using namespace std;
using namespace std::filesystem; 






// Define color codes
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string RESET = "\033[34m";
const string BLACK = "\033[30m";
const string YELLOW = "\033[33m";
const string BLUE = "\033[34m";
const string MAGENTA = "\033[35m";
const string CYAN = "\033[36m";
const string WHITE = "\033[37m";



void set_color(const std::string& color_code) {
    cout << color_code;
}

void reset_color() {
    cout << RESET;
}