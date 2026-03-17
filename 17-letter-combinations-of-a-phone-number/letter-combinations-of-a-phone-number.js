/**
 * @param {string} digits
 * @return {string[]}
 */
var letterCombinations = function(digits) {
    if (!digits) return [];
    
    const letters = {
        '2': 'abc', '3': 'def', '4': 'ghi', '5': 'jkl',
        '6': 'mno', '7': 'pqrs', '8': 'tuv', '9': 'wxyz'
    };
    
    return [...digits].reduce((result, digit) => {
        const chars = letters[digit];
        const newResult = [];
        
        for (const prefix of result) {
            for (const char of chars) {
                newResult.push(prefix + char);
            }
        }
        
        return newResult;
    }, ['']);
};