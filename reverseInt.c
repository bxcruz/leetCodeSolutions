int reverse(int x){
    long revx = 0;
    int lhs = 0;
    int rhs = 0;
    char temp;
    
    char xStr[12]; //10 + 2 for the sign and overflow
    sprintf(xStr, "%d", x);
    
    xStr[0] == '-'?(lhs = 1):(lhs = 0);
    rhs = strlen(xStr) - 1;

    while(lhs < rhs){
        temp = xStr[rhs];
        xStr[rhs] = xStr[lhs];
        xStr[lhs] = temp;
        lhs++;
        rhs--;
    }
    
    revx = atol(xStr);
    if(revx > INT_MAX || revx < INT_MIN){
        return 0;
    }
    
    else{
        return revx;
    }
}