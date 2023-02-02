#include "Maze.h"

int main()
{
    //Outputs a legend to explain what the symbols mean in the maze
    cout<<"Legend: "<<endl;
    cout<<". = Open space "<<endl;
    cout<<"# = Obstacle "<<endl;
    cout<<"S = Start "<<endl;
    cout<<"G = Finish "<<endl;
    cout<<"+ = Path to finish "<<endl;
    cout<<"x = Incorrect Path(dead end) "<<endl<<endl;;

    //Create a maze
    Maze maze1;

    //Siolve the maze
    maze1.findPath(maze1.GetstartX(), maze1.GetstartY());

    //Re-mark the start as start(S)
    maze1.maze[maze1.GetstartY()][maze1.GetstartX()] = 'S';

    //Outputs the solved maze to the user
    cout<<"Solved Maze: "<<endl;
    maze1.printMaze();

    return 0;
}
