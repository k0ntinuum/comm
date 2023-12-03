int safe_row(int r ) {
    if (r > rows - 1) return r - rows;
    if (r < 0) return r + rows;
    return r;
}
int safe_col(int c ) {
    if (c > cols - 1) return c - cols;
    if (c < 0) return c + cols;
    return c;
}

int situation(int stage[rows][cols], int row,int col) {
    int sum = 0;
    sum += stage[safe_row(row - 1)][col];
    sum += 2*stage[row][safe_col(col + 1)];
    sum += 4*stage[safe_row(row + 1)][col];
    sum += 8*stage[row][safe_col(col - 1)];
    sum += 16*stage[row][col];
    return sum;
}
void flip(int stage[rows][cols], int r,int c) {
    stage[r][c] = !stage[r][c];
    //stage[r][c] == 0 ? stage[r][c] = 1 : (stage[r][c] = 0);
}

void update_player(player* p , int stage[rows][cols]) {
    int s = situation(stage, p->row, p->col);
    int r = p->response[s];
    flip(stage, p->row,p->col);
    switch (r) {
        case 0 : p->row = safe_row(p->row - 1);break;
        case 1 : p->row = safe_row(p->row - 1);p->col = safe_col(p->col + 1);break;
        case 2 : p->col = safe_col(p->col + 1);break;
        case 3 : p->row = safe_row(p->row + 1);p->col = safe_col(p->col + 1);break;
        case 4 : p->row = safe_row(p->row + 1);break;
        case 5 : p->row = safe_row(p->row + 1);p->col = safe_col(p->col - 1);break;
        case 6 : p->col = safe_col(p->col - 1);break;
        case 7 : p->row = safe_row(p->row - 1);p->col = safe_col(p->col - 1);break;
    }
}
void update_cast(player cast[players], int stage[rows][cols]) {
    for (int p = 0; p < players; p++) update_player(&cast[p], stage);
}
void mark_positions(player cast[players], int taken[rows][cols]) {
    for (int i = 0; i < rows; i++) for (int j = 0; j < cols; j++) taken[i][j] = 0;
    for (int p = 0; p < players; p++) taken[cast[p].row][cast[p].col] = 1;
}