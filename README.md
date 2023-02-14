# Credit card validation
Credit card number validation using Luhn's algorithm in C. Implemented all other basic built-in required functions except `printf()`, `fgets()`, and `strtoul()` by myself for improving skill and logic. Currently supports validation of Visa, American Express and majority of MasterCard credit cards. The program correctly validates majority of Visa, American Express and MasterCard test credit cards provided for testing on [PayPal Developer](https://developer.paypal.com/api/nvp-soap/payflow/integration-guide/test-transactions/#standard-test-cards) site.

Main logic and Luhn's algorithm is in `credit.c` file. All other implemented functions are in `digit.c` file and their declarations are in `digit.h` header file.

## Credit cards
American Express uses 15-digit numbers, MasterCard uses 16-digit numbers, and Visa uses 13- and 16-digit numbers. Credit card numbers actually have some structure to them. All American Express numbers start with 34 or 37; most MasterCard numbers start with 51, 52, 53, 54, or 55 (they also have some other potential starting numbers which I haven't considered in this program); and all Visa numbers start with 4. But credit card numbers also have a “checksum” built into them, a mathematical relationship between at least one number and others. That checksum enables computers (or humans who like math) to detect typos (e.g., transpositions), if not fraudulent numbers, without having to query a database, which can be slow. Of course, a dishonest mathematician could certainly craft a fake number that nonetheless respects the mathematical constraint, so a database lookup is still necessary for more rigorous checks.

## Luhn's Algorithm
Most cards use an algorithm invented by Hans Peter Luhn of IBM. According to Luhn’s algorithm, you can determine if a credit card number is (syntactically) valid as follows:
1. Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products’ digits together.
2. Add the sum to the sum of the digits that weren’t multiplied by 2.
3. If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid mathematically!

Let's try with a credit card number: 5427660064241339
1. Let's highlight every other digit, starting with the number’s second-to-last digit: <p> __5__ 4 __2__ 7 __6__ 6 __0__ 0 __6__ 4 __2__ 4 __1__ 3 __3__ 9 </p>
2. Multiply the highlighted digits by two: <p>5×2 + 2×2 + 6×2 + 0×2 + 6×2 + 2×2 + 1×2 + 3×2</p> <p>That gives us:</p> <p>10 + 4 + 12 + 0 + 12 + 4 + 2 + 6</p> <p>Now add the individual digits of the product if they are greater than 9: <p>(1 + 0) + 4 + (1 + 2) + 0 + (1 + 2) + 4 + 2 + 6 = 23</p>
3. Now add all the digits that weren't multiplied by two: <p>4 + 7 + 6 + 0 + 0 + 4 + 4 + 3 + 9 = 37</p>
4. Now add these both sums together: <p>37 + 23 = 60</p>
5. The last digit of this sum (60) is 0, so this card is mathematically legit!
6. This credit card number is `16-digit` long and it starts with `54` so it is a __MasterCard__!

