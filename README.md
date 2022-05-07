# ENGG1340 group_project
//Gluttonous_Snake (word-spelling version)

//Group Number: 16

//Team Members：

Name: Liu Xinrui     UID: 3035950204

Name: Bao Xinyang    UID: 3035952989


//Game description:
1. In this game, player has to control a snake to collect letters. In each round, a word will be given. Player needs to use keyboard (A, left; D, right; W, up; S, down) to control the moving direction of the snake to collect letters so as to spell this word. 
2. The length of words in each round will increase as the level.
3. If the entire word is spelt correctly, win this round and enter the next round.
4. If the snake hit the wall or hit itself, the game fail.
5. Complete 10 rounds, win the game.
7. Positions of letters are randomly generated each time.
8. The level of difficulty will increase with the round.
9. Enter 'Q' to quit and save the game. Next time the player enters the game, it will start from the saved round.
10. Sample.
   The word you need to spell in this round: APPLE
//   **********************************
//	  *                                *
//	  *      L                         *
//	  *                          J     *
//	  *                                *
//	  *                  $APP          *
//	  *                                *
//   *                                *
//   **********************************



//Game Features and its Corresponding Coding Requirements
1. The game allows setting random game scenarios at different time. For example, the positions of the required letters for each word are randomly distributed in the map by calling the random function rand() to generate several 2-D points.
2. Array and vector are adopted in the program so as to store some basic information, such as the wordlist in each level of the game and the body of the snake. 
Structs is also required to store the data of the player (eg. x-coordinate, y-coordinate and letters which the snake has collected) and the functions that are used to make movements and judging success or failure.
3. Dynamic memory is of vital importance in the implementation of this game, because the body of the snake depends on the letters collected by the player, meaning that it can only be determined in runtime. Such method enables instant storage of the letters on the body of the snake.
4. Game level are streamed into the program via 'game_level' file input. When the player quit and save the game, it will save the current game level to the file. Next time the player enter the game, it will start from the the level which saved in the 'game_level' file.
5. The function declarations are written in different header files, and its corresponding contents are also defined in different files (eg. execution.cpp, execution.h,  Game.cpp, Game.h). They are compiled separately and finally linked together while executing the mian program. Such measure makes the code tidy and much easier to read.

