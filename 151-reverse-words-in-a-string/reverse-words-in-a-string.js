/**
 * @param {string} s
 * @return {string}
 */
var reverseWords = function(s) {
    s = s.trim();
    let str = s.split(' ');
    str = str.reverse();
    let res = "";
    for(let i of str){
        if(i !== ""){
        res+=i+" ";
        }
    }
    return res.trim();
};