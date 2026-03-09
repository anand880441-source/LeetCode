/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function(strs) {
    if(!strs || strs.length == 0){
        return "";
    }

    //step=1
    strs.sort();

    //step=2
    const first = strs[0];
    const last = strs[(strs.length) -1];

    //step=3
    let i = 0
    while(i<first.length && i< last.length && first[i] === last[i]){
        i++
    }

    // step=4

    return first.slice(0,i);
};