#include "Maze.h"

//Constructor
Maze::Maze()
{
    //Reads in maze from text file
    readInMaze();

    //Outputs the unsolved maze to the user
    cout<<"Original Maze: "<<endl;
    printMaze();
    cout<<endl;
}

//Destructor
Maze::~Maze()
{
    //dtor
}

//Function that reads in a 6x6 maze from a text file into a character array
void Maze::readInMaze()
{
    //Opens text file
    ifstream file("maze1.txt");

    //reads text file into character array line by line
    for(int i = 0; i<SIZEY; i++)
    {
        for(int k = 0; k<SIZEX; k++)
        {
            file>>maze[i][k];
            if(maze[i][k] == 'S')
            {
                //Find start position(S)
                startX = k;
                startY = i;
            }
        }
    }

    //close text file
    file.close();
}

//Prints out the character array that contains the maze
void Maze::printMaze()
{

    for(int i = 0; i<SIZEY; i++)
    {
        for(int k = 0; k<SIZEX; k++)
        {
            cout<<maze[i][k];
        }
        cout<<endl;
    }

}

//Creates a path from the start(S) to the finish(G) in a maze within a character array
bool Maze::findPath(int x, int y)
{
    //Makes sure path is in the maze
    if(x >= SIZEX||x < 0||y >= SIZEY||y < 0)
    {
        return false;
    }

    //Checks if goal has been reached
    if(maze[y][x] == 'G')
    {
        return true;
    }

    //Makes sure path is open
    if(maze[y][x] != '.'&& maze[y][x] != 'S')
    {
        return false;
    }

    //Marks space as visited
    maze[y][x] = '+';

    //Check space to the north
    if(findPath(x,y-1)==true)
    {
        return true;
    }
    //Check space to the east
    if(findPath(x+1,y)==true)
    {
        return true;
    }
    //Check space to the south
    if(findPath(x,y+1)==true)
    {
        return true;
    }
    //Check space to the west
    if(findPath(x-1,y)==true)
    {
        return true;
    }

    //Mark space as "dead end"
    maze[y][x] = 'x';

    return false;

}
