1> Title: **TIC TAC TOE GAME DEVELOPMENT USING MUTUAL EXCLUSION IN C**

2> Description
Mutual exclusion is a fundamental concept in computer science and concurrent programming, ensuring that only one process or thread can access a critical section of code at any given time.
In the context of game development, mutual exclusion plays a crucial role in maintaining game integrity and preventing conflicts between players. 
This program explores the application of mutual exclusion in the classic game of Tic-Tac-Toe and its implications for creating a fair and engaging gaming experience.
Tic-Tac-Toe is a two-player, turn-based game where each player strives to create a winning pattern of their symbols on a 3x3 grid. 
To implement mutual exclusion in this game, we as developers must address several key challenges.
First, we need to ensure that only one player can make a move at a time to prevent simultaneous moves, which would disrupt the game's logic. 
Second, we must handle the synchronization of player inputs and game state updates to maintain consistency and fairness. 
Finally, mutual exclusion mechanisms must prevent unauthorized access to game data to prevent cheating and maintain a level playing field

3> How to Install and Run this Program?
Simply download the file, and run it in a terminal or a compiler which supports mutual exclusion.
In our case, we used an Ubuntu terminal through a virtual machine and Windows 11. 
We also tested this on some online compilers like onlinegdb.com/online_c_compiler

4> How to Use and Feed your Inputs in the Code?
When you run the file, the terminal will display an empty board and request the first player "X" to take their turn. 
You must enter the coordinates for your turn in the format <ROW COLUMN>, space included.
After a valid turn is taken, the chance will rotate between Player 1 "X" and Player 2 "O" until a conclusive outcome is reached, ie a win for one of the players or a draw.
Once the outcome is reached, the program will stop executing.

5> Credits
I developed this along with my teammates SATVIK SHARMA and PREM LOHIA, my friends and colleagues at SRM IST Chennai.
