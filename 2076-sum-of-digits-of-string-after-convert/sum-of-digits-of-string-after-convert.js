/**
 * @param {string} s
 * @param {number} k
 * @return {number}
 */
var getLucky = function(s, k) {
    let current = [...s].map(char => char.charCodeAt(0) - 96).join('');
    for (let i = 0; i < k; i++) {
        current = [...current].reduce((sum, digit) => sum + parseInt(digit, 10), 0).toString();
    }
    return parseInt(current, 10);
};