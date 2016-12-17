// Problem from leetcode.com

// There are n bulbs that are initially off. You first turn on all the bulbs.
// Then, you turn off every second bulb. On the third round, you toggle every third bulb
// (turning on if it's off or turning off if it's on).
// For the ith round, you toggle every i bulb.
// For the nth round, you only toggle the last bulb.
//
// Find how many bulbs are on after n rounds.
//
// Example:
//
// Given n = 3.
//
// At first, the three bulbs are [off, off, off].
// After first round, the three bulbs are [on, on, on].
// After second round, the three bulbs are [on, off, on].
// After third round, the three bulbs are [on, off, off].
//
// So you should return 1, because there is only one bulb is on.

public class Solution {

    /**
    *   Naive approach 1:
    *
    *   Just follow the instructions! Create an array representing
    *   the bulbs, and iterate n times toggling the bulbs.
    *   The bulbs will probably break before you finish, tho.
    *
    *   This is highly inefficient, we must be able to do something
    *   better.
    */
    public int bulbSwitchNaive1(int n) {

        boolean []bulbs = new boolean[n]; // true is ON, false is OFF

        for( int i = 0; i < n; ++i ) {
            for( int j = i; j < n; j += i+1 ) {
                bulbs[j] = bulbs[j] ? false : true;
            }
        }

        int on = 0;
        for( int i = 0; i < n; ++i ) if( bulbs[i] ) ++on;

        return on;
    }

    /**
    *   Naive approach 2:
    *
    *   We don't want to iterate that huge amount of times over the array.
    *   Instead, we want to determine the final state of the bulb directly.
    *
    *   We use math for this: combinatories. Bulb#i will be toggled as many
    *   times as different divisors it has. Divisors are the pair 1-self and any
    *   pair of powers of primes that generate the number i.
    *
    *   We can see this problem as every of these intermediate primes (excluding
    *   1) representing a different color for a ball and its maximum exponent representing
    *   the number of available balls for that color. Hence, the number of different
    *   combinations will be the number of different sets that we can form with the
    *   available balls.
    *   If this number of combinations is even, the bulb will be left off.
    *   Otherwise, add this bulb to the count of bulbs left on.
    *
    *   Example: For bulb 500 = 1 * 2^2 * 5^3, we assign white to 2 and black to 5.
    *   We thus have 2 white balls and 3 black balls. The different sets we can
    *   generate are:
    *   0W 0B
    *   1W 0B
    *   2W 0B
    *   0W 1B
    *   1W 1B
    *   2W 1B
    *   0W 2B
    *   1W 2B
    *   2W 2B
    *   0W 3B
    *   1W 3B
    *   2W 3B
    *   Which adds up to 12. as 12 is even, the bulb will be left off.
    *
    *   We do this with every bulb, and now it's not the bulbs but our timer what breaks.
    *   We are factorizing numbers, which is a NP (suspected to be NP-Complete) problem!
    *   There must be a better way, even though this looked smart at first.
    */
    public int bulbSwitchNaive2(int n) {

        // Special cases (fail fast)
        if( n == 0 ) return 0;
        if( n == 1 ) return 1;

        // Precompute the primes that we might need to save iterations
        // (Sieve of Eratosthenes, saving the primes in an array)
        boolean [] crossed = new boolean[n];
        ArrayList<Integer> primes = new ArrayList<Integer>();
        for( int i = 1; i < n; ++i ) {
            for( int j = i; j < n; j += i+1 ) {
                if( j == i ) {
                    if( crossed[j] ) break;
                    primes.add(j+1);
                    continue; //else
                }
                crossed[j] = true;
            }
        }

        // Determine, for each bulb, whether it is finally on or off
        int on = 1; // bulb 1 is always on, skip
        int combinations, number, partial, posVals;
        double log;

        for( int i = 2; i <= n; i++ ) {

            if( ! crossed[i-1] ) { continue; } // We know that bulbs on primes are always left off

            // Prepare iteration
            combinations = 1;
            partial = 1;

            for( int prime : primes ) {

                // There's no point in evaluating a prime if the number is not divisible by it
                if( i % prime != 0) continue;

                // Prepare loop, skipping the first iteration (already known to succeed)
                posVals = 2;
                number = i/prime;
                partial *= prime;

                while( (number % prime) == 0 ) {
                    ++posVals;          // Increment the exponent (add a ball of the same color)
                    partial *= prime;   // Add the new factor found to our list
                    number /= prime;    // Apply the reduction over the number
                }

                // Multiply the current number of combinations by the number of new sets
                // that the new ball color introduces
                combinations *= posVals;

                if( partial == i ) { break; } // Exit the loop when the number is factorized
            }
            if( combinations % 2 != 0 ) ++on;
        }
        return on;
    }

    /**
    *   Smart Approach
    *
    *   Effectively, we were very close to the smart approach.
    *
    *   If you have read Naive Approach 2, you would have realize that we were
    *   calculating the number of possible different divisors. However, divisors
    *   always come in pairs. For example, 12 is 1*12, 2*6, 3*4, 4*3, 6*2 and 12*1. As
    *   you can see, there is always an dual of a pair that counteracts it.
    *
    *   Let's now see the square numbers:
    *   4 = 1*4, 2*2, 2*2, 4*1
    *   9 = 1*9, 3*3, 3*3, 9*1
    *   16 = 1*16, 2*8, 4*4, 4*4, 8*2, 16*1
    *
    *   Square numbers generate identical duals, which are executed only once (as we only
    *   iterate once over the first element in the pair), and these break the parity of the
    *   former different sets of balls.
    *
    *   Hence, the result of this problem is just the number of square numbers contained in
    *   the set {0, ..., n}, i.e. the square root of n.
    */
    public int bulbSwitchSmart(int n) { return (int) Math.sqrt(n); }
}

public class Solution {


}
