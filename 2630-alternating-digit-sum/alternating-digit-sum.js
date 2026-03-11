/**
 * @param {number} n
 * @return {number}
 */
var alternateDigitSum = function(n) {
    let str = String(n);
    let sum = 0;

    for(let i = 0; i<str.length; i++){
        if(i%2 !== 0){
            sum = sum + Number(-str[i]);
        }
        else{
            sum = sum + Number(str[i]);
        }
    }

    return sum
};