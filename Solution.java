
public class Solution {

    public boolean checkSubarraySum(int[] input, int target) {

        Set<Integer> previousPrefixSumModuloTarget = new HashSet<>();
        int previousSum = 0;
        int currentSum = 0;

        for (int value : input) {
            currentSum += value;
            if (previousPrefixSumModuloTarget.contains(currentSum % target)) {
                return true;
            }
            previousPrefixSumModuloTarget.add(previousSum % target);
            previousSum = currentSum;

        }
        return false;
    }
}
