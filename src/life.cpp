#include <iostream>

// the eight neighbors are: 
// current +/- 1, width-1, width, width+1
// default is dead (if number goes off end, dead)

// cases:
// if live: 
// live_neighbor < 2: die
// live_neighbor = 2, 3: no change
// live_neighbor > 3: die
// if dead:
// live_neighbor = 3: reanimate

int main (int argc, char const* argv[])
{

}

