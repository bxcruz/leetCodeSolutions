int myAtoi(char * s){
    
    long convertedInt = 0;          //return the converted integer
    int signCount = 0;              //get total number of sign chars
    int signIndex = -1;             //get the index of the sign
    int startIndex = -1;            //get the start index of number string
    int endIndex = -1;              //get the end index
    int sign = 1;                   //sign, 1 or -1
    long long power = 1;            //leftmost power of number, decrease by 10^n-1 every iteration
    int numLength = 0;              //get the length of the number
    long long tempNum = 0;          //store the largest next power digit
    const long INT_MIN_BUT_POS = ((-2147483648 + 1) * -1) + 1;
    
    if(strlen(s) == 0){
        return 0;
    }
    
    for(int findStartIndex = 0; findStartIndex < strlen(s); findStartIndex++){
        if(s[findStartIndex] <= '9' && s[findStartIndex] >= '0'){
            startIndex = findStartIndex;
            for(int findEndIndex = findStartIndex; findEndIndex < strlen(s); findEndIndex++){
                if(s[findEndIndex] > '9' || s[findEndIndex] < '0'){
                    endIndex = findEndIndex - 1;
                    break;
                }
                
            }
            if(endIndex == -1){
                endIndex = strlen(s) - 1;
            }
            break;
        }
        if(s[findStartIndex] == '+' || s[findStartIndex] == '-'){
            signCount++;
            signIndex = findStartIndex;
        }
    }
    if(signCount > 1 || startIndex < 0){
        return 0;
    }
    if(signIndex != -1 && s[signIndex] == '-'){
        sign = -1;
    }
    
    for(int j = startIndex; j >= 0; j--){
        if(s[j] != '+' && s[j] != '-' && s[j] != ' ' && (s[j] > '9' || s[j] < '0')){
            return 0;
        }
    }
    
    if(signCount > 0){
       for(int k = signIndex; k < startIndex; k++){
        if(s[k] == ' '){
            return 0;
        }
    } 
    }
    
    numLength = (endIndex - startIndex) + 1;
    power = numLength - 1;
        
    if(power > 9 && s[startIndex] > '0'){
        if(sign == 1){
            return INT_MAX;
        }else{
            return INT_MIN;
        }
    }
    
    for(int i = startIndex; i <= endIndex; i++){
        
        tempNum = (s[i]- 48) * pow(10,power);
        if(power > 9 && (tempNum + 1) == LLONG_MIN){
            if(tempNum-1 > INT_MAX && sign == 1){
            return INT_MAX;
        }
        else if(sign == -1 && tempNum > INT_MIN_BUT_POS){
            return INT_MIN;
        }
        }
        if(tempNum > INT_MAX && sign == 1){
            return INT_MAX;
        }
        else if(sign == -1 && tempNum > INT_MIN_BUT_POS){
            return INT_MIN;
        }
        
        convertedInt += tempNum;
        power--;
        
    }
    
    convertedInt *= sign;
    if(convertedInt > INT_MAX){
        convertedInt = INT_MAX;
    }
    else if(convertedInt < INT_MIN){
        if(sign == 1){
            convertedInt = INT_MAX;
        }
        else{
            convertedInt = INT_MIN; 
        }
    }
    return convertedInt;