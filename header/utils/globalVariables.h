#ifndef GLOBALVARIABLES_H
#define GLOBALVARIABLES_H

#define MAZE_WIDTH 672
#define MAZE_HEIGHT 864

#define HEADER_SCREEN_WIDTH 672
#define HEADER_SCREEN_HEIGHT 96
#define HEADER_X_POSITION 0
#define HEADER_Y_POSITION 0

#define TOTAL_SCREEN_WIDTH 672
#define TOTAL_SCREEN_HEIGHT (MAZE_HEIGHT + HEADER_SCREEN_HEIGHT + FOOTER_SCREEN_HEIGHT)

#define MAZE_WIDTH_IN_ARRAY 21
#define MAZE_HEIGHT_IN_ARRAY 27

#define FOOTER_SCREEN_WIDTH 672
#define FOOTER_SCREEN_HEIGHT 40

#define CELL_SIZE 32
#define PACMAN_SIZE 14

#define PACMAN_DEFAULT_DIRECTION DIRECTION_RIGHT
#define PACMAN_SPAWN_ANIMATION 0
#define PACMAN_DEFAULT_ANIMATION 1

#define PACMAN_LIVES 3
#define PACMAN_LIVES_X_DISPLAY_OFFSET 10
#define PACMAN_LIVES_Y_DISPLAY_OFFSET 3

#define DEFAULT_SCORE 0
#define DEFAULT_HIGH_SCORE 0

#define DIRECTION_ARROW_SIZE 7
#define DIRECTION_ARROW_OFFSET (PACMAN_SIZE / 2)
#define DIRECTION_ARROW_DISPLAY_SIZE (DIRECTION_ARROW_SIZE * (float)CELL_SIZE / (float)PACMAN_SIZE)
#define DIRECTION_ARROW_PADDING 25

#define ANIMATION_SPEED 15
#define GAME_FRAMERATE 300.0
#define DELAY 1.0 / GAME_FRAMERATE * 1000

#define LETTERS_IN_ALPHABET 26
#define LETTERS_SIZE 7
#define LETTERS_X_OFFSET 8
#define LETTERS_Y_OFFSET 0
#define ALPHABET_FIRST_LETTER_X_POSITION 45
#define ALPHABET_FIRST_LETTER_Y_POSITION 301

#define NUMBER_OF_NUMBERS 10
#define NUMBERS_SIZE 7
#define NUMBERS_X_OFFSET 8
#define NUMBERS_Y_OFFSET 0
#define NUMBERS_FIRST_NUMBER_X_POSITION 4
#define NUMBERS_FIRST_NUMBER_Y_POSITION 53

#define ONE_UP_X_POSITION 70
#define ONE_UP_Y_POSITION 20
#define HIGH_SCORE_X_POSITION 260
#define HIGH_SCORE_Y_POSITION 20

#define LETTERS_DISPLAY_RATIO ((float)LETTERS_X_OFFSET / (float)LETTERS_SIZE)

#endif //GLOBALVARIABLES_H