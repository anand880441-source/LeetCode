/**
 * @param {number} n
 * @return {string[]}
 */
var generateParenthesis = function(n) {
    const result = [];

    const backtrack = (current = 0, open = 0, close = 0) => {
        if (current.length === n * 2) {
            result.push(current);
            return;
        }
        
        if (open < n) {
            backtrack(current + '(', open + 1, close);
        }
        
        if (close < open) {
            backtrack(current + ')', open, close + 1);
        }
    };
    
    backtrack('', 0, 0);
    return result;
};