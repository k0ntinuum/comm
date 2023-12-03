void randomize_stage(int stage[rows][cols]) {
    for (int i = 0; i < rows; i++) 
        for (int j = 0; j < cols; j++)
            stage[i][j] = arc4random_uniform(states);
}
void randomize_cast(player cast[players]) {
    for (int p = 0; p < players; p++) {
        cast[p].avatar = p + 47;
        for (int s = 0; s < situations; s++) cast[p].response[s] = arc4random_uniform(responses);
        cast[p].row = arc4random_uniform(rows);
        cast[p].col = arc4random_uniform(cols);
        cast[p].red = arc4random_uniform(255);
        cast[p].green = arc4random_uniform(255);
        cast[p].blue = arc4random_uniform(255);
    }      
}
