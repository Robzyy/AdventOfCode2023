#include <iostream>
#include <bits/stdc++.h>
#include <fmt/format.h>
#include <fmt/color.h>
#include <fmt/ranges.h>

int main([[maybe_unused]] int argc, [[maybe_unused]] char **argv)
{
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

    std::string line;
    uint64_t sum = 0;

    while (std::getline(inputFile, line))
    {
        std::stringstream lineStream(line);
        std::string token;
        std::vector<int> winningNumbers;
        std::vector<int> myNumbers;
        uint64_t cardPow = 0;

        // Example string:
        // Card 1: 41 48 83 86 17 | 83 86  6 31 17  9 48 53

        // Split line by pipe character '|'
        std::getline(lineStream, token, '|');

        // Working with this part of the string:
        // Card 1: 41 48 83 86 17

        // Skip "Card" and card ID
        token = token.substr(token.find(':') + 2);

        for (int i = 0; i < token.size(); i = i + 3)
        {
            winningNumbers.push_back(std::stoi(token.substr(i, i + 2)));
        }

        // Now working with the part of the string after pipe
        std::getline(lineStream, token, '|');

        // i = 1 because there is a space after pipe
        for (int i = 1; i < token.size(); i = i + 3)
        {
            myNumbers.push_back(std::stoi(token.substr(i, i + 2)));
        }

        for (const auto &i : winningNumbers)
        {
            for (const auto &j : myNumbers)
            {
                if (i == j)
                {
                    if (cardPow == 0)
                    {
                        cardPow = 1;
                    }
                    else
                    {
                        cardPow = cardPow << 1;
                    }
                }
            }
        }
        // fmt::print("{::2} -- {::2} -- cardPow = {}\n", winningNumbers, myNumbers, cardPow);

        sum += cardPow;
    }

    fmt::println("Result = {}", sum);
}