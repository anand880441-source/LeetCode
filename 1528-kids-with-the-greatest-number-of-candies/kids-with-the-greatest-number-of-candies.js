/**
 * @param {number[]} candies
 * @param {number} extraCandies
 * @return {boolean[]}
 */
var kidsWithCandies = function(candies, extraCandies) {
    let arr = [];
    let maxCandies = Math.max(...candies)

    for(let i = 0; i<candies.length; i++){
        if(candies[i] + extraCandies >= maxCandies){
            arr.push(true)
        }
        else{
            arr.push(false)
        }
    }
    return arr
};