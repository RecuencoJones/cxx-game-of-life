#include <string>
#include <vector>
#include "game_of_life.h"

using std::vector;

const std::string initial_state {
    "......\n"
    "..+...\n"
    "...+..\n"
    ".+++..\n"
    "......"
};

int main()
{
    vector< vector<int> > state = game_of_life::parse_state(initial_state);

    game_of_life::print_state(state);

    for (int i = 0; i < 5; i++)
    {
        state = game_of_life::calculate_next_state(state);

        std::cout << std::endl;

        game_of_life::print_state(state);
    }

    return 0;
}