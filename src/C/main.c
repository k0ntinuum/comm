int main() {
    bool f = true;
    
    hide_cursor();
    cls();
    int stage[rows][cols];
    int taken[rows][cols];
    randomize_stage(stage);
    player cast[players];
    randomize_cast(cast);
    for (int i = 0 ; i < 10000000; i++) {
        
        
        //print_stage(stage);
        update_cast(cast,stage);
        //mark_positions(cast, taken);
        //print_stage_if(stage, taken);
        print_stage(stage);
        print_avatars(cast);
        printf("\n");
        usleep(80000);
    }
    show_cursor();
    cursor_to(rows+5,0);
    //print_cast(cast);
    //printf("success!");
}