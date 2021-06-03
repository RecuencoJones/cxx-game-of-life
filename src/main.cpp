#include <string>
#include <vector>
#include "game_of_life.h"

using std::vector;

std::string initial_state = "......\n"
                            "..+...\n"
                            "...+..\n"
                            ".+++..\n"
                            "......"
                            ;

int main()
{
    vector< vector<int> > state = game_of_life::parse_state(initial_state);

    std::cout << game_of_life::print_state(state) << std::endl;

    for (int i = 0; i < 5; i++)
    {
        state = game_of_life::calculate_next_state(state);

        std::cout << game_of_life::print_state(state) << std::endl;
    }

    return 0;
}