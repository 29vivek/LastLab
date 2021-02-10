#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int main()
{
    string text, key;
    int i, j, k, l, n;
    char a;
    cout << "Enter the text:" << endl;
    cin >> text;
    cout << "Enter the key :" << endl;
    cin >> key;
    char matrix[5][5];
    int visited[26] = {0};
    n = key.size();
    k = j = 0;

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            matrix[i][j] = 'A';
        }
    }

    int position_row[26] = {0};
    int position_column[26] = {0};

    for (i = 0; i < 5; i++)
    {
        j = 0;
        while (k < n && j < 5)
        {
            key[k] = tolower(key[k]);
            if (visited[key[k] - 'a'] == 0)
            {
                visited[key[k] - 'a'] = 1;
                if (visited[8] == 1 && visited[9] == 0)
                {
                    position_row[8] = i;
                    position_column[8] = j;
                    position_row[9] = i;
                    position_column[9] = j;
                    visited[9] = 1;
                }
                else if (visited[9] == 1 && visited[8] == 0)
                {
                    position_row[8] = i;
                    position_column[8] = j;
                    position_row[9] = i;
                    position_column[9] = j;
                    visited[8] = 1;
                }
                matrix[i][j] = key[k];
                j++;
            }
            k++;
        }
    }

    for (i = 0; i < 26; i++)
    {
        if (visited[i] == 0)
        {
            k = i;
            break;
        }
    }

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (matrix[i][j] == 'A')
            {
                visited[k] = 1;
                a = 97 + k;
                if (visited[8] == 1 && visited[9] == 0)
                {
                    position_row[8] = i;
                    position_column[8] = j;
                    position_row[9] = i;
                    position_column[9] = j;
                    visited[9] = 1;
                }
                else if (visited[9] == 1 && visited[8] == 0)
                {
                    position_row[8] = i;
                    position_column[8] = j;
                    position_row[9] = i;
                    position_column[9] = j;
                    visited[8] = 1;
                }
                matrix[i][j] = a;
            }
            for (l = k; l < 26; l++)
            {
                if (visited[l] == 0)
                {
                    k = l;
                    break;
                }
            }
        }
    }

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            position_row[matrix[i][j] - 'a'] = i;
            position_column[matrix[i][j] - 'a'] = j;
        }
    }

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    n = text.size();
    string encipher = "";
    string decipher = "";

    int row, col, row1, col1;
    vector<int> ij;

    for (i = 0; i < n; i++)
    {
        if (i + 1 < n && text[i] != text[i + 1])
        {
            row = position_row[text[i] - 'a'];
            col = position_column[text[i] - 'a'];
            row1 = position_row[text[i + 1] - 'a'];
            col1 = position_column[text[i + 1] - 'a'];
            i++;
        }
        else if (i + 1 < n && text[i] == text[i + 1])
        {
            row = position_row[text[i] - 'a'];
            col = position_column[text[i] - 'a'];
            if (text[i] == 'x')
            {
                row1 = position_row[0];
                col1 = position_column[0];
            }
            else
            {
                row1 = position_row['x' - 'a'];
                col1 = position_column['x' - 'a'];
            }
        }
        else
        {
            row = position_row[text[i] - 'a'];
            col = position_column[text[i] - 'a'];
            if (text[i] == 'x')
            {
                row1 = position_row[0];
                col1 = position_column[0];
            }
            else
            {
                row1 = position_row['x' - 'a'];
                col1 = position_column['x' - 'a'];
            }
        }
        if (row == row1)
        {
            encipher += matrix[row][(col + 1) % 5];
            encipher += matrix[row][(col1 + 1) % 5];
        }
        else if (col == col1)
        {
            encipher += matrix[(row + 1) % 5][col];
            encipher += matrix[(row1 + 1) % 5][col];
        }
        else
        {
            encipher += matrix[row][col1];
            encipher += matrix[row1][col];
        }
    }
    cout << encipher << endl;

    for (i = 0; i < n; i = i + 2)
    {
        row = position_row[encipher[i] - 'a'];
        col = position_column[encipher[i] - 'a'];
        row1 = position_row[encipher[i + 1] - 'a'];
        col1 = position_column[encipher[i + 1] - 'a'];
        if (row == row1)
        {
            decipher += matrix[row][(5 + col - 1) % 5];
            decipher += matrix[row][(5 + col1 - 1) % 5];
        }
        else if (col == col1)
        {
            decipher += matrix[(5 + row - 1) % 5][col];
            decipher += matrix[(5 + row1 - 1) % 5][col];
        }
        else
        {
            decipher += matrix[row][col1];
            decipher += matrix[row1][col];
        }
    }

    cout << decipher << endl;

    return 0;
}
