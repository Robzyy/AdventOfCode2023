#include <iostream>
#include <bits/stdc++.h>
#include <fmt/format.h>
#include <fmt/color.h>
#include <fmt/ranges.h>

int main([[maybe_unused]] int argc, [[maybe_unused]] char **argv)
{
    constexpr uint8_t redCubes = 12, greenCubes = 13, blueCubes = 14;
    uint64_t powerSum = 0;

    std::string line;
    std::ifstream inputFile("input.txt");
    while (std::getline(inputFile, line))
    {
        bool isGameOK = true;

        uint32_t minRedCubes, minGreenCubes, minBlueCubes;
        minRedCubes = minGreenCubes = minBlueCubes = 0;

        std::stringstream lineStream(line);
        std::string token;

        // Example string:
        // Game 1: 10 green, 9 blue, 1 red; 1 red, 7 green; 11 green, 6 blue; 8 blue, 12 green

        // Skip "Game", get the game ID
        std::getline(lineStream, token, ' ');
        std::getline(lineStream, token, ' ');
        uint32_t gameID = stoi(token);

        // Cntionously read tokens 2 by 2, first the number of cubes then the color
        while (std::getline(lineStream, token, ' '))
        {
            uint32_t numberOfCubes = stoi(token);
            std::getline(lineStream, token, ' ');
            std::string cubeColor = token;
            if (cubeColor[cubeColor.size() - 1] == ',' || cubeColor[cubeColor.size() - 1] == ';')
            {
                cubeColor = cubeColor.substr(0, cubeColor.size() - 1);
            }

            if (cubeColor == "red")
            {
                minRedCubes = std::max(minRedCubes, numberOfCubes);
            }
            else if (cubeColor == "green")
            {
                minGreenCubes = std::max(minGreenCubes, numberOfCubes);
            }
            else if (cubeColor == "blue")
            {
                minBlueCubes = std::max(minBlueCubes, numberOfCubes);
            }
        }
        powerSum += (minRedCubes * minGreenCubes * minBlueCubes);
        // fmt::print("Min {}: {}\tmin {}: {}\tmin {}: {}\n",
        //            fmt::styled("red", fmt::fg(fmt::terminal_color::bright_red)),
        //            minRedCubes,
        //            fmt::styled("green", fmt::fg(fmt::terminal_color::bright_green)),
        //            minGreenCubes,
        //            fmt::styled("blue", fmt::fg(fmt::terminal_color::bright_blue)),
        //            minBlueCubes);
    }
    fmt::print("{}\n", powerSum);
}