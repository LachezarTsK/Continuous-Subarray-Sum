
/**
 * @param {number[]} input
 * @param {number} target
 * @return {boolean}
 */
var checkSubarraySum = function (input, target) {
    const previousPrefixSumModuloTarget = new Set();
    let previousSum = 0;
    let currentSum = 0;

    for (let value of input) {
        currentSum += value;
        if (previousPrefixSumModuloTarget.has(currentSum % target)) {
            return true;
        }
        previousPrefixSumModuloTarget.add(previousSum % target);
        previousSum = currentSum;

    }
    return false;
};
