#include <iostream>
#include <stack>

using namespace std;
const int SIZE = 9;




/// The second SIZE is needed in the function prototype since it is a 2D array.
// Maze display helper
void display(char arr[SIZE][SIZE] )
{
    cout << endl << "= = = = = = = = = = = " << endl;
    for(int i  = 0; i < SIZE; i++)
    {
        cout << "= ";
        for(int j  = 0; j < SIZE; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout <<  "= " << endl;
    }
    cout << "= = = = = = = = = = = " << endl;
    return;
}

// Maze display helper when completed
void displayFinal(char arr[SIZE][SIZE] )
{
    cout << endl << "Path:" << endl;
    cout << "= = = = = = = = = = = " ;
    for(int i  = 0; i < SIZE; i++)
    {
        cout << endl << "= ";
        for(int j  = 0; j < SIZE; j++)
        {
            if (arr[i][j] == 'X')
                cout <<  "  ";
            else
                cout << arr[i][j] << " ";
        }
        cout <<  "= ";
    }
    cout << endl << "= = = = = = = = = = = " << endl;
    return;
}

// Check if boundary has been crossed
bool withinTheBoundary(int i, int j)
{
    return i >= 0 &&  i < SIZE && j >= 0 &&  j < SIZE;
}


// Cell Data type with coordinates.
struct Cell {
    int x;
    int y;
};

// class Robot {
//     stack<Cell> route_taken;
//     Cell current_pos;
// };

// void Move() {

//     Cell current_pos = {1,1};

//     char maze2D[SIZE][SIZE] =
//     {
//         {'S', ' ', ' ', ' ', 'W', ' ', ' ', ' ', ' '},
//         {' ', 'W', ' ', ' ', 'W', ' ', ' ', ' ', ' '},
//         {' ', ' ', ' ', 'W', 'W', ' ', ' ', 'W', ' '},
//         {'W', ' ', 'W', ' ', ' ', ' ', ' ', ' ', ' '},
//         {' ', ' ', 'W', ' ', ' ', 'W', ' ', ' ', ' '},
//         {' ', 'W', ' ', ' ', ' ', ' ', 'W', ' ', 'W'},
//         {' ', 'W', ' ', 'W', ' ', ' ', 'W', ' ', ' '},
//         {' ', ' ', ' ', 'W', 'W', 'W', ' ', ' ', 'W'},
//         {' ', ' ', ' ', ' ', ' ', 'W', ' ', ' ', 'G'},
//     };

//     // If cell movement is within the boundary,return the cell to be moved to as the new pos.
//     if (withinTheBoundary(current_pos.x, current_pos.y + 1)) {
//         if (maze2D[next_cell.x][next_cell.y] == null)


//     } else {
//         cout << "Error: Attempted move is outside the boundary";
//     }

// }

// Returns the solved maze
char solveMaze(char arr[SIZE][SIZE]) {
    stack<Cell> path;


};

int main()
{
    char maze2D[SIZE][SIZE] =
    {
        {'S', ' ', ' ', ' ', 'W', ' ', ' ', ' ', ' '},
        {' ', 'W', ' ', ' ', 'W', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', 'W', 'W', ' ', ' ', 'W', ' '},
        {'W', ' ', 'W', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', 'W', ' ', ' ', 'W', ' ', ' ', ' '},
        {' ', 'W', ' ', ' ', ' ', ' ', 'W', ' ', 'W'},
        {' ', 'W', ' ', 'W', ' ', ' ', 'W', ' ', ' '},
        {' ', ' ', ' ', 'W', 'W', 'W', ' ', ' ', 'W'},
        {' ', ' ', ' ', ' ', ' ', 'W', ' ', ' ', 'G'},
    };

    display(maze2D);

    return 0;
}
