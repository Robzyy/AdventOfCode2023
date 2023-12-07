#include <iostream>
#include <bits/stdc++.h>
#include <fmt/format.h>
#include <fmt/color.h>
#include <fmt/ranges.h>

bool checkNeighbors(char matrix[][256], int pos_i, int pos_j)
{
    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            if (!strchr("1234567890.", matrix[pos_i + i][pos_j + j]))
            {
                return true;
            }
        }
    }
    return false;
}

int main([[maybe_unused]] int argc, [[maybe_unused]] char **argv)
{
    uint64_t sum = 0;

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

    // Use a char matrix to store data
    char matrix[256][256]{};

    // Fill it with periods
    for (int i = 0; i < 256; i++)
    {
        for (int j = 0; j < 256; j++)
        {
            matrix[i][j] = '.';
        }
    }

    // Read input data
    for (int i = 1; i <= 140; i++)
    {
        for (int j = 1; j <= 140; j++)
        {
            inputFile >> matrix[i][j];
        }
    }

    // Print data, have sybols colored and periods faded out
    for (int i = 0; i < 142; i++)
    {
        for (int j = 0; j < 142; j++)
        {
            if (!strchr("1234567890.", matrix[i][j]))
            {
                fmt::print(fmt::fg(fmt::terminal_color::bright_red), "{:c}", matrix[i][j]);
            }
            else if(strchr(".", matrix[i][j]))
            {
                fmt::print(fmt::fg(fmt::terminal_color::black), "{:c}", matrix[i][j]);
            }
            else
            {
                fmt::print("{:c}", matrix[i][j]);
            }
        }
        fmt::print("\n");
    }

    // Iterate over every element in matrix
    for (int i = 1; i <= 140; i++)
    {
        for (int j = 1; j <= 140; j++)
        {
            // Check if element is a digit and if it has a neighbouring symbol
            if (matrix[i][j] >= '0' && matrix[i][j] <= '9' && checkNeighbors(matrix, i, j))
            {
                // Determine where the number starts and where it ends
                int deltaNeg = 0, deltaPos = 0;
                char number[8]{};

                while (strchr("1234567890", matrix[i][j - deltaNeg - 1]))
                {
                    deltaNeg++;
                }
                while (strchr("1234567890", matrix[i][j + deltaPos + 1]))
                {
                    deltaPos++;
                }
                strncpy(number, matrix[i] + j - deltaNeg, deltaNeg + deltaPos + 1);
                int numberAsInt = atoi(number);
                sum += numberAsInt;
                // Skip the number, we don't want to detect it again
                // if it has more digits close to symbols
                j += deltaPos + 1;
            }
        }
    }

    fmt::print("Sum = {}\n", sum);
}