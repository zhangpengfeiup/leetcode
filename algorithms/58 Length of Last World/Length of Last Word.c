// that below is the right answer refer from https://leetcode.com/problems/length-of-last-word/discuss/22228/My-solution-in-C-(0-ms)
int lengthOfLastWord(char *s) {
    int length,num = 0,flag = 0;
    
    length = strlen(s);
    
    int i;
    
    for (i = length-1;i >= 0;i--) {
        if ((s[i] >='a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
            num++;
            flag = 1;
        }else if (s[i] == ' ' && flag) {
            break;
        }
    }
    return num;
}


// my first think is reverse then count it length,find it will wrong when meet some case as "   abc a"

