public class Hash {

    /**
     * Hash method in jdk 7.
     */
    static final int hash7(Object k) {
        int h = 0;
        h ^= k.hashCode();
        h ^= (h >>> 20) ^ (h >>> 12);
        return h ^ (h >>> 7) ^ (h >>> 4);
    }

    /**
     * Hash method in jdk 8.
     */
    static final int hash8(Object key) {
        int h;
        return (key == null) ? 0 : (h = key.hashCode()) ^ (h >>> 16);
    }

    public static void main(String[] args) {
        int n = 16;
        int h7, h8;
        for (int i = 0; i < 32; i++) {
            h7 = hash7(i);
            h8 = hash8(i);
            System.out.printf("h7:%d, i7:%d; h8: %d, i8: %d\n", h7, h7&(n-1), h8, h8&(n-1));
        }
    }
}
