/**
 * @param {string} paragraph
 * @param {string[]} banned
 * @return {string}
 */
var mostCommonWord = function(paragraph, banned) {
    let arr = paragraph.toLowerCase().split(/\W+/); 
    let obj = {};

    for (let word of arr) {
        if (word === "" || banned.includes(word)) continue;

        obj[word] = (obj[word] || 0) + 1;
    }

    let maxCount = 0;
    let result = "";

    for (let word in obj) {
        if (obj[word] > maxCount) {
            maxCount = obj[word];
            result = word;
        }
    }
    return result;
};