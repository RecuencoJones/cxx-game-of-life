#include "game_of_life.h"

vector<string> tokenize(const string &value, const string delimiter)
{
    size_t last = 0;
    size_t next = 0;
    vector<string> res;

    while ((next = value.find(delimiter, last)) != string::npos)
    {
        string line = value.substr(last, next-last);

        res.push_back(line);
        last = next + 1;
    }

    res.push_back(value.substr(last));

    return res;
}

namespace game_of_life
{
    const vector< vector<int> > neighborhood = {
        { -1, -1 }, { -1, 0 }, { -1,  1 },
        {  0, -1 },            {  0,  1 },
        {  1, -1 }, {  1, 0 }, {  1,  1 }
    };

    vector< vector<int> > parse_state(const string &representation)
    {
        vector< vector<int> > res;

        vector<string> lines = tokenize(representation, "\n");

        for (auto line : lines)
        {
            vector<int> row;
            for (char & c : line)
            {
                row.push_back(c == '+' ? 1 : 0);
            }
            res.push_back(row);
        }

        return res;
    }

    void print_state(const vector< vector<int> > &state)
    {
        for (auto row : state)
        {
            for (int cell : row)
            {
                std::cout << (cell == 1 ? '+' : '.');
            }
            std::cout << std::endl;
        }
    }

    vector< vector<int> > calculate_next_state(const vector< vector<int> > &state)
    {
        vector< vector<int> > res {state};

        for (int y {0}; y < state.size(); y++)
        {
            for (int x {0}; x < state[y].size(); x++)
            {
                int cell {state[y][x]};
                int neighbors {0};

                for (vector<int> neighbor : neighborhood)
                {
                    int neighbor_x { neighbor[0] + x };
                    int neighbor_y { neighbor[1] + y };

                    if (neighbor_y >= 0 && neighbor_y < state.size())
                    {
                        if (neighbor_x >= 0 && neighbor_x < state[y].size())
                        {
                            neighbors += state[neighbor_y][neighbor_x];
                        }
                    }

                }

                res[y][x] = calculate_next_cell_state(cell, neighbors);
            }
        }

        return res;
    }

    int calculate_next_cell_state(int state, int num_neighbors)
    {
        if (state == 0 && num_neighbors == 3) return 1;
        if (num_neighbors < 2) return 0;
        if (num_neighbors > 3) return 0;
        return state;
    }
}