#ifndef UTILS_H
#define UTILS_H

#include <string>

using namespace std;
using namespace std::filesystem; 
// Function to set text color (cross-platform)
void set_color(const string& color_code);
void reset_color();

// Constants for colors (ANSI escape codes)
extern const string RED;
extern const string GREEN;
extern const string RESET;
extern const string BLACK;
extern const string YELLOW;
extern const string BLUE;
extern const string MAGENTA;
extern const string CYAN;
extern const string WHITE;


#endif // UTILS_H
