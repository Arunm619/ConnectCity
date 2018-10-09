//
// Created by root on 5/10/18.
//
#pragma once

#include <utility>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <climits>

class ConnectCities {
private:
    std::vector<std::vector<int>> grid;

    int getNumberofCity(std::vector<std::vector<int>> &grid);

    void doDFS(std::vector<std::vector<int>> &grid, int i, int j, std::vector<std::vector<bool>> &visited);

    std::vector<std::vector<int>> convertToMap();

    const std::vector<std::vector<int>> &getMap() const;

    void setMap(const std::vector<std::vector<int>> &map);

    bool helper(std::vector<std::vector<int>> &grid, int cost);

    int bestcost = INT_MAX;
public:

    void process();

    void print();

};

