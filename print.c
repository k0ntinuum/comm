void print_cell(int i) {
    switch(i) {
        case 0: printf(" ");break;
        case 1: printf("\u2588");break;
        case 2: printf("\u2591");break;
    }
}
void print_stage(int stage[rows][cols]) {
    int h = 255;
    //int 
                h = 255;
            //h = arc4random_uniform(2) + 253;
            
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            h = 245 + arc4random_uniform(10);
            rgb(h,h,h);
            cursor_to(stage_down_start + i, stage_left_start + j);
            print_cell(stage[i][j]);
        }

    }         
    printf("\n");
}
void print_stage_if(int stage[rows][cols], int taken[rows][cols]) {
    int h = 200;
    rgb(h,h,h);
    for (int i = 0; i < rows; i++) 
        for (int j = 0; j < cols; j++) 
            if (taken[i][j] == 0)
                cursor_to(stage_down_start + i, stage_left_start + j), print_cell(stage[i][j]);
    printf("\n");
}
void print_player(player* p) {
        printf("%c  " , p->avatar);
        for (int s = 0; s < situations; s++) printf(" %2d ", p->response[s]);
        printf("%3d " , p->row);
        printf("%3d\n" , p->col);
}

void print_cast(player cast[players]) {
    for (int p = 0; p < players; p++) print_player(&cast[p]);
}
void print_avatar(player* p) {
    int h = arc4random_uniform(150);
    cursor_to(stage_down_start + p->row, stage_left_start + p->col);
    //rgb(p->red,p->green,p->blue);
    rgb(h,h,h);
    printf("%c", p->avatar);
}
void print_avatars(player cast[players]) {
    for (int p = 0; p < players; p++) print_avatar(&cast[p]);
}