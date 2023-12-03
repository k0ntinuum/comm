int main() {
    
    hide_cursor();
    cls();
    int stage[rows][cols];
    int taken[rows][cols];
    randomize_stage(stage);
    player cast[players];
    randomize_cast(cast);
    mark_positions(cast, taken);
    for (int i = 0 ; i < 10000000; i++) {
        mark_positions(cast, taken);
        print_stage_if(stage, taken);
        //print_stage(stage);
        update_cast(cast,stage);
        print_avatars(cast);
        usleep(60000);
    }
    show_cursor();
    cursor_to(rows+5,0);
    //print_cast(cast);
    //printf("success!");
}