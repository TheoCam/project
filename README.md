# ENGG1340 group_project
//Gluttonous_Snake (word-spelling version)

//Group Number: 16

//Team Members
Name: Liu Xinrui     UID: 3035950204
Name: Bao Xinyang    UID: 3035952989


//Game description:
1.	In each round, a word will be given. Players need to use keyboard (A, left; D, right; W, up; S, down), to control the moving direction of the snake to eat letters and spell this word. 
2.	Two letters will be given each time with one correct and one wrong, players need to choose the correct one and eat it.
3.	If the entire word is spelt correctly, win this round.
4.	If the snake hit the wall or obstacles or eat the wrong letters, the game fail.
5.	Complete 10 rounds, win the game.
6.	Maps and obstacles within the maps are generated randomly each round.
7.	Positions of letters are randomly generated each time.
8.	The level of difficulty will increase with the round.
9.	(积分制？）


//Game Features and its Corresponding Coding Requirements
1. The game allows setting random game scenarios at different time. For example, the positions of the required letters for each word are randomly distributed in the map by calling the random function rand() to generate several 2-D points.
2. Arrays are adopted in the program so as to store some basic information, such as the wordlist in each level of the game and the body of the snake. Classes and structs are also required to store the data of the player (eg. current position, moving speed, game level) and the functions that are used mo make movements and judging success or failure.
3. Dynamic memory is of vital importance in the implementation of this game, because the body of the snake depends on the input(keyboard input) from the player, meaning that it can only be determined in runtime. This enables the instant storge of the letters on the body of the snake.
4. Wordlists/dictionaries for different levels are streamed into the program via file input, and file output is used to write the instant status of the game into a txt file, enabling loading and saving game status instantly.
5. The function declarations are written in different header files, and its corresponding contents are also defined in different files. They are compiled separately and finally linked together while executing the mian program. Such measure makes the code tidy and much easier to read.
