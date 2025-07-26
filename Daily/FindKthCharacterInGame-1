class Solution {
public:
   /* char kthCharacter(int k) {
        string word="a";
        while(word.length()<k){
         string next;
         for (char ch:word){
            next+=(ch=='z')?'a':ch+1;
         }
         word+=next;
        }
        return word[k-1];
    }
    */
    char kthCharacter(int k, int step = 0) {
    // Base case
    if (k == 1) return 'a';

    // Find smallest power of 2 >= k
    int len = 1;
    int steps = 0;
    while (len < k) {
        len *= 2;
        steps++;
    }

    len /= 2; // previous step length
    if (k <= len) {
        return kthCharacter(k, steps - 1);
    } else {
        char prev = kthCharacter(k - len, steps - 1);
        return prev == 'z' ? 'a' : prev + 1;
    }
}

};