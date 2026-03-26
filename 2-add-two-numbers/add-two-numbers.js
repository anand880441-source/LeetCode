/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var addTwoNumbers = function(l1, l2) {
    let arr1 = [], arr2 = [];
    while (l1) { arr1.push(l1.val); l1 = l1.next; }
    while (l2) { arr2.push(l2.val); l2 = l2.next; }

    let num1 = BigInt(arr1.reverse().join(""));
    let num2 = BigInt(arr2.reverse().join(""));

    let sumStr = (num1 + num2).toString();
    let resArr = sumStr.split("").reverse();

    let dummy = new ListNode(0);
    let current = dummy;
    for (let digit of resArr) {
        current.next = new ListNode(Number(digit));
        current = current.next;
    }

    return dummy.next;
};