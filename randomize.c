void randomize_stage(int stage[rows][cols]) {
    for (int i = 0; i < rows; i++) 
        for (int j = 0; j < cols; j++)
            stage[i][j] = arc4random_uniform(states);
}
void randomize_cast(player cast[players]) {
    int h = 100;
    for (int p = 0; p < players; p++) {
        cast[p].avatar = p + 47;
        cast[p].trace = arc4random_uniform(states);
        for (int s = 0; s < situations; s++) cast[p].response[s] = arc4random_uniform(responses);
        cast[p].row = arc4random_uniform(rows);
        cast[p].col = arc4random_uniform(cols);
        cast[p].red = arc4random_uniform(h);
        cast[p].green = arc4random_uniform(h);
        cast[p].blue = arc4random_uniform(h);
    }      
}
