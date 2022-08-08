#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'matrixRotation' function below.
 *
 * The function accepts following parameters:
 *  1. 2D_INTEGER_ARRAY matrix
 *  2. INTEGER r
 */

void matrixRotation(vector<vector<int>> matrix, int r) {
    int height = matrix.size();
    int width = matrix[0].size();
    vector<vector<int>> result;
    if(height % 2 == 0)
    {
        for(int k = 0; k < r; k++)
        {
            for(int loopDiff = 0 ; loopDiff < (int)(height/2); loopDiff++)
            {
                int oldUpLeft = matrix[loopDiff][loopDiff];
                int oldUpRight = matrix[loopDiff][width-1-loopDiff];
                int oldDownLeft = matrix[height-1-loopDiff][loopDiff];
                int oldDownRight = matrix[height-1-loopDiff][width-1-loopDiff];
                for(int i = loopDiff ; i < width - 1 - loopDiff ; i++) //horizontal top & bottom rows
                {
                    matrix[loopDiff][i] = matrix[loopDiff][i+1];
                    matrix[height-1-loopDiff][width-1-i] = matrix[height-1-loopDiff][width-1-i-1];
                }
                for(int j = loopDiff ; j < height - 1 - loopDiff - 1 ; j++) //vertical left & right columns
                {
                    matrix[height-1-j][loopDiff] = matrix[height-1-j-1][loopDiff];
                    matrix[j][width-1-loopDiff] = matrix[j-1][width-1-loopDiff];
                }
                //set rotated corners
                matrix[loopDiff+1][loopDiff] = oldUpLeft;
                matrix[loopDiff][width-1-loopDiff-1] = oldUpRight;
                matrix[height-1-loopDiff][loopDiff+1] = oldDownLeft;
                matrix[height-1-loopDiff-1][width-1-loopDiff] = oldDownRight;
            }
        }
    }
    for(int i = 0 ; i < height ; i++)
    {
        for(int j = 0; j < width; j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int m = stoi(first_multiple_input[0]);

    int n = stoi(first_multiple_input[1]);

    int r = stoi(first_multiple_input[2]);

    vector<vector<int>> matrix(m);

    for (int i = 0; i < m; i++) {
        matrix[i].resize(n);

        string matrix_row_temp_temp;
        getline(cin, matrix_row_temp_temp);

        vector<string> matrix_row_temp = split(rtrim(matrix_row_temp_temp));

        for (int j = 0; j < n; j++) {
            int matrix_row_item = stoi(matrix_row_temp[j]);

            matrix[i][j] = matrix_row_item;
        }
    }

    matrixRotation(matrix, r);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
