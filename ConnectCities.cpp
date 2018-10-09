//
// Created by root on 5/10/18.
//

#include "ConnectCities.h"

std::vector<std::pair<int, int>> directions = {
        {1,  0},
        {-1, 0},
        {0,  1},
        {0,  -1},
        {-1, 1},
        {-1, -1},
        {1,  1},
        {1,  -1}

};

bool ConnectCities::helper(std::vector<std::vector<int>> &map, int cost) {

    if (getNumberofCity(map) == 1) {
        bestcost = std::min(cost, bestcost);
        return true;
    }

    for (int i = 0; i < map.size(); i++) {
        for (int j = 0; j < map[0].size(); j++) {
            if (map[i][j] != -1) {
                int temp = map[i][j];
                cost += temp;
                map[i][j] = -1;

                helper(map, cost);

                map[i][j] = temp;
                cost -= temp;
            }
        }
    }

    return true;
}


void ConnectCities::doDFS(std::vector<std::vector<int>> &grid, int i, int j,
                          std::vector<std::vector<bool>> &visited) {
    //boundary check

    if (i < 0 or i >= grid.size() or j < 0 or j >= grid[0].size())
        return;

    //already visited
    if (visited[i][j])
        return;

    if (grid[i][j] == -1) {
        visited[i][j] = true;

        for (auto dir : directions) {
            doDFS(grid, i + dir.first, j + dir.second, visited);
        }

    }
}


int ConnectCities::getNumberofCity(std::vector<std::vector<int>> &grid) {

    //number of islands
    int islands = 0;

    //rows
    int row = grid.size();
    //return 0 if null
    if (row == 0) return islands;

    int col = grid[0].size();

    //mappings of visited
    std::vector<std::vector<bool>> visited(row, std::vector<bool>(col, false));

    //traverse all ifnot already visited
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (grid[i][j] == -1 and visited[i][j] == false) {
                islands++;
                doDFS(grid, i, j, visited);
            }
        }
    }

    return islands;
}


const std::vector<std::vector<int>> &ConnectCities::getMap() const {
    return grid;
}

void ConnectCities::setMap(const std::vector<std::vector<int>> &grid) {
    ConnectCities::grid = grid;
}

std::vector<std::vector<int>> ConnectCities::convertToMap() {
    std::string input;
    getline(std::cin, input);

    std::vector<int> temp;
    std::vector<std::vector<int>> map;


    std::istringstream ss(input);
    std::string token, number;

    while (std::getline(ss, token, '#')) {

        std::istringstream row(token);
        while (getline(row, number, '@')) {
            temp.push_back(stoi(number));
        }

        map.push_back(temp);
        temp.clear();

    }


    return map;

}

void ConnectCities::print() {
    for (auto i : grid) {
        for (auto j : i) std::cout << j << " ";
        endl(std::cout);
    }
}

void ConnectCities::process() {

    grid = convertToMap();

    print();

    int numberofcities = getNumberofCity(grid);

    if (numberofcities <= 1) {
        std::cout << 0 << std::endl;
    } else {

        helper(grid, 0);
        std::cout << bestcost << std::endl;
    }


}
