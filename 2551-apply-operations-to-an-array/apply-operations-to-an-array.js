/**
 * @param {number[]} nums
 * @return {number[]}
 */
var applyOperations = function(nums) {
    for (let i = 0; i < nums.length - 1; i++) {
        if (nums[i] === nums[i + 1]) {
            nums[i] *= 2;
            nums[i + 1] = 0;
        }
    }
    
    let nonZeros = nums.filter(n => n !== 0);
    let zeros = new Array(nums.length - nonZeros.length).fill(0);
    
    return [...nonZeros, ...zeros];

};