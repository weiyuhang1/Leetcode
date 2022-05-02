/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int len = 0;
        int len4 = 4;
        while (len4 == 4) {
            char buf4[4];
            len4 = read4(buf4);           
            for (int i = 0; i < len4; i++) {    
                if (len == n) return n;   
                buf[len] = buf4[i];
                len++;
            }
        }
        return len;
    }
};