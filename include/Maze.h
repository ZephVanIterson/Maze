//Zeph Van Iterson June-2020
//Maze Recursion Asignment
//This program:
//1. reads in a maze from a text file
//2. prints out the maze
//3. Uses recursion to find the path to the end of the maze
//4. prints ouyt the maze with the path to the finish

//*Assumes that all mazes will be 6x6





#include<iostream>
#include<fstream>
#include<vector>
#include<math.h>
#include<apmatrix.h>
#include <windows.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>

using namespace std;

#define SIZEX 6
#define SIZEY 6

class Maze
{
    public:
        Maze();
        ~Maze();

        char maze[SIZEY][SIZEX];

        int GetstartX() { return startX; }
        void SetstartX(int val) { startX = val; }
        int GetstartY() { return startY; }
        void SetstartY(int val) { startY = val; }
        bool findPath(int x, int y);

        void readInMaze();
        void printMaze();

    protected:

    private:

        int startX;
        int startY;

};


