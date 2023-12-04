const int rows = 10;
const int cols = 20;
const int players = 10;
const int situations = 32;
const int responses = 8;
const int states = 2;
const int stage_down_start = 2;
const int stage_left_start = 5;


typedef struct {
    char avatar;
    int trace;
    int response[situations];
    int row;
    int col;
    int red;
    int green;
    int blue;
} player;
//int cell[ROWS][COLS] = {0};
//int person[PEOPLE][SITUATIONS];
