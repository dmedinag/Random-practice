// Self-explanatory! The classic problem of palindrome numbers, solved in JS

/**
 * @param {number} x
 * @return {boolean}
 */
var isPalindrome = function(x) {

    if (x<0) { return false; }

    // ----- Solution using powers of 10

    var digits = 0;
    var curlast;
    var cur1st

    // 1. Determine the number of digits
    while( x >= Math.pow(10, digits) ) { digits++; }

    // 2. Compute the last index before the middle of the word
    const ituntil = 0 | (digits/2);

    // 3. Check pairs of digits!
    for( i=0; i<ituntil; i++ ) {
        curlast = 0 | x % Math.pow(10, i+1) / Math.pow(10, i);
        cur1st = 0 | x % Math.pow(10,digits-i) / Math.pow(10,digits-1-i);
        if( curlast != cur1st ) return false;
    }
    return true;

    // ----- Solution using string conversion (more readable, but less efficient)

    // 1. Convert the number into a digit string
    const digitString = x.toString();

    // 2. Compute last index in the string
    const lastIndex = digitString.length - 1;

    // 3. Compute the last index before the middle of the word
    const iterateUntil = parseInt(digitString.length/2);

    // 4. Check pairs of digits!
    for( i=0; i<iterateUntil; ++i ) {
        if( digitString.charAt(i) != digitString.charAt(lastIndex-i) ) { return false; }
    }

    return true;
};
