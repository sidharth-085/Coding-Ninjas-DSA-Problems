bool checkAB(char input[]) {
    if (input[0] == '\0') {
        return true;
    }
    if (input[0] != 'a') {
        return false;
    }
    if (input[1] != 'b') {
        return checkAB(input + 1);
    }
    if (input[2] == 'b') {
        if (input[3] == '\0' || input[3] == 'a') {
            return true;
        }
    }
    return false;
}
