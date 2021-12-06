
#ifndef JOEL_MACROS_H
#define JOEL_MACROS_H

/// evaluates to nothing.
/// Just signifies that the reference on which it is applied will modify its value
# define mut

/// signifies that the value will bre dropped inside the function so it shouldn't be used after that call
#define owned


enum bool {false, true};

#endif