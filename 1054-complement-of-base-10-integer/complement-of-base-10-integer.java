class Solution {
    public int bitwiseComplement(int n) {

        if (n == 0)
            return 1;

        String binary = Integer.toBinaryString(n);

        StringBuilder complement = new StringBuilder();

        for (char c : binary.toCharArray()) {

            if (c == '0')
                complement.append('1');
            else
                complement.append('0');
        }

        return Integer.parseInt(complement.toString(), 2);
    }
}