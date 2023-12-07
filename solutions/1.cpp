#include <iostream>
#include <bits/stdc++.h>
#include <fmt/format.h>
#include <fmt/color.h>
#include <fmt/ranges.h>

std::map<int, std::string> digitsMap{
    {0, "zero"},
    {1, "one"},
    {2, "two"},
    {3, "three"},
    {4, "four"},
    {5, "five"},
    {6, "six"},
    {7, "seven"},
    {8, "eight"},
    {9, "nine"},
};

int main([[maybe_unused]] int argc, [[maybe_unused]] char **argv)
{
    uint64_t total = 0;
    if (argc < 2)
    {
        fmt::print(fg(fmt::terminal_color::bright_red), "No file passed as argument. Exiting.\n");
        return -1;
    }
    std::ifstream inputFile(argv[1]);
    if (!inputFile.is_open())
    {
        fmt::print(fg(fmt::terminal_color::bright_red), "File not found. Exiting.\n");
        return -1;
    }
    std::string line{};
    while (std::getline(inputFile, line))
    {
        std::vector<int> vec;
        for (int i = 0; i < 10; i++)
        {
            int pos = line.find(digitsMap[i]);
            if (pos != line.npos)
            {
                vec.push_back(pos);
            }
        }
        vec.push_back(line.find_first_of("0123456789"));
        fmt::print("{} {}\n", vec, std::min_element(vec.begin(), vec.end()) - vec.begin());

        int digit1 = line[std::min_element(vec.begin(), vec.end()) - vec.begin()] - '0';
        int digit2 = line[std::max({line.find_last_of("0123456789"),
                                    line.find("zero"),
                                    line.find("one"),
                                    line.find("two"),
                                    line.find("three"),
                                    line.find("four"),
                                    line.find("five"),
                                    line.find("six"),
                                    line.find("seven"),
                                    line.find("eight"),
                                    line.find("nine")})] -
                     '0';
        int number = digit1 * 10 + digit2;
        // fmt::print("Number1 = {}\tNumber2 = {}\n", digit1, digit2);
    }

    // fmt::print("{}\n", total);
}