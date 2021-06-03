#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

namespace game_of_life
{
    vector< vector<int> > parse_state(string representation);
    string print_state(vector< vector<int> > state);
    vector< vector<int> > calculate_next_state(vector< vector<int> > state);
    int calculate_next_cell_state(int state, int num_neighbors);
}