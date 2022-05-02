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
        int i = 0;
        int j = 0;
        for (int i = 0; i < n / 4 + 1; i++) {
            char buf4[4];
            int len4 = read4(buf4);
            
            while (j < len4 && j + len <= n) {
                buf[len + j] = buf4[j];
                if (j + len == n) return n;
                j++;
            }

            j = 0;
            len += len4;
            if (len4 < 4) break;
            
        }
        return len;
    }
};