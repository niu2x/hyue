#include "panic.h"

#include <stdexcept>
#include <stdlib.h>

void panic() { abort(); }