#include <iostream>
#include <bits/stdc++.h>
#include <fmt/format.h>
#include <fmt/color.h>
#include <fmt/ranges.h>

int main([[maybe_unused]] int argc, [[maybe_unused]] char **argv)
{
    std::string line;
    std::ifstream inputFile("input.txt");
    while (std::getline(inputFile, line))
    {
        std::stringstream lineStream(line);
        std::string token;
        while (std::getline(lineStream, token, ' '))
        {
            fmt::print("{} ", token);
        }
    }
}