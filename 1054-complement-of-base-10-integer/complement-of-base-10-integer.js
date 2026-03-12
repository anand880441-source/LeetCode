/**
 * @param {number} n
 * @return {number}
 */
var bitwiseComplement = function(n) {
    return parseInt((n.toString(2).split('').map(bit => bit === '1' ? '0' : '1').join('')) , 2);
};