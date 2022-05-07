# ENGG1340 group_project
//Gluttonous_Snake (word-spelling version)

//Group Number: 16

//Team Members：

Name: Liu Xinrui     UID: 3035950204

Name: Bao Xinyang    UID: 3035952989


//Game description:
1. In this game, player has to control a snake to collect letters. In each level, a word will be given. Player needs to use keyboard (a, left; d, right; w, up; s, down) to control the moving direction of the snake to collect letters so as to spell this word. 
2. The game difficulty will increase, which means the length of words in each level will increase.
3. If the entire word is spelt correctly, win this round and enter the next level.
4. If the snake hit the wall or hit itself, the game fail.
5. Complete 10 levels, win the game.
6. Positions of letters are randomly generated each time.
7. Enter 'q' to quit and save the game. Next time the player enters the game, it will start from the saved level.
8. Sample.
   The word you need to spell in level 0: APPLE
//   **********************************
//	  *                                *
//	  *      l                         *
//	  *                                *
//	  *                                *
//	  *                  $app          *
//	  *                                *
//   *                                *
//   **********************************



//Game Features and its Corresponding Coding Requirements
1. The game allows setting random game scenarios at different time. For example, the positions of the required letters for each word are randomly distributed in the map by calling the random function rand() to generate several 2-D points.
2. Array and vector are adopted in the program so as to store some basic information, such as the wordlist in each level of the game and the body of the snake. 
Structs is also required to store the data of the player (eg. x-coordinate, y-coordinate and letters which the snake has collected).
3. Dynamic memory is of vital importance in the implementation of this game, because the body of the snake depends on the letters collected by the player, meaning that it can only be determined in runtime. Such method enables instant storage of the letters on the body of the snake. In this game, we use vector to store the data of the snake such as the position and letter of each node, which is a use of dynamic memory management.
4. Each time when the palyer saves the game, the game level is streamed into the file named 'game_level.txt' by using file output. Next time when the player enter the game, the program will read the previously stored data in 'game_level.txt' by using file input and let the game start from the level which saved in the 'game_level' file.
5. The function declarations are written in different header files, and its corresponding contents are also defined in different .cpp files (eg. execution.cpp, execution.h,  Game.cpp, Game.h). They are compiled separately and finally linked together while executing the mian program. Such measure makes the code tidy and much easier to read. 



//List of nin-standard C/C++ librarires
1. <termios.h>
This is a library that contains the functions and struct for Linux terminal I/O. 
termios: We have use this struct to declare variables storing Linux terminal I/O information.
tcgetattr(): We use this function to get the I/O information of the current terminal
new_mode.c_lflag &= (~ICANON): This disables the canonical mode of reading input (the end of reading input will not be simply judged by an EOL)
new_mode.c_lflag &= (~ECHO): disable the echoing of reading input (the input text will not be shown)
new_mode.c_cc[VMIN] = 1: setting the length of the expected input to be 1
new_mode.c_cc[VTIME] = 0: etting the time of input timeout
tcsetattr(0, TCSANOW, &new_mode): set the input mode of the terminal according to the attributes stored in new_mode. TCSANOW means update immediately

The above mentioned functions help set the input mode of Linux terminal. It allows player to make instructions by directly pressing keys on the keyboard (eg: a,w,s,d). There is no need to press 'enter' to mark the end of reading input, and the input char will not be shown in ther terminal, making the interface clean and tidy.

2. <iomanip>
We use setw() and setfill() function in this library to format the output of our program


   
//Compilation and Execution Instructions
1. Download all the files to the same directory
2. Enter the Linux terminal make that directory as the present working directory
3. Input command: make main
4. If compiled successfully, enter: ./main
5. Now you enter the game, try to use a,w,s,d to control the direction of the snake (a, left; d, right; w, up; s, down) Notice that, user cannot input a direction that is in opposite direction of the previously input one (for example, use cannot press ’a’ if his or her previous input was ‘d’)
6. If you want to save and quit the game, press 'q'
